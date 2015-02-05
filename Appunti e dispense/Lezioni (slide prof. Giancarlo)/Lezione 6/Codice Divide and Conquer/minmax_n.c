#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define L 50

void minmax(int *S, int n, int *m, int *M)
{
 int m1,m2,M1,M2;
 if (n<2)
 {
  *m=S[0];
  *M=S[0];
 }
 else
 {
  minmax(&S[0],n/2,&m1,&M1);
  minmax(&S[n/2],n-(n/2),&m2,&M2);
  *m = (m1<m2) ? m1:m2; 
  *M = (m1>m2) ? M1:M2;
 }  
}

int main()
{
 int m,M,i;
 int *A = (int *) malloc (N*sizeof(int));
 srand((unsigned) time (NULL));
 for (i=0;i<N;i++)
 {
  A[i]=rand()%L;
  printf("%d ",A[i]);	 
 }
 printf("\n");	 
 minmax(A,N,&m,&M); 
 printf("%d %d\n",m,M);	 
}