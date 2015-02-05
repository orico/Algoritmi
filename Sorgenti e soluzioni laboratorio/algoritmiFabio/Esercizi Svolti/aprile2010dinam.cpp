
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int funz_dinam(int, int);

int main (void) {
    int n, k, x;
    double tempo;
    clock_t inizio, fine;
    printf("Inserire n: ");
    scanf("%d", &n);
    printf("Inserire k: ");
    scanf("%d", &k);

    inizio = clock();
    x = funz_dinam(n, k);
    fine = clock();
    tempo = (fine - inizio)/CLOCKS_PER_SEC;
    printf("F(%d, %d) = %d\n", n, k, x);
    printf("T = %f", tempo);
    return 0;
}

int funz_dinam(int n, int k) {
    int **M, i, j;

    M = (int **)malloc((n+1) * sizeof(int *));
    for(i=0; i<n+1; i++)
        M[i] = (int *)malloc((k+1) * sizeof(int));

    for(i=0; i<n+1; i++)
        M[i][0] = i;
    for(j=1; j<k+1; j++)
        M[0][j] = j;

    for(i=1; i<n+1; i++)
        for(j=1; j<k+1; j++) {
            M[i][j] = M[i-1][j-1] + M[i][j-1] + M[i-1][j];
    }

    return M[n][k];
}
