#include <stdio.h>
#include <string.h>

typedef struct nodo* pnodo;

struct nodo
{
 int inf;
 pnodo next;
};

pnodo T=NULL;
pnodo malloc(int size_t);
pnodo free();

pnodo creanodo(int val)
{
 pnodo p = (pnodo) malloc(sizeof(*p));
 p->inf=val;
 p->next=NULL;
 return(p);
}

void push(int c)
{
 pnodo p = creanodo(c);
 p->next=T;
 T=p;
}

int pop()
{
 int c = -1;
 if (T!=NULL)
 {
  pnodo p=T;
  c=T->inf;
  T=T->next;
  free(p);
 }
 return(c);
}

int main(int argc, char* argv[])
{
 char buff[255];
 char *a;
 int fine = 0,m=0,c,d;
 m=0;
 while (fine==0)
 {
  a=&buff[m];
  scanf("%s",a);
  if (*a=='q') fine =1;
  else
  {
   switch (*a)
   {
    case '+' : push(pop() + pop());break;
    case '*' : push(pop() * pop());break;
    case '-' : c=pop();d=pop(); push(d - c);break;
    case '/' : c=pop();d=pop(); push(d / c);break;
    default : push(atoi(a));
   }
  }
  m=m+strlen(a)+1;
 }
 printf("%d\n",pop());
 return 0;
}
