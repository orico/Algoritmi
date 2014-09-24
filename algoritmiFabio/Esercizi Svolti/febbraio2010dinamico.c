
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void funz();
int massimo(int,int,int);
int **P;
int n;
void stampa(int **);

int main (void)
{
    int k,i,j;
    printf("Inserire n: ");
    scanf("%d", &n);
    P = (int **)malloc((n) * sizeof(int *));
    for(i=0;i<n;i++)
        P[i]=(int *)malloc(n*sizeof(int ));
    srand(time(NULL));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            P[i][j]=rand()%10;
    stampa(P);
    printf("\n");
    funz();
    return 0;
}
void funz()
{
    int i,j,a,b,c;
    int **G;
    G=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
        G[i]=(int *)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
        G[n-1][i]=P[n-1][i];

    for(i=n-2;i>=0;i--)
        for(j=0;j<n;j++)
        {

            if(j==0) a=0;
            else  a=G[i+1][j-1];
            if(j==n-1) c=0;
            else  c=G[i+1][j+1];
            b=G[i+1][j];
            G[i][j]=P[i][j]+massimo(a,b,c);

        }
            stampa(G);
}

void stampa(int **G)
{
    int i,j;
    for(i=0;i<n;i++)
    {

        for(j=0;j<n;j++)
            printf("%d\t",G[i][j]);
        printf("\n");
    }
}

int massimo(int a,int b,int c)
{
    if(b>a) a=b;
    if(c>a) a=c;
    return a;

}
