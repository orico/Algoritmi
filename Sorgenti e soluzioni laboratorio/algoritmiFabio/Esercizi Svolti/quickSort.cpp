
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void scambia(int *a, int *b) {
    int aus = *a;
    *a = *b;
    *b = aus;
}

void quickSort(int *A, int inizio, int fine) {
    int i, j, pivot;
    i = inizio;
    j = fine;
    pivot = (A[i] + A[j]) / 2;
    do {
        while(A[i] < pivot)
            i++;
        while(A[j] > pivot)
            j--;
        if(i <= j) {
            scambia(&A[i], &A[j]);
            i++;
            j--;
        }
    }
    while(i <= j);
    if(inizio < j)
        quickSort(A, inizio, j);
    if(fine > i)
        quickSort(A, i, fine);
}

int main (void) {

    // alloca e riempi un vettore di n elementi random
    int *v, n, i;
    printf("Numero di elementi del vettore: ");
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));

    srand(time(NULL));
    for(i=0; i<n; i++) {
        v[i] = rand()%10;
        printf("%d\t", v[i]);
    }
    printf("\n\nVettore ordinato\n");
    quickSort(v, 0, n-1);
    for(i=0; i<n; i++)
        printf("%d\t", v[i]);
    return 0;
}
