using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Xml;

//Create two threads, a producer and a consumer, with the producer feeding the consumer.

//Requirement: Compute the scalar product of two vectors.

//Create two threads. The first thread (producer) will compute the products of pairs of elements - one from each vector - and will feed the second thread.
//The second thread (consumer) will sum up the products computed by the first one.
//The two threads will behind synchronized with a condition variable and a mutex. 
//The consumer will be cleared to use each product as soon as it is computed by the producer thread.
namespace a2
{
    internal class Program
    {
        private static readonly object lockObj = new object();
        private static int[] vector1 = new int[numberOfVar];
        private static int[] vector2 = new int[numberOfVar];
        private static int result = 0;
        private static int currentProduct = 0;
        private static bool productReady = false;
        private const int numberOfVar = 5;
        private static Random random = new Random();

        static void ComputeProduct()
        {
            for (int i = 0; i < numberOfVar; i++)
            {
                int product = vector1[i] * vector2[i];

                lock (lockObj)
                {
                    while (productReady) 
                        Monitor.Wait(lockObj); 

                    currentProduct = product;
                    productReady = true;
                    Monitor.Pulse(lockObj);
                }
            }
            lock (lockObj)
            {
                currentProduct = -1;
                productReady = true;
                Monitor.Pulse(lockObj);
            }
        }

        static void ComputeSum()
        {
            while (true)
            {
                lock (lockObj)
                {
                    while (!productReady) 
                        Monitor.Wait(lockObj);

                    if (currentProduct == -1) 
                        break;

                    result += currentProduct;
                    productReady = false;
                    Monitor.Pulse(lockObj);
                }
            }
        }

        static void Main(string[] args)
        {
            for (int i = 0; i < numberOfVar; i++)
            {
                vector1[i] = random.Next(0, 10);
                vector2[i] = random.Next(0, 10);
            }
            Console.WriteLine("The first vector is: ");
            for (int i = 0; i < numberOfVar; i++)
            {
                Console.Write(vector1[i] + " ");
            }
            Console.WriteLine("\n The second vector is: ");
            for (int i = 0; i < numberOfVar; i++)
            {
                Console.Write(vector2[i] + " ");
            }

            Thread producer = new Thread(ComputeProduct);
            Thread consumer = new Thread(ComputeSum);

            producer.Start();
            consumer.Start();

            producer.Join();
            consumer.Join();

            Console.WriteLine("\n The scalar product is: " + result);
            Console.ReadKey();
        }
    }
}

