using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

namespace assignment1
{
    class Program
    {
        private const int nrOfThreads = 100;
        private static Random random = new Random();
        private static List<int> primaryValues = new List<int>();
        private static List<int> secondaryValues = new List<int>();
        private static object primaryLock = new object();
        //private static object secondaryLock = new object();
        private static List<object> secondaryLocks = new List<object>();

        static void ReadPrimary(object obj)
        {
            int i = (int)obj;
            Console.WriteLine("Primary Thread " + i + " requesting lock");

            lock (primaryLock)
            {
                Console.WriteLine("Primary Thread " + i + " inside");
                // Console.Write("Input a number: ");
                int newValue = random.Next(1, 100);
                Console.WriteLine("New Value: "+newValue);
                if (i >= primaryValues.Count)
                {
                    primaryValues.Add(newValue);
                }
                else
                {
                    int diff = newValue - primaryValues[i];
                    primaryValues[i] = newValue;

                    UpdateSecondary(i, diff);
                }
                // if (int.TryParse())
                //{
                //    if (i >= primaryValues.Count)
                //    {
                //        primaryValues.Add(newValue);
                //    }
                //    else
                //    {
                //        int diff = newValue - primaryValues[i];
                //        primaryValues[i] = newValue;

                //        UpdateSecondary(i, diff);
                //    }
                //}
                //else
                //{
                //    Console.WriteLine("Invalid input");
                //}
                Console.WriteLine("Primary Thread " + i + " releasing lock");
            }
        }

        static void UpdateSecondary(int i, int diff)
        {
           // lock (secondaryLock[i-1])
            //{
                if (i > 0 && (i - 1) < secondaryValues.Count)
                {
                    lock (secondaryLocks[i - 1])
                    {
                        secondaryValues[i - 1] += diff;
                    }
                }

                if (i < secondaryValues.Count)
                {
                lock (secondaryLocks[i])
                {
                    secondaryValues[i] += diff;
                }
                }
           // }
        }

        static void ComputeSecondary(object obj)
        {
            int i = (int)obj;
            Console.WriteLine("Secondary Thread " + i + " requesting lock");
            if (i > 0 && i < primaryValues.Count && i<secondaryValues.Count)
            {
                lock (primaryLock)
                {
                    lock (secondaryLocks[i - 1])  
                    {
                        secondaryValues.Add(primaryValues[i - 1] + primaryValues[i]);
                        secondaryLocks.Add(new object());  
                    }
                }
            }
            Console.WriteLine("Secondary Thread " + i + " releasing lock");
            
        }

        static void ConsistencyCheck()
        {
            lock (primaryLock)
            {
                
                    for (int i = 0; i < secondaryValues.Count; i++)
                    {
                        if (i < primaryValues.Count - 1)
                        {
                        lock (secondaryLocks[i])
                        {
                            int expected = primaryValues[i] + primaryValues[i + 1];
                            if (secondaryValues[i] != expected)
                            {
                                Console.WriteLine($"\n\nConsistency check failed at secondary {i}: expected {expected}, found {secondaryValues[i]}");
                                return;
                            }
                        }
                        }
                        else
                        {
                            Console.WriteLine($"\n\nConsistency check failed due to missing primary value for secondary {i}");
                            return;
                        }
                    }
                
            }
            Console.WriteLine("\n\nPassed consistency check");
        }

        static void Main(string[] args)
        {
            List<Thread> threads = new List<Thread>();
            int iterations = 100;

            for (int i = 0; i < nrOfThreads; i++)
            {
                int index = i;
                Thread primaryThread = new Thread(ReadPrimary);
                threads.Add(primaryThread);
                primaryThread.Start(index);
                primaryThread.Join();
            }

            for (int i = 1; i < nrOfThreads; i++)
            {
                int index = i;
                Thread secondaryThread = new Thread(ComputeSecondary);
                threads.Add(secondaryThread);
                secondaryThread.Start(index);
                secondaryThread.Join();
            }

            ConsistencyCheck();

            
            while (iterations > 1)
            {
                int rand1 = random.Next(0, nrOfThreads);
                int rand2 = random.Next(0, nrOfThreads);
                for (int i = rand1; i < rand2; i++)
                {
                    ReadPrimary(i);
                }

                ConsistencyCheck();
            
                iterations--;
            }

            foreach (var thread in threads)
            {
                thread.Join();
            }

            ConsistencyCheck();

            Console.ReadKey();
        }
    }
}
