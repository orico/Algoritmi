#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int palindroma(char [],int);
int massimo(int ,int );
int main(void)
{
    int n,Lunghezza;
    char str[20];
    printf("Inserisci stringa:");
    scanf("%s",&str);
    clock_t Start,End;
    double intervallo;
    n=strlen(str);
    Start=clock();
    Lunghezza=palindroma(str,n-1);
    End=clock();
    intervallo=(double)((End-Start)/CLOCKS_PER_SEC);
    printf("La Parola massima e':%d",Lunghezza);
    printf("\nIl tempo Empirico =%f",intervallo);
}
int palindroma(char S[],int n)
{
    int **M;
    int i,j;

    M=(int **)malloc((n)*sizeof(int *));
    for(i=0;i<n;i++)
        M[i]=(int *)malloc((n)*sizeof(int));
    for(i=n;i>=0;i--)
    {
        for(j=0;j<=n;j++)
    {
        if(i>j)
            M[i][j]=0;
        else if(i==j)
            M[i][j]=1;
            else
            {

                if(S[i]==S[j] && M[i+1][j-1]==j-i-1)
                    M[i][j]=M[i+1][j-1]+2;
                else
                M[i][j]=massimo(M[i+1][j],M[i][j-1]);
            }

    }
    }
        return M[0][n];
}

int massimo(int a,int b)
{
    if(a>b) return a;
    else return b;
}
