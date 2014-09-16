#include<stdio.h>
#include<stdlib.h>

/* Dato un vettore di n numeri reali, si programmi un algoritmo che, utilizzando il
   divide and conquer, calcoli la somma degli elementi nel vettore. */

int somma(int,int);

int main()
{
    int *v,n,i,sum;

    printf("Inserisci il numero di elementi del vettore: ");
    scanf("%d",&n);

    v=malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
        printf("Inserisci elemento: ");
        scanf("%d",&v[i]);
    }

    for(i=0;i<n;i++)
        printf("%d ",v[i]);

    sum=somma(0,n);
    printf("Somma degli elementi del vettore: %d\n",sum);

  return 0;
}

int somma(int i, int j)
{
    int meta,sum=0;

    if(i<=j) return sum;

    meta=(i+j)/2;
    if(meta<i)


  return sum;
}



