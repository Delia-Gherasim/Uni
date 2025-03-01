using System;
using System.Collections.Generic;
using System.Threading;

namespace MatrixMultiplicationParallel
{
    internal class Program
    {
        private static int[][] matrix1;
        private static int[][] matrix2;
        private static int[][] matrix3;
        private static int size = 500;
        private static int nrThreads = 5;
        private static CountdownEvent countdownEvent;

        //BY K ELEMENT
        private static void ComputeSectionByKthElements(int taskId)
        {
            int totalElements = size * size;
            int row, col;

            for (int index = taskId; index < totalElements; index += nrThreads)
            {
                row = index / size;
                col = index % size;      
                ComputeElement(row, col);
            }
        }

        private static void ComputeSectionByKthElements(object obj)
        {
            int taskId = (int)obj;
            int totalElements = size * size;
            int row, col;

            for (int index = taskId; index < totalElements; index += nrThreads)
            {
                row = index / size;
                col = index % size;
                ComputeElement(row, col);
            }

            countdownEvent.Signal();
        }

        private static void RunWithThreadsByKthElements()
        {
            var watch = System.Diagnostics.Stopwatch.StartNew();
            List<Thread> threads = new List<Thread>();

            for (int taskId = 0; taskId < nrThreads; taskId++)
            {
                int _taskId = taskId;
                Thread thread = new Thread(() => ComputeSectionByKthElements(_taskId));
                threads.Add(thread);
                thread.Start();
            }

            foreach (var thread in threads)
            {
                thread.Join();
            }

            watch.Stop();
            Console.WriteLine("Elapsed milliseconds : " + watch.ElapsedMilliseconds);
        }

        private static void RunWithThreadPoolByKthElements()
        {
            var watch = System.Diagnostics.Stopwatch.StartNew();
            countdownEvent = new CountdownEvent(nrThreads);

            for (int taskId = 0; taskId < nrThreads; taskId++)
            {
                ThreadPool.QueueUserWorkItem(ComputeSectionByKthElements, taskId);
            }

            countdownEvent.Wait();

            watch.Stop();
            Console.WriteLine("Elapsed milliseconds : " + watch.ElapsedMilliseconds);
        }


        private static void ComputeElement(int rowIdx, int colIdx)
        {
            int result = 0;
            for (int k = 0; k < size; k++)
            {
                result += matrix1[rowIdx][k] * matrix2[k][colIdx];
            }
            matrix3[rowIdx][colIdx] = result;
        }

        //BY ROW
        private static void ComputeSectionByRow(int startRow, int endRow)
        {
            for (int i = startRow; i <= endRow; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    ComputeElement(i, j);
                }
            }
        }

