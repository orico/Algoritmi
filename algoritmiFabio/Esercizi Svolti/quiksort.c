#include <stdio.h>
#include <stdlib.h>
int *V;
void quicksort(int,int);
void scambia(int *,int *);
void stampa(int);
int main()
{
    int n,i;
    printf("Inserisci grandezza del vettore:");
    scanf("%d",&n);
    V=(int *)malloc(sizeof(int)*n);
    srand(time(NULL));
    for(i=0;i<n;i++)
        V[i]=rand()%100;
    quicksort(0,n-1);
    stampa(n);

}
void quicksort(int inizio,int fine)
{
    int i,j,pivot;
    i=inizio;
    j=fine;
    pivot=(V[i]+V[j])/2;
    do
    {
        while(V[i]<pivot)
            i++;
        while(V[j]>pivot)
            j--;
        if(i<=j)
        {
            scambia(&V[i],&V[j]);
            i++;
            j--;
        }
    } while(i<=j);
    if(inizio<j)
        quicksort(inizio,j);
    if(fine>i)
        quicksort(i,fine);
}
void scambia(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
void stampa(int n) {
  int i;

  for (i=0; i<n; i++) {
    printf("%d ", V[i]);
  }
  printf("\n");
  return;
}
