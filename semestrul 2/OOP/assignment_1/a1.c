/*
13
a. Determine the first (and only) 8 natural numbers (x1, x2,  …,  x8) greater than 2 with the following property: 
all the natural numbers smaller than xi and that are relatively prime with xi (except for the number 1) are prime, i =1,2, …, n.
b. Given a vector of numbers, find the longest continuous subsequence such that any consecutive elements contain the same digits.
*/
#include <stdio.h>

int vector[100];

int numberisprime(int numbertocheck)
/*function checks if a number is prime and returns 1 if it is, otherwise it returns 0
:param numbertocheck: integer 
:return 1: number is prime
:return 0: number is NOt prime
*/
{
    if (numbertocheck==1 || numbertocheck==2)
        return 1;
    for (int i=2; i*i<=numbertocheck; i++)
        if (numbertocheck %i!=0)
            return 0;
    return 1;

}

int are_relatively_prime(int firstnumber, int secondnumber)
/*function checks if 2 integers are relatively prime and returns 1 if they are, 0 otherwise
:param firstnumber: integer
:param secondnumber: integer
:return 1: firstnumber and secondnumber are relatively prime
:return 0: firstnumber and secondnumber are not relatively prime
*/
{
    while (firstnumber != secondnumber)
    {
        if (firstnumber > secondnumber)
            firstnumber = firstnumber - secondnumber;
        else
            secondnumber = secondnumber - firstnumber;
    }
    if (firstnumber == 1)
        return 1;
    return 0;
}

void determine_8_numbers_relatively_prime_with_any_smaller_number()
//function determines and prints the first 8 natural numbers greater then 2 that are relatively prime with any number smaller than them

{
    int number=3, arrayofvalidnumbers[8], indexofarray=0;
    while (indexofarray<8)
    {
        int isvalid=1;
        for (int i=1; i<number; i++)
        {   
            if (numberisprime(i) && are_relatively_prime(i, number)==0)
                isvalid=0;
        }
        if (isvalid==1)
            {
                arrayofvalidnumbers[indexofarray]=number;
                indexofarray++;
            }
        number++;
    }
    for (int i=0; i<8; i++)
    {
        printf("%d", arrayofvalidnumbers[i]);
        printf("%c ");
    }
    printf("\n");
    
}

int containsamedigits(int firstnumber, int secondnumber)
//function checks if 2 int numbers contain the same digits and returns 1 if yes
{
    while (firstnumber>0)
    {
        int digittofind=firstnumber%10, ok=0;
        firstnumber=firstnumber/10;
        int copysecondnumber=secondnumber;
        while (copysecondnumber>0)
        {
            if (copysecondnumber%10==digittofind)
                ok=1;
            copysecondnumber=copysecondnumber/10;
        }
        if (ok==0)
            return 0;

    }
    return 1;
}

void find_longest_subsequence_with_elements_having_the_same_digits(int vector[], int numberofelements)
//function finds longest continuous subsequence such that any consecutive elements contain the same digits and prints it
{
    int maximlenght=0, currentlenght=0, startingindex=0, endindex=0, savestartindex, saveendindex;
    for (int i=0; i<numberofelements; i++)
        {   
            if (i==0)
                currentlenght++;
            else
            {
                if (containsamedigits(vector[i], vector[i-1])==1)
                {
                    currentlenght++;
                    endindex++;
                }
                else
                    {
                        startingindex=i;
                        endindex=i;
                        currentlenght=1;
                    }
                if (currentlenght>maximlenght)
                    {
                        maximlenght=currentlenght;
                        savestartindex=startingindex;
                        saveendindex=endindex;
                    }
            }
        }
    
    if (numberofelements<1)
        printf("%s There is no such sequence");
    else
        if (numberofelements==1)
            printf("%d", vector[0]);
        else
            if (maximlenght==1)
                printf("%d", vector[saveendindex]);
            else
            {
                printf("%s The longest continuous subsequence is:");
                if (maximlenght==0)
                    printf("%d", vector[0]);
                else
                    for (int i=savestartindex; i<=saveendindex; i++)
                        {
                            printf("%d", vector[i]);
                            printf(" ");
                        }
            }
    printf("%s \n");
}

int main()
{
    int option;
    printf("%s Here are your options, \n");
    printf("%s 1. Determine the first (and only) 8 natural numbers greater than 2 with the property \n");
    printf("%s 2. Longest continuous subsequence such that any consecutive elements contain the same digits \n");
    printf("%s 3. Exit \n");
    printf("%s Your option is? ");
    scanf("%d", &option);

    while (option!=3)
    {
        if (option==1)
            determine_8_numbers_relatively_prime_with_any_smaller_number();
        if (option==2)
        {
            //int vector[100], 
            int numberofelements;
            printf("%s How many numbers are in the vector?");
            scanf("%d", &numberofelements);
            for (int i=0; i<numberofelements; i++)
            {
                printf("%s Element: ");
                scanf("%d", &vector[i]);
            }
            find_longest_subsequence_with_elements_having_the_same_digits (vector, numberofelements);
        }
        printf("%s Your option is? ");
        scanf("%d", &option);
    }

    return 0;
}