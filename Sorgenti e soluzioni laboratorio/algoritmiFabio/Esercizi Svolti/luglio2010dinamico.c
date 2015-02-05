#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int binomiale(int,int);

int main(void)
{
    int n,k,valore;
    double intervallo;
    clock_t Start, End;
    do
    {
    printf("inserisci valore n:");
    scanf("%d",&n);
    printf("Inserisci valore di k:");
    scanf("%d",&k);
    } while(k>n);

    Start = clock();
    valore = binomiale(n,k);
    End = clock();

    intervallo=(double)((End-Start)/CLOCKS_PER_SEC);

    printf("\n\nIl coefficiente binomiale e'%d:",valore);

    printf("\nIl tempo empirico = %f\n",intervallo);

}
int binomiale(int n,int k)
{
   int **M,i,j;
   M=(int **)malloc((n+1)*sizeof(int));
   for(i=0;i<=n;i++)
        M[i]=(int *)malloc((k+1)*sizeof(int));
   M[0][0]=1;

   for(i=1;i<=n;i++)
        M[i][0]=1;

   for(i=1;i<=n;i++)

        for(j=1;j<=i;j++)
        {

            if(i==j)
                M[i][j]=1;
            else
        M[i][j]=M[i-1][j-1]+M[i-1][j];
        }
   for(i=0;i<=n;i++)
   {
       printf("\n");
       for(j=0;j<=i;j++)
        printf("%d\t",M[i][j]);
   }
   return M[n][k];
}
