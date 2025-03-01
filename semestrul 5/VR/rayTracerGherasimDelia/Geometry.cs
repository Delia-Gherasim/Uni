namespace rt
{
    public abstract class Geometry
    {
        //extended by elipsoid
        public Color Color { get; set; }
        public Material Material { get; set; }

        public Geometry(Material material, Color color) {
            Material = material;
            Color = color;
        }

        public Geometry(Color color)
        {
            Material = Material.FromColor(color);
            Color = color;
        }

        public abstract Intersection GetIntersection(Line line, double minDist, double maxDist);
        //returneaza un obiect Intersection sa aflii daca obiectul intersecteaza o linie
    }
}