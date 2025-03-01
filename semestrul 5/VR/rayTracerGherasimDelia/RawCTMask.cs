using System;
using System.IO;
using System.Text.RegularExpressions;

namespace rt;

public class RawCtMask: Geometry
{
    private readonly Vector _position;
    private readonly double _scale;
    private readonly ColorMap _colorMap;
    private readonly byte[] _data;

    private readonly int[] _resolution = new int[3];
    private readonly double[] _thickness = new double[3];
    private readonly Vector _v0;
    private readonly Vector _v1;

    public RawCtMask(string datFile, string rawFile, Vector position, double scale, ColorMap colorMap) : base(Color.NONE)
    {
        _position = position;
        _scale = scale;
        _colorMap = colorMap;

        var lines = File.ReadLines(datFile);
        foreach (var line in lines)
        {
            var kv = Regex.Replace(line, "[:\\t ]+", ":").Split(":");
            if (kv[0] == "Resolution")
            {
                _resolution[0] = Convert.ToInt32(kv[1]);
                _resolution[1] = Convert.ToInt32(kv[2]);
                _resolution[2] = Convert.ToInt32(kv[3]);
            } else if (kv[0] == "SliceThickness")
            {
                _thickness[0] = Convert.ToDouble(kv[1]);
                _thickness[1] = Convert.ToDouble(kv[2]);
                _thickness[2] = Convert.ToDouble(kv[3]);
            }
        }

        _v0 = position;
        _v1 = position + new Vector(_resolution[0]*_thickness[0]*scale, _resolution[1]*_thickness[1]*scale, _resolution[2]*_thickness[2]*scale);

        var len = _resolution[0] * _resolution[1] * _resolution[2];
        _data = new byte[len];
        using FileStream f = new FileStream(rawFile, FileMode.Open, FileAccess.Read);
        if (f.Read(_data, 0, len) != len)
        {
            throw new InvalidDataException($"Failed to read the {len}-byte raw data");
        }
    }
    
    private ushort Value(int x, int y, int z)
    {
        if (x < 0 || y < 0 || z < 0 || x >= _resolution[0] || y >= _resolution[1] || z >= _resolution[2])
        {
            return 0;
        }

        return _data[z * _resolution[1] * _resolution[0] + y * _resolution[0] + x];
    }

    public override Intersection GetIntersection(Line line, double minDist, double maxDist)
    {
        //mx + ny + pz = q
        //    a t +b = x
        //    c t +d = y
        //    a t +f + z

        //0 = 0 no sol
        //1 = 0 infinity of sol
        //t = sol

        double tMin = (_v0.X - line.X0.X) / line.Dx.X;
        double tMax = (_v1.X - line.X0.X) / line.Dx.X;
        if (tMin > tMax)
            (tMin, tMax) = (tMax, tMin);
        double tyMin = (_v0.Y - line.X0.Y) / line.Dx.Y;
        double tyMax = (_v1.Y - line.X0.Y) / line.Dx.Y;
        if (tyMin > tyMax)
            (tyMin, tyMax) = (tyMax, tyMin);

        if ((tMin > tyMax) || (tyMin > tMax))
            return Intersection.NONE;
        if (tyMin > tMin)
            tMin = tyMin;
        if (tyMax < tMax)
            tMax = tyMax;

        double tzMin = (_v0.Z - line.X0.Z) / line.Dx.Z;
        double tzMax = (_v1.Z - line.X0.Z) / line.Dx.Z;
        if (tzMin > tzMax)
            (tzMin, tzMax) = (tzMax, tzMin);

        if ((tMin > tzMax) || (tzMin > tMax))
            return Intersection.NONE;

        tMin = Math.Max(tMin, minDist);
        tMax = Math.Min(tMax, maxDist);
        if (tMin > tMax)
            return Intersection.NONE;

        Color accumulatedColor = Color.NONE;
        double accumulatedAlpha = 0.0;
        double stepSize = _scale;
        double currentT = tMin;
        double firstNotTransparent = -1.0;
        bool foundEntry = false;

        while (accumulatedAlpha < 1.0 && currentT <= tMax)
        {
            Vector currentPos = line.CoordinateToPosition(currentT);
            Color currentColor = GetColor(currentPos);
            //c0*a0 
            //c01 = c0*a0 + c1 * a1 * (1- a0)
            //a01 = a0 + a1 * (1-a0)

            if (currentColor.Alpha > 0)
            {
                if (!foundEntry)
                {
                    accumulatedColor = currentColor;
                    accumulatedAlpha = currentColor.Alpha;
                    foundEntry = true;
                    firstNotTransparent = currentT;
                }
                else
                {
                    double remainingAlpha = 1.0 - accumulatedAlpha;
                    accumulatedColor += currentColor * currentColor.Alpha * remainingAlpha;
                    accumulatedAlpha += currentColor.Alpha * remainingAlpha;
                }
            }

            if (accumulatedAlpha >= 1)
            {
                break;
            }

            currentT += stepSize;
        }

        if (!foundEntry || firstNotTransparent < minDist)
            return Intersection.NONE;

        accumulatedAlpha = Math.Min(accumulatedAlpha, 1.0);
        accumulatedColor.Alpha = accumulatedAlpha;

        Vector intersectionPoint = line.CoordinateToPosition(firstNotTransparent);
        Vector entryNormal = GetNormal(intersectionPoint);

        return new Intersection(
            valid: true,
            visible: true,
            geometry: this,
            line: line,
            t: firstNotTransparent,
            normal: entryNormal,
            material: Material.FromColor(accumulatedColor),
            color: accumulatedColor
        );
    }

    private int[] GetIndexes(Vector v)
    {
        return new []{
            (int)Math.Floor((v.X - _position.X) / _thickness[0] / _scale), 
            (int)Math.Floor((v.Y - _position.Y) / _thickness[1] / _scale),
            (int)Math.Floor((v.Z - _position.Z) / _thickness[2] / _scale)};
    }
    private Color GetColor(Vector v)
    {
        int[] idx = GetIndexes(v);
        ushort value = Value(idx[0], idx[1], idx[2]);
        return _colorMap.GetColor(value);
    }

    private Vector GetNormal(Vector v)
    {
        int[] idx = GetIndexes(v);
        double x0 = Value(idx[0] - 1, idx[1], idx[2]);
        double x1 = Value(idx[0] + 1, idx[1], idx[2]);
        double y0 = Value(idx[0], idx[1] - 1, idx[2]);
        double y1 = Value(idx[0], idx[1] + 1, idx[2]);
        double z0 = Value(idx[0], idx[1], idx[2] - 1);
        double z1 = Value(idx[0], idx[1], idx[2] + 1);

        return new Vector(x1 - x0, y1 - y0, z1 - z0).Normalize();
    }

}