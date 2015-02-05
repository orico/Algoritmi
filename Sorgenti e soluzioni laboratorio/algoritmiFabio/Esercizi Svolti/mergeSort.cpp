
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int *A, int inizio, int fine) {
    int *X, i, j, k, m;
    X = (int *)malloc(fine * sizeof(int));
    if(fine > inizio) {
            m = (fine + inizio)/2;
            mergeSort(A, inizio, m);
            mergeSort(A, m+1, fine);
            for(i=m+1; i>inizio; i--)
                X[i-1] = A[i-1];
            for(j=m; j<fine; j++)
                X[fine+m-j] = A[j+1];
            for(k = inizio; k<=fine; k++)
                A[k] = (X[i] < X[j]) ? X[i++] : X[j--];
    }
}

int main (void) {
    int *v, n, i;
    printf("Inserire un vettore di dimensione: ");
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));
    srand(time(NULL));
    for(i=0; i<n; i++) {
        v[i] = rand()%10;
        printf("%d\t", v[i]);
    }

    mergeSort(v, 0, n-1);
    printf("\n\nVettore ordinato\n");
    for(i=0; i<n; i++)
        printf("%d\t", v[i]);
    return 0;
}
