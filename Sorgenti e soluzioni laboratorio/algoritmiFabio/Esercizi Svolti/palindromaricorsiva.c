#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int palindroma(char [],int ,int);
int massimo(int ,int );
int main(void)
{
    int **M;
    int n,Lunghezza;
    char str[20];
    printf("Inserisci stringa:");
    scanf("%s",&str);
    clock_t Start,End;
    double intervallo;
    n=strlen(str);
    Start=clock();
    Lunghezza=palindroma(str,0,n-1);
    End=clock();
    intervallo=(double)((End-Start)/CLOCKS_PER_SEC);
    printf("La Parola massima e':%d",Lunghezza);
    printf("\nIl tempo Empirico =%f",intervallo);
}
int palindroma(char S[],int i,int j)
{

    if(i>j)
        return 0;
    if(i==j)
        return 1;
    if(S[i]==S[j] && palindroma(S,i+1,j-1)==j-i-1)
        return 2+palindroma(S,i+1,j-1);
    else
        return massimo(palindroma(S,i+1,j),palindroma(S,i,j-1));
}

int massimo(int a,int b)
{
    if(a>b) return a;
    else return b;
}
