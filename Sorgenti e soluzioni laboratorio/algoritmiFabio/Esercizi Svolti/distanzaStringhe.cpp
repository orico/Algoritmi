
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min3(int x, int y, int z) {

    // calcola il minimo tra 3 valori x, y, z
    if(y > x)
        x = y;
    if(z > x)
        x = z;
    return x;
}

int distanzaStringhe(char *x, char *y) {

    int x_len, y_len, **D, i, j;
    x_len = strlen(x);
    y_len = strlen(y);

    // alloco la matrice dinamicamente
    D = (int **)malloc((x_len+1) * sizeof(int *));
    for(i=0; i<x_len+1; i++)
        D[i] = (int *)malloc((y_len+1) * sizeof(int));

    // inizializzo la colonna 0
    for(i=0; i<x_len+1; i++)
        D[i][0] = i;

    // inizializzo la riga 0
    for(j=1; j<y_len+1; j++)
        D[0][j] = j;

    // riempimento della matrice
    for(i=1; i<x_len+1; i++)
        for(j=1; j<y_len+1; j++)
            if(x[i-1] == y[j-1])
                D[i][j] = D[i-1][j-1];
            else
                D[i][j] = 1 + min3(D[i-1][j], D[i][j-1], D[i-1][j-1]);

    // stampa della matrice
    for(i=0; i<x_len+1; i++) {
            printf("\n");
            for(j=0; j<y_len+1; j++)
                printf("%d\t", D[i][j]);
    }

    return D[x_len][y_len];
}

int main (void) {

    char s1[20], s2[20];
    printf("Stringa X = ");
    scanf("%s", &s1);
    printf("Stringa Y = ");
    scanf("%s", &s2);
    printf("\nMatrice distanza tra stringhe:");
    printf("\n\nD(X, Y) = %d\n", distanzaStringhe(s1, s2));
    return 0;
}
