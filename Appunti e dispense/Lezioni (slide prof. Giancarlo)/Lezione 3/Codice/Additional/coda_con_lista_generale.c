#include <stdio.h>
#include <stdlib.h>

typedef struct nodo *pnodo;

struct nodo
{
 void *inf;
 pnodo next;
};

pnodo crea(void *val)
{
 pnodo p = (pnodo) malloc(sizeof(*p));
 p->inf=val;
 p->next=NULL;
 return(p);
}

void enqueue(pnodo *H,pnodo *T, void *c)
{
 pnodo p = crea(c);
 if (p!=NULL)
 {
  if ((*T)!=NULL) (*T)->next=p;
  else ((*H)=p);
  *T=p;
 }
 else printf("OverFlow\n");
}

void *dequeue(pnodo *H,pnodo *T)
{
 void *c=NULL;
 pnodo p=*H;
 if ((*H)!=NULL)
 {
  c=(*H)->inf;
  *H=(*H)->next;
  if ((*H)==NULL) *T=*H; 
  free(p);
 }
 
 return(c);
}

int main(int argc, char* argv[])
{
 pnodo H=NULL;
 pnodo T=NULL;
 int a=1,*c;

 while(a!=3)
 {
  printf("Enqueue=1 , Dequeue=2 , Fine=3 ? ");
  scanf("%d",&a);
  if (a!=3)
  {
   if (a==1) 
   {  
    printf("Elemento ?");
    c=malloc(sizeof(int));
	scanf("%d",c);
    enqueue(&H,&T,c);
	printf("\n");
   }
   else 
   {   
	c=dequeue(&H,&T);
	if (c!=NULL) printf("%d\n",*c);
		else printf("UnderFlow\n");
   }
  }
 }
 return 0;
}
