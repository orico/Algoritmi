#include "stdafx.h"
#define N 4

int H,T;

int Q[N];

void enqueue(int c)
{
 if ((T+1)%N==H) printf("OverFlow");
 else
	{
	 T=(T+1)%N;
     Q[T]=c;
     if (H==-1) H=0;
 }
}

int dequeue()
{
 int c;
 if (H==-1) printf("UnderFlow");
 else
	{
	 c=Q[H];
     if (H==T) 
	 {
	  H=-1;
	  T=-1;
	 }
     else H=(H+1)%N;
 }
return(c);

}

int main(int argc, char* argv[])
{
 H=-1;
 T=-1;
 int a=1,c,i,mi,ma;

 while(a!=3)
 {
  printf("Enqueue=1 , Dequeue=2 , Fine=3 ? ");
  scanf("%d",&a);
  if (a!=3)
  {
   if (a==1) 
   {  
    printf("Elemento ?");
    scanf("%d",&c);
    enqueue(c);
	printf("\n");
   }
   else 
   {   
	c=dequeue();
    printf("%d\n",c);
   }
  }
  printf("%d",Q[0]);
  for (i=1;i<N;i++) printf("-%d",Q[i]);
  printf("\n");
  
  mi=H;
  ma=T;

  if (mi>ma) 
  {
   mi = T;
   ma = H;
  }
  
  for (i=0;i<mi;i++) printf("  ");
  
  if (mi!=ma)
  {
   if (H<T) printf("H ");
    else printf("T ");
   for (i=mi+1;i<ma;i++) printf("  ");
   if (H<T) printf("T ");
    else printf("H \n");
   
  }
  else 
  {
   printf("H\n");
   for (i=0;i<mi;i++) printf("  ");
   printf("T\n");
  }
  printf("H:%d - T:%d\n",H,T);
 }
 
 return 0;
}