        private static void ComputeSectionByRow(object obj)
        {
            (int startRow, int endRow) = ((int, int))obj;

            for (int i = startRow; i <= endRow; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    ComputeElement(i, j);
                }
            }
            countdownEvent.Signal();
        }

        private static void RunWithThreadsByRow()
        {
            var watch = System.Diagnostics.Stopwatch.StartNew();
            List<Thread> threads = new List<Thread>();
            int rowsPerTask = size / nrThreads;
            for (int taskId = 0; taskId < nrThreads; taskId++)
            {
                int startRow = taskId * rowsPerTask;
                int endRow = (taskId == nrThreads - 1) ? size - 1 : startRow + rowsPerTask - 1;

                Thread thread = new Thread(() => ComputeSectionByRow(startRow, endRow));
                threads.Add(thread);
                thread.Start();
            }

            foreach (var thread in threads)
            {
                thread.Join();
            }

            watch.Stop();
            var elapsedMs = watch.ElapsedMilliseconds;
            Console.WriteLine("Elapsed miliseconds: " + elapsedMs.ToString());
        }

        private static void RunWithThreadPoolbyRow()
        {
            var watch = System.Diagnostics.Stopwatch.StartNew();

            countdownEvent = new CountdownEvent(nrThreads);
            int rowsPerTask = size / nrThreads;

            for (int taskId = 0; taskId < nrThreads; taskId++)
            {
                int startRow = taskId * rowsPerTask;
                int endRow = (taskId == nrThreads - 1) ? size - 1 : startRow + rowsPerTask - 1;

                ThreadPool.QueueUserWorkItem(ComputeSectionByRow, (startRow, endRow));
            }
            countdownEvent.Wait();

            watch.Stop();
            var elapsedMs = watch.ElapsedMilliseconds;
            Console.WriteLine("Elapsed miliseconds: " + elapsedMs.ToString());
        }

        //BY COLUMN        
        private static void ComputeSectionByColumn(int startCol, int endCol)
        {
            for (int j = startCol; j <= endCol; j++) 
            {
                for (int i = 0; i < size; i++)  
                {
                    ComputeElement(i, j);  
                }
            }
        }

        private static void ComputeSectionByColumn(object obj)
        {
            (int startCol, int endCol) = ((int, int))obj;

            for (int j = startCol; j <= endCol; j++)  
            {
                for (int i = 0; i < size; i++)  
                {
                    ComputeElement(i, j); 
                }
            }
            countdownEvent.Signal();
        }

        private static void RunWithThreadsByColumn()
        {
            var watch = System.Diagnostics.Stopwatch.StartNew();
            List<Thread> threads = new List<Thread>();
            int rowsPerTask = size / nrThreads;
            for (int taskId = 0; taskId < nrThreads; taskId++)
            {
                int startRow = taskId * rowsPerTask;
                int endRow = (taskId == nrThreads - 1) ? size - 1 : startRow + rowsPerTask - 1;

                Thread thread = new Thread(() => ComputeSectionByColumn(startRow, endRow));
                threads.Add(thread);
                thread.Start();
            }

            foreach (var thread in threads)
            {
                thread.Join();
            }

            watch.Stop();
            var elapsedMs = watch.ElapsedMilliseconds;
            Console.WriteLine("Elapsed miliseconds: " + elapsedMs.ToString());
        }

        private static void RunWithThreadPoolbyColumn()
        {
            var watch = System.Diagnostics.Stopwatch.StartNew();

            countdownEvent = new CountdownEvent(nrThreads); 
            int rowsPerTask = size / nrThreads;

            for (int taskId = 0; taskId < nrThreads; taskId++)
            {
                int startRow = taskId * rowsPerTask;
                int endRow = (taskId == nrThreads - 1) ? size - 1 : startRow + rowsPerTask - 1;

                ThreadPool.QueueUserWorkItem(ComputeSectionByColumn, (startRow, endRow));
            }
            countdownEvent.Wait();

            watch.Stop();
            var elapsedMs = watch.ElapsedMilliseconds;
            Console.WriteLine("Elapsed miliseconds: " + elapsedMs.ToString());
        }

        static void Main(string[] args)
        {
            Random random = new Random();
            matrix1 = new int[size][];
            matrix2 = new int[size][];
            matrix3 = new int[size][];

            for (int i = 0; i < size; i++)
            {
                matrix1[i] = new int[size];
                matrix2[i] = new int[size];
                matrix3[i] = new int[size];
                for (int j = 0; j < size; j++)
                {
                    matrix1[i][j] = random.Next(1, 10);
                    matrix2[i][j] = random.Next(1, 10);
                    matrix3[i][j] = 0;
                }
            }

            Console.WriteLine("\n Computing By Row");
            Console.WriteLine("\n Running with threads");
            RunWithThreadsByRow();
                       
            Console.WriteLine("\n Running with threadPool");
            RunWithThreadPoolbyRow();
           

            Console.WriteLine("\n Computing By Column");
            Console.WriteLine("\n Running with threads");
            RunWithThreadsByColumn();     
            
            Console.WriteLine("\n Running with threadPool");
            RunWithThreadPoolbyColumn();
           

            Console.WriteLine("\n Computing By K-th element");
            Console.WriteLine("\n Running with threads");
            RunWithThreadsByKthElements();
            
            Console.WriteLine("\n Running with threadPool");
            RunWithThreadPoolByKthElements();
           
        }
    }
}
