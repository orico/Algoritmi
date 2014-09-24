#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20 //Dimensione massima del vettore

void divecon(int,int); //Funzione Divide & Conquer

int n,v[MAX],contatore=0;

int main(void)
{
  clock_t t; int i;
  do
  {
    printf("Inserisci la dimensione del vettore (max %d elementi): ",MAX);
    scanf("%d",&n);
  } while(n>=MAX || n<=0); //Inserimento del vettore
  printf("\nInserisci gli elementi del vettore (valori ammessi 0 ed 1): \n");
  for(i=0;i<n;i++)
  {
      printf("v[%d] = ",i);
	  scanf("%d",&v[i]); //controllo che l'inserimento sia solo 0 o 1
	  if (v[i]!=0 && v[i]!=1)
      {
	      i--;
		  printf("Attenzione!! Unici valori ammessi 0 e 1\n");
      }
   } //Invoco la funzione divecon dandogli come parametri l'indice del primo elemento
   //e la lunghezza del vettore
   t=clock();
   divecon(0,n);
   printf("Totale di 0 : %d \n",contatore);
   t=t-clock();
   printf("tempo=%f\n",((float)t)/CLOCKS_PER_SEC);//tempo empirico
   system("pause");
   return 0;
}

//Funzione divide & conquer
void divecon(int i,int j)
{
    if(i+1==j)
    {
        if(v[i]==0) contatore++;
        return;
	}
	else
    {          //fase di divisione in due insiemi(divide and conquer)... //dal primo elemento a metà e da metà all'ultimo elemento
	  int m=(i+j)/2;
	  divecon(i,m);
	  divecon(m,j);
	}
}
