using System;


namespace rt
{
    public class Ellipsoid : Geometry
    {
        public Vector Center { get; }
        private Vector SemiAxesLength { get; }
        private double Radius { get; }
        
        public Ellipsoid(Vector center, Vector semiAxesLength, double radius, Material material, Color color) : base(material, color)
        {
            Center = center;
            SemiAxesLength = semiAxesLength;
            Radius = radius;
        }

        public Ellipsoid(Vector center, Vector semiAxesLength, double radius, Color color) : base(color)
        {
            Center = center;
            SemiAxesLength = semiAxesLength;
            Radius = radius;
        }

        public override Intersection GetIntersection(Line line, double minDist, double maxDist)
        {
            if (line == null)
                return Intersection.NONE;

            double A = (line.Dx.X * line.Dx.X) / (SemiAxesLength.X * SemiAxesLength.X) +
                       (line.Dx.Y * line.Dx.Y) / (SemiAxesLength.Y * SemiAxesLength.Y) +
                       (line.Dx.Z * line.Dx.Z) / (SemiAxesLength.Z * SemiAxesLength.Z);

            double B = 2 * (
                (line.Dx.X * (line.X0.X - Center.X)) / (SemiAxesLength.X * SemiAxesLength.X) +
                (line.Dx.Y * (line.X0.Y - Center.Y)) / (SemiAxesLength.Y * SemiAxesLength.Y) +
                (line.Dx.Z * (line.X0.Z - Center.Z)) / (SemiAxesLength.Z * SemiAxesLength.Z)
            );

            double C = ((line.X0.X - Center.X) * (line.X0.X - Center.X)) / (SemiAxesLength.X * SemiAxesLength.X) +
                       ((line.X0.Y - Center.Y) * (line.X0.Y - Center.Y)) / (SemiAxesLength.Y * SemiAxesLength.Y) +
                       ((line.X0.Z - Center.Z) * (line.X0.Z - Center.Z)) / (SemiAxesLength.Z * SemiAxesLength.Z) -
                       Radius * Radius;

            double discriminant = B * B - 4 * A * C;

            if (discriminant < 0)
            {
                return Intersection.NONE;
            }

            double sqrtDiscriminant = Math.Sqrt(discriminant);
            double t1 = (-B - sqrtDiscriminant) / (2 * A);
            double t2 = (-B + sqrtDiscriminant) / (2 * A);

            double t = -1;

            if (t1 < t2)
            {
                if (t1 >= minDist && t1 <= maxDist)
                {
                    t = t1;
                }
            }
            else
            {
                if (t2 >= minDist && t2 <= maxDist && (t == -1 || t2 < t))
                {
                    t = t2;
                }
            }

            if (t == -1)
            {
                return Intersection.NONE;
            }

            Vector intersectionPoint = line.X0 + line.Dx * t;

            Vector normal = new Vector(
                (intersectionPoint.X - Center.X) / (SemiAxesLength.X * SemiAxesLength.X),
                (intersectionPoint.Y - Center.Y) / (SemiAxesLength.Y * SemiAxesLength.Y),
                (intersectionPoint.Z - Center.Z) / (SemiAxesLength.Z * SemiAxesLength.Z)
            ).Normalize();

            return new Intersection(true, true, this, line, t, intersectionPoint, this.Material, this.Color);
        }






    }
}
