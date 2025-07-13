#include <stdio.h>
void sort(int arr[], int n)
{
        int i, j, aux;
        for (i=0; i<n-1; i++)
                for (j=i+1; j<n; j++)
                        if (*(arr+i)>*(arr+j))
                                {
                                        aux=*(arr+j);
                                        *(arr+j)=*(arr+i);
                                        *(arr+i)=aux;
                                }
}
void merge(int a1[], int n, int m, int a2[], int a3[])
{
        int i, j, x=0;
        for (i=0; i<n; i++)
                {
                        *(a3+x)=*(a1+i);
                        x++;
                }
        for (j=0; j<m; j++)
                {
                        *(a3+x)=*(a2+j);
                        x++;
                }
}
int main()
{
        int a1[10], a2[10], a3[20], n, m, i, j;
        printf ("number of elements for the first array");
        scanf ("%d",&n);
        for (i=0; i<n; i++)
        {
                printf ("element: ");
                scanf ("%d", &a1[i]);
        }
	printf ("number of elements for the second array");
        scanf ("%d", &m);
        for (i=0; i<m; i++)
        {
                printf("element ");
                scanf ("%d", &a2[i]);
        }
        sort(a1, n);
        sort(a2, m);
        merge(a1, n, m, a2, a3);
        printf ("new array");
        printf ("\n");
        for (i=0; i<n+m; i++)
                printf("% -1d", a3[i]);
        return 0;
}