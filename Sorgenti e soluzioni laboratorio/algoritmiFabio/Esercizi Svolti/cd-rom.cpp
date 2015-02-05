
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CD 650

int max2(int a, int b) {
    if(a >= b)
        return a;
    return b;
}

int cd_mat(int *F, int n) {
    int **M, i, j;
    M = (int **)malloc(n * sizeof(int *));
    for(i=0; i<n; i++)
        M[i] = (int *)malloc((CD+1) * sizeof(int));

    for(j=0; j<=CD; j++) {
        if(j >= F[0])
            M[0][j] = 1;
        else
            M[0][j] = 0;
    }

    for(i=1; i<n; i++)
        for(j=0; j<=CD; j++) {
            if(j >= F[i])
                M[i][j] = max2(M[i-1][j], M[i-1][j-F[i]] + 1);
            else
                M[i][j] = M[i-1][j];
        }
/*
    for(i=0; i<n; i++) {
        printf("\n");
        for(j=0; j<=CD; j++)
            printf("%d\t", M[i][j]);
    }
*/

    return M[n-1][CD];
}

int main (void) {
    int i, n, *F;
    printf("Numero di file: ");
    scanf("%d", &n);
    F = (int *)malloc(n * sizeof(int));
    srand((time(NULL)));
    for(i=0; i<n; i++) {
        F[i] = rand()%CD + 1;
        printf("%d\t", F[i]);
    }
    printf("\n\n");
    printf("\n\nIl numero massimo di file e' %d\n", cd_mat(F, n));
    return 0;
}
