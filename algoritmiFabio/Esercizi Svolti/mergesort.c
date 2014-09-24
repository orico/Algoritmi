#include <stdio.h>
#include <stdlib.h>
int *V;
int *X;
void mergesort(int,int);
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
    stampa(n);
    mergesort(0,n-1);
    stampa(n);
}
void stampa(int n) {
  int i;

  for (i=0; i<n; i++) {
    printf("%d ", V[i]);
  }
  printf("\n");
  return;
}
void mergesort(int l,int r)
{

    int i,j,k,m;
    int *b;
    b=(int *)malloc(sizeof(int)*r);
    if(r > l)
    {
        m=(r+l)/2;
        mergesort(l,m);
        mergesort(m+1,r);
        for(i=m+1;i>l;i--)
            b[i-1]=V[i-1];
        for(j=m;j<r;j++)
            b[r+m-j]=V[j+1];
        for(k=l;k<=r;k++)
        V[k]=(b[i]<b[j]) ? b[i++] : b[j--];
    }
}

