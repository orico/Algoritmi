#include <stdio.h>
#include <time.h>
#include <math.h>

double delay;

void sleep(double amount) 
{ 
 time_t begin, end; 
 end = begin = clock(); 
 while ( ((double) (end - begin)) / (CLOCKS_PER_SEC)  < amount) 
  end = clock(); 
} 

/*double FIB1(int n)
{
 sleep(delay);
 if (n==1 || n==2)
  return (1);
 else
  return(FIB1(n-1)+FIB1(n-2));
}*/

double FIB2(int n, double *F)
{
 sleep(delay);
 if (F[n]==-1)
  F[n]=FIB2(n-1,F)+FIB2(n-2,F);
  return(F[n]);
}

double FIB3(int n)
{
double a=1,b=1,c=1,i;
for(i=3; i<=n; i++)
 {
  sleep(delay); 
  c=a+b;
  a=b;
  b=c;
 }
 return(c);
}

void FIB4(int n, double M[2][2])
{
 int i;
 double oldM1,oldM2;
 for (i=1; i<n; i++)
 {
  sleep(delay); 
  oldM1=M[0][0];
  oldM2=M[1][0];
  M[0][0]= M[0][0]+M[0][1];
  M[0][1]=oldM1;
  M[1][0]=M[1][0]+M[1][1];
  M[1][1]=oldM2;
 }
}

void Product2_by_2(double A[2][2], double B[2][2])
{
 double C[2][2];
 sleep(delay);
 C[0][0]=A[0][0]*B[0][0]+A[0][1]*B[1][0];
 C[0][1]=A[0][0]*B[0][1]+A[0][1]*B[1][1];
 C[1][0]=A[1][0]*B[0][0]+A[1][1]*B[1][0];
 C[1][1]=A[1][0]*B[0][1]+A[1][1]*B[1][1];
 A[0][0]=C[0][0];
 A[0][1]=C[0][1];
 A[1][0]=C[1][0];
 A[1][1]=C[1][1];
}

void FIB5(int n, double M[2][2])
{
 //Questa procedura calcola ricorsivamente M^n per quadrati successivi: M^(n/2) * M^(n/2) = M^n
 //Per n dispari una ulteriore moltiplicazione é da effettuarsi
 double Temp[2][2];
 sleep(delay);         
 if (n>1)
 {
  FIB5(n/2,M);
  Product2_by_2(M,M);
 }

 if (n%2==1)
 {
  Temp[0][0]=1;
  Temp[0][1]=1;
  Temp[1][0]=1;
  Temp[1][1]=0;
  Product2_by_2(M,Temp);
 }
}

int main()
{
 int i,nmax=500,n,s;
 double f1,f2,f3,f4,f5;
 clock_t t1,t2,t3,t4,t5,t6;
 double *F,*G;
 FILE *fpT;
 double M[2][2],N[2][2];
 delay = 0.0000000000000000000000000000000000001;
 
 F=(double *) malloc((nmax+1) * sizeof(double) );
  
 fpT=fopen("tempi.txt","wb");

 for (n=3;n<=nmax;n++)
 {
  F[0]=0;
  F[1]=1;
  for (i=2;i<=n;i++) F[i]=-1; 
  
  M[0][0]=1;
  M[0][1]=0;
  M[1][0]=0;
  M[1][1]=1;

  N[0][0]=1;
  N[0][1]=0;
  N[1][0]=0;
  N[1][1]=1;
 
  //t1=clock();
  //f1=FIB1(n);
  //f1=0;
  t2=clock();
  f2=FIB2(n,F);
  t3=clock();
  f3=FIB3(n);
  t4=clock();
  FIB4(n,M);
  t5=clock();
  if(n>1)
   FIB5(n-1,N);
  t6=clock();
  f4=M[0][0];
  f5=N[0][0];
  printf("%lf \n",(double) n/nmax);
  //printf("Il numero di fibonacci : %lf %lf %lf %lf %lf\n",f2,f3,M[0][0],N[0][0]);
  fprintf(fpT,"%lf %lf %lf %lf \r\n",((double)(t3-t2))/(CLOCKS_PER_SEC),((double)(t4-t3))/CLOCKS_PER_SEC,((double)(t5-t4))/CLOCKS_PER_SEC,((double)(t6-t5))/CLOCKS_PER_SEC);
  //fprintf(fpT,"%lf %lf %lf %lf \r\n",((double)(kk)),((double)(t4-t3))/CLOCKS_PER_SEC,((double)(t5-t4))/CLOCKS_PER_SEC,((double)(t6-t5))/CLOCKS_PER_SEC);
 }
 fclose(fpT);
}