#include<stdio.h>
#include<stdlib.h>

int funz_ric(int,int);
int funz_din(int **,int,int);
int main()
{
    int ris_ric,ris_din,n,k,i,j;
    int **mat;
    do{
       printf("Inserisci n: ");
       scanf("%d",&n);
       printf("Inserisci k: ");
       scanf("%d",&k);
       }
    while(n<k);
    ris_ric=funz_ric(n,k);
    printf("Risultato (ricorsivo): %d\n",ris_ric);
    mat=(int**)malloc(sizeof(int)*(n+1));
    for(i=0;i<=n;i++)
    {
      mat[i]=(int *)malloc(sizeof(int)*(k+1));
      }
    ris_din=funz_din(mat,n,k);
    for(i=0;i<=n;i++)
    {
      for(j=0;j<=k;j++)
        {
          if(j<=i)printf("%d\t",mat[i][j]);
        }
      printf("\n");
      }
      system("pause");
    printf("Risultato (dinamica): %d\n",ris_din);
    getchar();
    system("pause");
}

int funz_ric(int n,int k)
{
    if(k==0) return 1;
    if(k==n) return 1;
    else
    {
        return (funz_ric(n-1,k-1)+funz_ric(n-1,k));
    }
}

int funz_din(int **mat,int n,int k)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
      mat[i][0]=1;
      mat[i][i]=1;
      }
    for(i=2;i<=n;i++)
    {
      for(j=1;j<i;j++)
      {
        mat[i][j]=mat[i-1][j-1]+mat[i-1][j];
      }
    }
    return(mat[n][k]);
}
