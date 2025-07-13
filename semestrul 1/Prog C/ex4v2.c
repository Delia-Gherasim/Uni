#include <stdio.h>
int get_nr(int x,int y)
{
        return (x+y);
}
int main()
{
        int n;
        printf ("input n ");
        scanf("%d", &n);
        while ( (int)n!=n || n<0)
        {
                printf("invalid input");
                printf("\n");
                printf("input n");
                scanf("%d", &n);
        }
        if (n==1)
        {
        printf("1");
        }
        else
        {
                if (n==2)
                {
                        printf("1 1");
                }
                else
                {
                        int x, y, z;
                        x=1;
                        y=1;
                        while (n>1)
                        {
                                z=get_nr(x, y);
                                printf("%d",x);
                                printf(" ");
				x=y;
                                y=z;
                                n=n-1;
                        }
                        printf("%d",x);
                }
        }
        return 0;
}
