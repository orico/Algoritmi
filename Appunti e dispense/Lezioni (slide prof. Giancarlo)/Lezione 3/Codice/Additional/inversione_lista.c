#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nodo* pnodo;

#define N 40
#define M 4

struct nodo
{
 int inf;
 pnodo next;
};

//genera numeri interi random
unsigned int random_intera(unsigned int n)
{
 double num;
 //srand( (unsigned)time( NULL ) );
 num = (n-1)*(((double) rand())/RAND_MAX);
 return(floor(num));
}


int main()
{
 int i;

 pnodo x,y,v,r,t=NULL,tt,z=NULL;

 
 for(i=0;i<N;i++)
 {
  x=(pnodo) malloc(sizeof(*x));
  x->inf=random_intera (N);
  printf("%d ",x->inf); 
  if (t==NULL) t=x;
	  else y->next=x;
  y=x;
 }
 
 printf("\n"); 	

 x->next=NULL;

 x=t;
 r=NULL;
 
 while(x!=NULL)
 {
  v=x->next;
  x->next = r;
  r=x;
  x=v;
 }

 y=r;

 printf("\n"); 	

 while(y!=NULL)
 {
  printf("%d ",y->inf); 	
  y=y->next;
 }

 printf("\n"); 	
}