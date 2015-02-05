#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define MAX 100 //Dimensione massima del vettore 

void divecon(int,int); //Funzione Divide & Conquer 

int n,*v,max1=0,max2=0,contatore=0; 

int main(void) { 
  clock_t t; int i; 
  srand(time(NULL));
  printf("Inserisci la dimensione del vettore: "); 
  scanf("%d",&n); 
  v=malloc(n*sizeof(int)); 
   for(i=0;i<n;i++) { 
      v[i]=rand()%100+1;
   } 
   /*printf("\nVettore: "); 
   for(i=0;i<n;i++) { 
      printf("%d ",v[i]);
   } 
   printf("\n\n"); */
   
   
   //Invoco la funzione divecon dandogli come parametri l'indice del primo elemento 
   //e la lunghezza del vettore 
   t=clock(); 
   divecon(0,n); 
   printf("I due numeri massimi sono: %d e %d\n",max1,max2); 
   t=t-clock(); 
   printf("tempo=%f\n",((float)t)/CLOCKS_PER_SEC);//tempo empirico
   system("pause"); 
   return 0; 
   } 
   //Funzione divide & conquer 
   void divecon(int i,int j) { 
   if(i+1==j) { 
		if(v[i]>=max1){
			max1=v[i];
		}else{
			if((v[i]>max2)) //&&(v[i]!=max1)
				max2=v[i];
		}
	} 
	else {          //fase di divisione in due insiemi(divide and conquer)... //dal primo elemento a metà e da metà all'ultimo elemento 
	  int m=(i+j)/2; 
	  //printf("\n- %d -",m); 
	  divecon(i,m); 
	  divecon(m,j); 
	  } 
}

