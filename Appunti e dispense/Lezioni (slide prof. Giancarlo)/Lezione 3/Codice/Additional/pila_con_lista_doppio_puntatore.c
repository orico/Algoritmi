#include <stdio.h>

typedef struct nodo *pnodo;

struct nodo
{
 int inf;
 pnodo next;
 pnodo prev;
};

pnodo T=NULL;

pnodo malloc(int size_t);
pnodo free();

pnodo crea(int val)
{
 pnodo p = (pnodo) malloc(sizeof(struct nodo));
 p->inf=val;
 p->next=NULL;
 p->prev=NULL;
 return(p);
}

void push(int c)
{
 pnodo p = crea(c);
 if (p!=NULL)
	{ 
	 if (T!=NULL) T->next=p;
     p->prev=T; 
	 T=p;
 }
 else printf("OverFlow\n");
}

int pop()
{
 int c=-1;
 if (T!=NULL)
 {
  pnodo p=T;
  c=T->inf;
  T=T->prev;
  if (T!=NULL) T->next=NULL;
  free(p);
 }
 return(c);
 
}

int main(int argc, char* argv[])
{
 int a=1,c;

 while(a!=3)
 {
  printf("Push=1 , Pop=2 , Fine=3 ? ");
  scanf("%d",&a);
  if (a!=3)
  {
   if (a==1) 
   {  
    printf("Elemento ?");
    scanf("%d",&c);
    push(c);
	printf("\n");
   }
   else 
   {   
	c=pop();
	if (c!=-1) printf("%d\n",c);
		else printf("UnderFlow\n");
   }
  }
 }
 return 0;
}
