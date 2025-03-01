namespace rt
{
    public class Line
    {
        //adica ray-ul, line definita din 2 puncte
        public Vector X0 { get; set; }
        public Vector Dx { get; set; }

        public Line()
        {
            X0 = new Vector(0.0, 0.0, 0.0);
            Dx = new Vector(1.0, 0.0, 0.0);
        }

        public Line(Vector x0, Vector x1)
        {
            // schimb un punct intr - un direction vector
            X0 = new Vector(x0);
            Dx = new Vector(x1 - x0);
            Dx.Normalize();
        }

        public Vector CoordinateToPosition(double t)
        {
            return new Vector(Dx * t + X0);
        }
    }
}