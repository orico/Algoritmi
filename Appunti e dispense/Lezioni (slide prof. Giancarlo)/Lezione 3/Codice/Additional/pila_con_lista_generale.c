#include <stdio.h>
#include <stdlib.h>

typedef struct nodo *pnodo;

struct nodo
{
 void* inf;
 pnodo next;
};

pnodo crea(void *val)
{
 pnodo p = (pnodo) malloc(sizeof(struct nodo));
 p->inf=val;
 p->next=NULL;
 return(p);
}

void push(pnodo *T, void *c)
{
 pnodo p = crea(c);
 if (p!=NULL)
 { 
  p->next=*T;
  *T=p; 
 }
 else printf("OverFlow\n");
}

void *pop(pnodo *T)
{
 void *c=NULL;
 if ((*T)!=NULL)
 {
  pnodo p=*T;
  c=(*T)->inf;
  *T=(*T)->next;
  free(p);
 }
 return(c);
}

int main(int argc, char* argv[])
{
 int a=1,m=0;
 char *c,*d,buff[255];
 pnodo T=NULL;
 while(a!=3)
 {
  printf("Push=1 , Pop=2 , Fine=3 ? ");
  scanf("%d",&a);
  if (a!=3)
  {
   if (a==1) 
   {  
    printf("Elemento ?");
    //c=malloc(sizeof(int));
	c=&buff[m];
	scanf("%s",c);
	push(&T,c);
	printf("\n");
	m=m+strlen(c)+1;
   }
   else 
   {   
	d=(char*)pop(&T);
	if (d!=NULL) printf("%s\n",d);
		else printf("UnderFlow\n");
   }
  }
 }
 return 0;
}