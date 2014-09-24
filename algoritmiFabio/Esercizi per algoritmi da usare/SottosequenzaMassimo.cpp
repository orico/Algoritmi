#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void stampaVettore(int *, int);
int sottosequenza(int *,int);
int sottosequenzar(int *,int);
int massimo(int,int);

int main()
{
    int *X;
    int n,segno,m,i,l,r;
    do
    {
    printf("Come vuoi inserire i dati???\n");
    printf("0 inserisci da tastiera \n1 inserimento random:");
    scanf("%d",&m);
    }while(m<0 || m>1);
    printf("Inserisci dimensione lunghezza del vettore:");
    scanf("%d",&n);
    X=(int *)malloc(sizeof(int)*n);
    if(m==0)
        for(i=0;i<n;i++)
        {
            printf("X[%d]: ", i);
            scanf("%d", &X[i]);
        }
    else
    {
        srand((NULL));
        for(i=0;i<n;i++)
        {
            segno = rand()%2;
        if(segno == 0) segno=-1;
            X[i]=segno*(rand()%10);
        }

    }
    stampaVettore(X,n);
    l=sottosequenza(X,n);
    printf("la massima sequenza e':%d",l);
    printf("\n");
    r=sottosequenzar(X,n-1);
    printf("la massima sequenza e':%d",r);
}

int sottosequenza(int *V,int n)
{
    int *M;
    int i,aux;
    M=(int *)malloc(sizeof(int)*n);
    M[0]=V[0];
    aux=M[0];
    for(i=1;i<n;i++)
    {
        M[i]=massimo(M[i-1]+V[i],V[i]);
        if(M[i]>aux) aux=M[i];
    }
    return aux;
}

int massimo(int a,int b)
{
    if(a>=b) return a;
    else return b;
}
void stampaVettore(int *V,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",V[i]);
    printf("\n");

}
int sottosequenzar(int *V,int i)
{

    if(i==0) return V[0];
    else return(massimo(sottosequenzar(V, i-1)+V[i], V[i]));
}

