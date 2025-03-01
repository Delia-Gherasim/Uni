using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;

class Program
{
    static object lockObject = new object();
    static bool cycleFound = false;
    static List<int> resultCycle = null;

   static void FindHamiltonianCycle(Dictionary<int, List<int>> graph, int startVertex)
    {
        var visited = new HashSet<int> { startVertex };
        var path = new List<int> { startVertex };

        ParallelSearch(graph, startVertex, visited, path, graph.Count);
    }

    static void ParallelSearch(Dictionary<int, List<int>> graph, int currentVertex, HashSet<int> visited, List<int> path, int totalVertices)
    {
        if (cycleFound) return; 
        if (visited.Count == totalVertices)
        {
            if (graph[currentVertex].Contains(path[0]))
            {
                lock (lockObject)
                {
                    if (!cycleFound)
                    {
                        cycleFound = true;
                        resultCycle = new List<int>(path) { path[0] }; 
                    }
                }
            }
            return;
        }

        var neighbors = graph[currentVertex].Where(n => !visited.Contains(n)).ToList();
        Parallel.ForEach(neighbors, neighbor =>
        {
            if (cycleFound) return;

            var newVisited = new HashSet<int>(visited) { neighbor };
            var newPath = new List<int>(path) { neighbor };

            ParallelSearch(graph, neighbor, newVisited, newPath, totalVertices);
        });
    }

    static void Main(string[] args)
    {
        var graph = new Dictionary<int, List<int>>()//vertex, neighbors
        {
            { 0, new List<int> { 1, 2 } },
            { 1, new List<int> { 2, 3 } },
            { 2, new List<int> { 3 } },
            { 3, new List<int> { 0 } }
        };

        var graph2 = new Dictionary<int, List<int>>()
        {
            { 0, new List<int> { 1 } },
            { 1, new List<int> { 2, 3 } },
            { 2, new List<int> { 4 } },
            { 3, new List<int> { } },
            { 4, new List<int> {} }
        };

        int startVertex = 0;
        FindHamiltonianCycle(graph, startVertex);

        if (resultCycle != null)
        {
            Console.WriteLine("Hamiltonian Cycle Found: " + string.Join(" -> ", resultCycle));
        }
        else
        {
            Console.WriteLine("No Hamiltonian Cycle Found.");
        }
    }
}
