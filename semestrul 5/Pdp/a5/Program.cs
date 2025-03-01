using System;
using System.Diagnostics;
using System.Linq;
using System.Threading;

class Program
{
    public static int[] MultiplyBasic(int[] poly1, int[] poly2)
    {
        int n = poly1.Length;
        int m = poly2.Length;
        int[] result = new int[n + m - 1];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                result[i + j] += poly1[i] * poly2[j];
            }
        }
        return result;
    }

    public static int[] MultiplyBasicParallel(int[] poly1, int[] poly2)
    {
        int n = poly1.Length;
        int m = poly2.Length;
        int[] result = new int[n + m - 1];
        int threadCount = 8;
        Thread[] threads = new Thread[threadCount];

        for (int t = 0; t < threadCount; t++)
        {
            int start = t * n / threadCount;
            int end = (t + 1) * n / threadCount;

            threads[t] = new Thread(() =>
            {
                for (int i = start; i < end; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        Interlocked.Add(ref result[i + j], poly1[i] * poly2[j]);
                      
                    }
                }
            });

            threads[t].Start();
        }

        foreach (var thread in threads)
        {
            thread.Join(); 
        }

        return result;
    }

    public static int[] Karatsuba(int[] poly1, int[] poly2)
    {
        int n = Math.Max(poly1.Length, poly2.Length);
        if (n == 1)
        {
            return new int[] { poly1[0] * poly2[0] };
        }

        int mid = n / 2;

        int[] low1 = poly1.Take(mid).ToArray();
        int[] high1 = poly1.Skip(mid).ToArray();
        int[] low2 = poly2.Take(mid).ToArray();
        int[] high2 = poly2.Skip(mid).ToArray();

        int[] z0 = Karatsuba(low1, low2);
        int[] z1 = Karatsuba(AddPolynomials(low1, high1), AddPolynomials(low2, high2));
        int[] z2 = Karatsuba(high1, high2);

        return CombinePolynomials(z0, z1, z2, mid);
    }

    private static int[] AddPolynomials(int[] poly1, int[] poly2)
    {
        int n = Math.Max(poly1.Length, poly2.Length);
        int[] result = new int[n];
        for (int i = 0; i < n; i++)
        {
            int val1 = i < poly1.Length ? poly1[i] : 0;
            int val2 = i < poly2.Length ? poly2[i] : 0;
            result[i] = val1 + val2;
        }
        return result;
    }

    private static int[] CombinePolynomials(int[] z0, int[] z1, int[] z2, int mid)
    {
        int n = z0.Length + z2.Length + mid;
        int[] result = new int[n];

        for (int i = 0; i < z0.Length; i++)
            result[i] += z0[i];
        for (int i = 0; i < z1.Length; i++)
            result[i + mid] += z1[i] - (i < z0.Length ? z0[i] : 0) - (i < z2.Length ? z2[i] : 0);
        for (int i = 0; i < z2.Length; i++)
            result[i + 2 * mid] += z2[i];

        return result;
    }

    public static int[] KaratsubaParallel(int[] poly1, int[] poly2)
    {
        int n = Math.Max(poly1.Length, poly2.Length);
        if (n == 1)
        {
            return new int[] { poly1[0] * poly2[0] };
        }

        int mid = n / 2;

        int[] low1 = poly1.Take(mid).ToArray();
        int[] high1 = poly1.Skip(mid).ToArray();
        int[] low2 = poly2.Take(mid).ToArray();
        int[] high2 = poly2.Skip(mid).ToArray();

        int[] z0 = null, z1 = null, z2 = null;

        Thread threadZ0 = new Thread(() => z0 = KaratsubaParallel(low1, low2));
        Thread threadZ1 = new Thread(() => z1 = KaratsubaParallel(AddPolynomials(low1, high1), AddPolynomials(low2, high2)));
        Thread threadZ2 = new Thread(() => z2 = KaratsubaParallel(high1, high2));

        threadZ0.Start();
        threadZ1.Start();
        threadZ2.Start();

        threadZ0.Join();
        threadZ1.Join();
        threadZ2.Join();

        return CombinePolynomials(z0, z1, z2, mid);
    }

    static void Main()
    {
        int nr = 1000;
        int[] poly1 = new int[nr];
        int[] poly2 = new int[nr];

        Random rand = new Random();
        for (int i = 0; i < nr; i++)
        {
            poly1[i] = rand.Next(1, 10);
            poly2[i] = rand.Next(1, 10);
        }

        var stopwatch = Stopwatch.StartNew();
        MultiplyBasic(poly1, poly2);
        stopwatch.Stop();
        Console.WriteLine($"Regular: {stopwatch.ElapsedMilliseconds}ms");

        stopwatch.Restart();
        MultiplyBasicParallel(poly1, poly2);
        stopwatch.Stop();
        Console.WriteLine($"Regular with threads: {stopwatch.ElapsedMilliseconds}ms");

        stopwatch.Restart();
        Karatsuba(poly1, poly2);
        stopwatch.Stop();
        Console.WriteLine($"Karatsuba: {stopwatch.ElapsedMilliseconds}ms");

        stopwatch.Restart();
       // KaratsubaParallel(poly1, poly2);
        stopwatch.Stop();
        Console.WriteLine($"Karatsuba with Threads: {stopwatch.ElapsedMilliseconds}ms");
    }
}
