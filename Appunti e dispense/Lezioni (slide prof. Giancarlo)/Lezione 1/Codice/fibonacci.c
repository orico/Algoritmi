#include <stdio.h>

#define N 10

int *F;


int FIB(int n)
{
 int FB=F[n];
 if (FB==-1)
  FB=FIB(n-1)+FIB(n-2);
 return(FB);
}

int main()
{
 int i;
 F = (int *) malloc( (N+1) * sizeof(int) );
 F[0]=0;
 F[1]=1;
 for (i=2;i<=N;i++) F[i]=-1; 
 
 printf("Il numero di fibonacci : %d\n",FIB(N));
}