#include <stdio.h>
int main()
{
    int a[2][3], b[2][3], sum[2][3];
    int i, j;

    printf("Enter elements of first matrix (2x3):\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix (2x3):\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &b[i][j]);

    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            sum[i][j] = a[i][j] + b[i][j];

    printf("\nSum of the two matrices:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }

    return 0;
}
