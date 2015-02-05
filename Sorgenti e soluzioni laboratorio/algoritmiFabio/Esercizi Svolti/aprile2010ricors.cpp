
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int funz(int, int);
int massimo(int,int,int);
int **P;
int n;
void stampa(int **);
int main (void)
{
    int k,x,y,i,j;
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
    printf("Inserire x: ");
    scanf("%d", &x);
    printf("Inserire y: ");
    scanf("%d", &y);
    printf("P(%d, %d) = %d\n", x,y, funz(x,y));
    return 0;
}
int massimo(int a,int b,int c)
{
    if(b>a) a=b;
    if(c>a) a=c;
    return a;

}
int funz(int x,int y) {

   if(y==n-1 || x==n-1)
    return (P[x][y]);
   else
    return(P[x][y]+massimo(funz(x+1,y-1),funz(x+1,y),funz(x+1,y+1)));
}
void stampa(int **P)
{
    int i,j;
    for(i=0;i<n;i++)
    {

        for(j=0;j<n;j++)
            printf("%d\t",P[i][j]);
        printf("\n");
    }
}
