
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void scambia(int *a, int *b) {
    int aus = *a;
    *a = *b;
    *b = aus;
}

void integerSort(int *A, int n) {
    int *X, i, j;
    X = (int *)malloc(n *sizeof(int));
    for(i=0; i<n; i++)
        X[i] = 0;
    for(i=0; i<n; i++)
        X[A[i]-1]++;                //metto il -1 perchè i valori vanno da 1 a n (con valori da 0 a n-1 si leva)
    j = 0;
    for(i=0; i<n; i++) {
        while(X[i] > 0) {
            A[j] = i+1;             //metto il +1 perchè i valori vanno da 1 a n (con valori da 0 a n-1 si leva)
            j++;
            X[i]--;
        }
    }
}

int main (void) {
    int *v, n, i;
    printf("Inserire n: ");
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));
    printf("Vettore di %d elementi compresi tra [1, %d]:\n", n, n);
    srand(time(NULL));
    for(i=0; i<n; i++) {
        v[i] = rand()%n + 1;
        printf("%d\t", v[i]);
    }
    printf("\n\n");
    integerSort(v, n);
    for(i=0; i<n; i++)
        printf("%d\t", v[i]);
    printf("\n");
    return 0;
}
