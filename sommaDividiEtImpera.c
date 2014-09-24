#include <stdio.h>
#include <stdlib.h>

void stampaVettore(int *v, int N)
{
    int i;
    for(i=0; i < N; i++)
        printf("%d ", v[i]);
    putchar('\n');
}

void calcola(int *v, int N, int *s)
{
    int ris1=0, ris2=0;
    if(N < 2)
    {
        *s += v[0];
    }
    else
    {
        calcola(&v[0], N/2, &ris1);
        calcola(&v[N/2], N-(N/2), &ris2);
        *s = ris1 + ris2;
    }
}

int main()
{
    int N,i;
    int *vettore;
    int somma = 0;

    printf("Inserisci n: ");
    scanf("%d",&N);

    vettore = (int*)malloc(N*sizeof(int));

    for(i=0; i < N; i++)
    {
        printf("Valore [%d]: ", i);
        scanf("%d", &vettore[i]);
    }

    stampaVettore(vettore, N);
    calcola(vettore, N, &somma);

    printf("Risultato: %d\n", somma);
    return 0;
}
