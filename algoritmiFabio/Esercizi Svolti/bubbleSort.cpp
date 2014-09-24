
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void scambia(int *a, int *b) {
    int aus = *a;
    *a = *b;
    *b = aus;
}

void bubbleSort(int *A, int n) {
    int i, k;
    do {
        k = 0;
        for(i=0; i<n-1; i++) {
            if(A[i] > A[i+1]) {
                scambia(&A[i], &A[i+1]);
                k = 1;
            }
        }
        n--;
    }
    while(k == 1);
}

int main (void) {
    int *v, n, i;
    printf("Inserire n: ");
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));
    srand(time(NULL));
    for(i=0; i<n; i++) {
        v[i] = rand()%10;
        printf("%d\t", v[i]);
    }
    printf("\n\n");
    bubbleSort(v, n);
    for(i=0; i<n; i++)
        printf("%d\t", v[i]);
    printf("\n");
    return 0;
}
