
#include <stdio.h>
#include <stdlib.h>

int fib_dinam(int);

int main(void) {
    int n;
    printf("Inserire n = ");
    scanf("%d", &n);
    printf("fibonacci(%d) = %d\n", n, fib_dinam(n));
    system("pause");
    return 0;
}

int fib_dinam(int x) {
    int i;
    int *F = (int*)malloc((x+1) * sizeof(int));
    F[0] = 1;
    F[1] = 1;
    for(i=2; i<=x; i++)
        F[i] = F[i-1] + F[i-2];
    return F[x];
}

