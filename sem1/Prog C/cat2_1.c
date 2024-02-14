#include <stdio.h>
#include <stdlib.h>
int main()
{
        int rows, col, i, j;
        printf("nr of rows");
        scanf("%d", &rows);
        printf("nr of collums");
        scanf("%d", &col);
        int **m1=(int**)malloc(rows*sizeof(int*));
        for (i=0; i<rows; i++)
                m1[i]=(int*)malloc(col*sizeof(int));
        int **m2=(int**)malloc(rows*sizeof(int*));
        for (i=0; i<rows; i++)
                m2[i]=(int*)malloc(rows*sizeof(int));
        int **m3=(int**)malloc(rows*sizeof(int*));
        for (i=0; i<rows; i++)
                m3[i]=(int*)malloc(col*sizeof(int));
        printf("first matrix");
        for (i=0; i<rows; i++)
                for (j=0; j<col; j++)
                {
                        printf("element ");
                        scanf("%d", &m1[i][j]);

                }
        printf("second matrix");
        for (i=0; i<rows; i++)
                for (j=0; j<col; j++)
                {
                        printf("element ");
                        scanf("%d", &m2[i][j]);

                }
        for (i = 0; i < rows; i++)
        {
                for (j = 0; j < col; j++)
                      {
                                 m3[i][j] += m1[i][k] * m2[k][j];
                        }

            printf("%d\t", m3[i][j]);
                }
        }
        printf("\n");
        for (i=0; i<rows; i++)
        {
                free(m1[i]);
                free(m2[i]);
                free(m3[i]);
        }
        free(m1);
        free(m2);
        free(m3);
        return 0;
}