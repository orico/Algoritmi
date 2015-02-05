#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int ric_b(int *,int,int);

int main(void)
{
  int *v,n,i,num;
  clock_t t;
  
  t = clock(); //inizializzazione clock se viene posizionato prima della chiamata della funzione ric_b il clock risulterà sempre 0
  n=1000000;  
  
  v=malloc(n*sizeof(int)); //allocazione memoria vettore
  for(i=0; i<n; i++)  //assegnazione valore
  {
    v[i]=i;
  }
  /*for(i=0; i<n; i++)  //se viene tolta la stampa il clock risulterà sempre 0 tranne per un range circa 1.000.000:100.000.000
  {                     
    printf("%d\n",v[i]);         
  }*/
  
  printf("\n%d elementi\n",n);
  num=145;
  printf("\nelemento da ricercare: %d\n",num);

  // t = clock();

  if(ric_b(v,num,n)!=-1) printf("l'elemento si trova al %d^ posto\n",ric_b(v,num,n));
  else printf("elemento non trovato\n");
  
  t = clock()-t;
  
  printf ("\nci ho messo %d clicks (%f secondi)\n",t,((float)t)/CLOCKS_PER_SEC);
  free(v);  //deallocazione memoria
  
  system("PAUSE");	
  return 0;
}

int ric_b(int *vett,int ele, int dim)
{
  int i=0,f=dim-1,m;
  while(i<=f)
  {
    m=(i+f)/2;
    if(vett[m]==ele) return m+1;
    if(vett[m]<ele) i=m+1;
    else f=m-1;
  }
  return -1;
}
