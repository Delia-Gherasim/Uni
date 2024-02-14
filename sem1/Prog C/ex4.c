#include <stdio.h>
int main()
{
        int fibo[10000], n;
        fibo[0]=1;
        fibo[1]=1;
        printf("input n ");
        scanf("%d", &n);
        while (n<0||(int)n!=n)
        {
                printf("invalid input" );
                printf("\n");
                printf("input n ");
                scanf("%d", &n);
        }

        printf("fibonacci series: ");
        printf("\n");
        if (n==1)
        {
 printf("%d",fibo[0]);
        }
        else
        {
                if (n==2)
                {
                        printf("%d",fibo[0]);
                        printf(" ");
                        printf("%d ",fibo[1]);
                }
                else
                {
                        printf("%d",fibo[0]);
                        printf(" ");
                        printf("%d", fibo[1]);
                        int i;
                        for ( i=2; i<n; i=i+1)
                        {
                                fibo[i]=fibo[i-1]+fibo[i-2];
                                printf(" ");
                                printf("%d",fibo[i]);

                        }
                }
        }

        return 0;
}
