#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int binomiale(int,int);
int main(void)
{
    int n,k,valore;
    clock_t Start,End;
    double intervallo;
    do
    {
    printf("inserisci valore n:");
    scanf("%d",&n);
    printf("Inserisci valore di k:");
    scanf("%d",&k);
    } while(k>n);
    Start=clock();
    valore=binomiale(n,k);
    End=clock();
    intervallo=(double)((End-Start)/CLOCKS_PER_SEC);
    printf("Il coefficiente binomiale e':%d",valore);
    printf("\nTempo Empirico= %f",intervallo);
    
    system("pause");
    return 0;
}
int binomiale(int n,int k)
{
    if(k==0) return 1;
    if(k==n) return 1;
    else
        return(binomiale(n-1,k-1)+binomiale(n-1,k));
}

