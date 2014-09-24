
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *A, int n) {
    int i, j, k, x;
    for(i=0; i<n-1; i++) {
        x = A[i+1];
        for(j=0; j<i+1; j++) {
            if(A[j] > x)
                break;
        }
        if(j < i+1) {
            for(k=i; k>=j; k--)
                A[k+1] = A[k];
            A[j] = x;
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
    insertionSort(v, n);
    for(i=0; i<n; i++)
        printf("%d\t", v[i]);
    printf("\n");
    return 0;
}
