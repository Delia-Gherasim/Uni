using System.ComponentModel.DataAnnotations;

namespace lab1
{
    internal class Program
    {
        //6. Write a program to find the longest palindromic substring in a given string.
        //For example, in the string "babad", one possible longest palindromic substring is "bab"

        static void Main(string[] args)
        {
            Console.WriteLine("Write the string you wish to check ");
            string word = Console.ReadLine();
            string result = FindLongestPalindromicSubstring(word);

            Console.WriteLine("The longest palindromic substring is ");
            Console.WriteLine(result);
        }

        static string FindLongestPalindromicSubstring(string word)
        {
           
            int maxLength = 1;
            int start = 0;

            for (int i = 1; i < word.Length; i++)
            {
                if (word.Length % 2 == 1)
                {
                    int low = i - 1;
                    int high = i + 1;
                    while (low >= 0 && high < word.Length && word[low] == word[high])
                    {
                        if (high - low + 1 > maxLength)
                        {
                            start = low;
                            maxLength = high - low + 1;
                        }
                        low--;
                        high++;
                    }
                }
                else
                {
                    int low = i - 1;
                    int high = i;
                    while (low >= 0 && high < word.Length && word[low] == word[high])
                    {
                        if (high - low + 1 > maxLength)
                        {
                            start = low;
                            maxLength = high - low + 1;
                        }
                        low--;
                        high++;
                    }
                }
            }

            return word.Substring(start, maxLength);
        }
    }

}
