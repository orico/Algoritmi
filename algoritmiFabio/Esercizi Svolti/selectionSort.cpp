
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void scambia(int *a, int *b) {
    int aus = *a;
    *a = *b;
    *b = aus;
}

void selectionSort(int *A, int n) {
    int i, j, m;
    for(i=0; i<n-1; i++) {
        m = i;
        for(j=i+1; j<n; j++) {
            if(A[j] < A[m])
                m = j;
            scambia(&A[m], &A[i]);
        }
    }
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
    selectionSort(v, n);
    for(i=0; i<n; i++)
        printf("%d\t", v[i]);
    printf("\n");
    return 0;
}
