#include <stdio.h>

#define MAX 10

void printMatrix(float mat[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%8.3f ", mat[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    float a[MAX][MAX], inverse[MAX][MAX];
    
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%f", &a[i][j]);

    // Initialize the inverse matrix as identity
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inverse[i][j] = (i == j) ? 1.0 : 0.0;

    // Applying Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        float diag = a[i][i];
        if (diag == 0.0) {
            printf("Matrix is singular and cannot be inverted.\n");
            return 0;
        }

        // Normalize the pivot row
        for (int j = 0; j < n; j++) {
            a[i][j] /= diag;
            inverse[i][j] /= diag;
        }

        // Eliminate all other rows
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float ratio = a[k][i];
                for (int j = 0; j < n; j++) {
                    a[k][j] -= ratio * a[i][j];
                    inverse[k][j] -= ratio * inverse[i][j];
                }
            }
        }
    }

    printf("\nInverse of the matrix is:\n");
    printMatrix(inverse, n);

    return 0;
}
