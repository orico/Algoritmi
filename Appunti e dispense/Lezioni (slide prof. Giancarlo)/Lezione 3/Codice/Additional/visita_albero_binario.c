#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *oper ="+*-/";

int N;


typedef struct nodo *pnodo;

struct nodo
{
 char *inf;
 pnodo l;
 pnodo r;
};

int isoperator(char a)
{
 int isin=0;
 int j=0;
 while ((isin==0) && (j<strlen(oper)))
 {	 
  isin = ((isin) || (oper[j]==a));
  j++;
 }
 return(isin);
}

pnodo creanodo(char *val)
{
 pnodo p;
 p=(pnodo) malloc(sizeof(*p));
 p->inf=val;
 p->l=NULL;
 p->r=NULL;
 return p;
}

pnodo crea_albero_prefisso(int *i,char **a)
{
 pnodo p;
 *i=*i+1;
 p=creanodo(a[*i]);
 if (isoperator(*p->inf))
 {
  p->l=crea_albero_prefisso(i,a);
  p->r=crea_albero_prefisso(i,a);
 }	 
 return(p);
}

pnodo crea_albero_postfisso(int *i,char **a)
{
 pnodo p;
 *i=*i-1;
 p=creanodo(a[*i]);
 if (isoperator(*p->inf))
 {
  p->r=crea_albero_postfisso(i,a);
  p->l=crea_albero_postfisso(i,a);
 }	 
 return(p);
}

void visita_postordine(pnodo p)
{
 if (p==NULL) return;
 visita_postordine(p->l);
 visita_postordine(p->r);
 printf("%s ",p->inf);
}

void visita_preordine(pnodo p)
{
 if (p==NULL) return;
 printf("%s ",p->inf);
 visita_preordine(p->l);
 visita_preordine(p->r);
}

void visita_inordine(pnodo p)
{
 if (p==NULL) return;
 if ((p->l)!=NULL) printf("( ");
 visita_inordine(p->l);
 printf("%s ",p->inf);
 visita_inordine(p->r);
 if ((p->r)!=NULL) printf(") ");
}

int valuta_postfissa(pnodo p)
{
 int a,b,c;
 if ((p->l==NULL) && (p->r==NULL))  return atoi(p->inf);
 a=valuta_postfissa(p->l);
 b=valuta_postfissa(p->r);
 switch(*(p->inf))
 {	
  case '+' : c = a+b;break;
  case '-' : c = a-b;break;
  case '*' : c = a*b;break;
  case '/' : c = a/b; break;
 }
 return(c);
}

int main(int argc, char* argv[])
{
 int i=0;
 int j=argc;
 int result = 0;
 pnodo rad;
 //immissione dati per fare la verifica dele visite
 //la sequenza dei nodi secondo una visita in preordine vale : 1 2 4 5 3 6  
 /*
 rad=creanodo("1");
 pnodo rs=creanodo("2");
 pnodo rd=creanodo("3");
 pnodo rss=creanodo("4");
 pnodo rsd=creanodo("5");
 pnodo rds=creanodo("6");
 rad->l=rs;
 rad->r=rd;
 rs->l=rss;
 rs->r=rsd;
 rd->l=rds;*/
 rad=crea_albero_postfisso(&j,argv) ; 
 //crea l'albero considerando al stringa in input in notazione prefissa 
 //N=argc;
 //rad=crea_albero_prefisso(&i,argv) ; 
 
 printf("\nVisita postordine : ");
 visita_postordine(rad);
 printf("\nVisita preordine : ");
 visita_preordine(rad);
 printf("\nVisita inordine : ");
 visita_inordine(rad);
 result = valuta_postfissa(rad);
 printf("\nRisultato : %d \n",result);
 return 0;
}
