using System;

namespace rt
{
    class RayTracer
    {
        private Geometry[] geometries;
        private Light[] lights;

        public RayTracer(Geometry[] geometries, Light[] lights)
        {
            this.geometries = geometries;
            this.lights = lights;
        }

        private double ImageToViewPlane(int n, int imgSize, double viewPlaneSize)
        {
            return -n * viewPlaneSize / imgSize + viewPlaneSize / 2;
        }

        private Intersection FindFirstIntersection(Line ray, double minDist, double maxDist)
        {
            var intersection = Intersection.NONE;

            foreach (var geometry in geometries)
            {
                var intr = geometry.GetIntersection(ray, minDist, maxDist);

                if (!intr.Valid || !intr.Visible)
                    continue;
                else if (intr.T > 0 && (intersection == Intersection.NONE || intr.T < intersection.T))
                {
                    intersection = intr;
                }
            }

            return intersection;

        }

        private bool IsLit(Vector point, Light light)
        {
            double epsilon = 1e-4;
            Vector shadowRayOrigin = point + (light.Position - point).Normalize() * epsilon;
            Line ray = new Line(light.Position, shadowRayOrigin);
            var intersection = FindFirstIntersection(ray, epsilon, (light.Position - shadowRayOrigin).Length());
            return intersection.Valid;

        }


        public void Render(Camera camera, int width, int height, string filename)
        {
            var image = new Image(width, height);
            camera.Normalize();

            for (var i = 0; i < width; i++)
            {
                for (var j = 0; j < height; j++)
                {
                    var background = new Color(0.2, 0.2, 0.2, 1.0);
                    double x = ImageToViewPlane(i, width, camera.ViewPlaneWidth);
                    double y = ImageToViewPlane(j, height, camera.ViewPlaneHeight);

                    var viewRayDirection = camera.Position +
                        camera.Direction * camera.ViewPlaneDistance +
                        (camera.Up ^ camera.Direction) * x +
                        camera.Up * y;

                    Line line = new Line(camera.Position, viewRayDirection);

                    var intersection = FindFirstIntersection(line, camera.FrontPlaneDistance, camera.BackPlaneDistance);
                    if (intersection == null || intersection.Geometry == null)
                    {
                        image.SetPixel(i, j, background);
                        continue;
                    }

                    var material = intersection.Material;
                    if (material == null)
                    {
                        continue;
                    }

                    var geometry = intersection.Geometry;
                    if (geometry == null)
                    {
                        continue;
                    }

                    Vector S = new Vector(0, 0, 0);
                    var color = new Color();
                    if (geometry is Ellipsoid)
                    {
                        S = ((Ellipsoid)geometry).Center;
                    }
                    else if (geometry is Sphere)
                    {
                        S = ((Sphere)geometry).Center;
                    }
                    else if (geometry is RawCtMask)
                    {
                        //nuca n.are treaba cu umbrele cica
                        var walnutColor = intersection.Color;
                        image.SetPixel(i, j, walnutColor);
                        continue;
                    }

                    var normal = (intersection.Position - S).Normalize();
                    

                    foreach (var light in lights)
                    {
                        var lightColor = material.Ambient * light.Ambient;

                        if (IsLit(intersection.Position, light))
                        {
                            var t = (light.Position - intersection.Position).Normalize();
                            double nt = normal * t;

                            if (nt > 0)
                            {
                                lightColor += material.Diffuse * light.Diffuse * light.Intensity * nt;
                            }

                            var e = (camera.Position - intersection.Position).Normalize();
                            var r = normal * (nt * 2) - t;

                            double ER = e * r;
                            if (ER > Double.Epsilon)
                            {
                                lightColor += material.Specular * light.Specular * Math.Pow(ER, material.Shininess);
                            }

                            lightColor *= light.Intensity;
                        }

                        color += lightColor;
                    }

                    image.SetPixel(i, j, color);
                }
            }

            image.Store(filename);
        }

    }
}


