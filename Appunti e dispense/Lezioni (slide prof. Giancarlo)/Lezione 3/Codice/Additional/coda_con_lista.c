#include <stdio.h>


typedef struct nodo
{
 int inf;
 struct nodo *next;
 struct nodo *prev;
};

typedef struct nodo *pnodo;


pnodo H=NULL;
pnodo T=NULL;

pnodo *malloc(int size_t);
pnodo free();

pnodo crea(int val)
{
 pnodo p = (pnodo) malloc(sizeof(struct nodo));
 p->inf=val;
 p->next=NULL;
 return(p);
}

void enqueue(int c)
{
 pnodo p = crea(c);
 if (p!=NULL)
 {
  if (T!=NULL) T->next=p;
  else (H=p);
  T=p;
 }
 else printf("OverFlow\n");
}

int dequeue()
{
 int c = -1;
 pnodo p=H;
 if (H!=NULL)
 {
  c=H->inf;
  H=H->next;
  if (H==NULL) T=H; 
  free(p);
 }
 
 return(c);
}

int main(int argc, char* argv[])
{
 int a=1,c;

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
	if (c!=-1) printf("%d\n",c);
		else printf("UnderFlow\n");
   }
  }
 }
 return 0;
}
