#include <stdio.h>
int main()
{
    int a;
    int b[4] = {0};
    int i = 0;

    scanf("%d",&a);

    printf("haha\n");
    for(i=0;i<a;i++)
    {
        for (int y = 0; y<4; y++)
        {
            scanf("%d", &b[y]);
        }
        if ((b[1] - b[1]) == (b[3] - b[2]))
        {
            printf("%d %d %d %d %d \n", b[0], b[1], b[2], b[3], b[4], b[4] + b[1] - b[0]);
        }
        else
        {
            printf("%d %d %d %d %d \n", b[0], b[1], b[2], b[3], b[4], b[4] * b[1] / b[0]);
        }
      
    }
}