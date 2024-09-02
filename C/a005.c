#include <stdio.h>
int main()
{
    int a[][4] = {0};
    int b[][5] = {0};

    int c = 0;

    scanf("%d", &c);

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int r = 0; r < c; r++)
    {
        for (int q = 0; q< 4; q++)
        {
            printf("%d", a[r][q]);
        }
        printf("\n");
    }

    for (int p = 0; p < c; p++)
    {

        if ((a[p][1] - a[p][0]) == a[p][2] - a[p][1])
        {
            int u;
            u = a[p][1] - a[p][0];
            for (int k = 0; k < 4; k++)
            {
                b[p][k] = a[p][k];
            }

            b[p][4] = b[p][3] + u;
        }

        else
        {
            int l;
            l = a[p][2] / a[p][1];
            for (int m = 0; m < 4; m++)
            {
                b[p][m] = a[p][m];
            }

            b[p][4] = b[p][3] * l;
        }
    }
    for (int z = 0; z < c; z++)
    {
        for (int y = 0; y < 5; y++)
        {
            printf("%d", b[z][y]);
        }
        printf("\n");
    }
    
}
