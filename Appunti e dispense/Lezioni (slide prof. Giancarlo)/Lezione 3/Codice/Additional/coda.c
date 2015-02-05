#include <stdio.h>
#define N 4

int H,T;

int Q[N];


typedef struct nodo
{
 double inf;
 struct nodo* pun;
};

typedef struct nodo *pnodo;


void enqueue(int c)
{
 if (T==N-1) printf("OverFlow");
 else
	{
	 T=T+1;
     Q[T]=c;
   }
}

int dequeue()
{
 int c,i;
 if (T<H) printf("UnderFlow");
 else
	{
	 c=Q[H];
     for (i=1;i<=T;i++) Q[i-1]=Q[i];
	 T=T-1;
 }
return(c);

}

int main(int argc, char* argv[])
{
 int a=1,c,i,b,g;
 double d;

 H=0;
 T=-1;
 
 c=sizeof(nodo)-(sizeof(double)+sizeof(pnodo));

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
  printf("\nH = %d, T= %d\n",H,T);
  
  
 }
 
 return 0;
}

