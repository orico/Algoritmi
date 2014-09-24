#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

int *V;
int sottosequenza(int,int);
int minimo(int);
int massimo(int);
void stampa(int);
int main(void)
{
    int n,l,i;
    printf("Inserisci lunghezza stringa:");
    scanf("%d",&n);
    V=(int *)malloc(sizeof(int)*n);
    srand(time(NULL));
    for(i=0;i<n;i++)
        V[i]=rand()%10;
        stampa(n);
    l=sottosequenza(n,0);

    printf("La piu lunga sottosequenza è formata da:%d",l);

}
int minimo(int i)
{
    int j, mini=INT_MAX;
    for(j=0;j<i;j++){
        if(V[j]<mini) mini=V[j];
    }
    return mini;
}
int sottosequenza(int n, int i)
{
    int a=0;
    if(i==n)
        return 0;
    else
        if(V[i]<=V[i+1]) a=1;
    return a+sottosequenza(n,i+1);

}
int massimo(int i)
{
    int j, mas=INT_MIN;
    for(j=0;j<i;j++){
        if(V[j]>mas) mas=V[j];
    }
    return mas;
}

void stampa( int n) {
  int i;

  for (i=0; i<n; i++) {
    printf("%d ", V[i]);
  }
  printf("\n");
  return;
}
