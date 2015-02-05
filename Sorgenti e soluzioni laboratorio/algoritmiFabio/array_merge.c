#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stampa (int*, int);
int* simple_merge(int*, int, int);

int main (){
	clock_t t;
	int *a;
	int dim;
	int j,i;
	printf("Inserire la dimensione dell'array: ");
	do{
		scanf("%d",&dim);
		if(dim<=0)
			printf("Errore, inserire un valore positivo per la dimensione: ");		//Controllo sulla dimensione (inserire un valore positivo)
	}while(dim<=0);
	a=(int*)malloc(dim*sizeof(int));
	for(j=0,i=dim-1;j<dim;j++){		//In questo ciclo l'utente inserirà valori tutti in ordine crescente o fino alla fine della
		printf("a[%d]= ",j);				//dimensione dell'array o fino a quando non verrà inserito un valore minore del precedente.
		scanf("%d",&a[j]);
		if(j>0&&a[j-1]>a[j]){			//Se è stato inserito un valore minore del precedente, prendo nota della posizione di questo
			i=j;								//elemento nell'array salvando l'indice nella variabile "i".
			j=dim;							//Si pone la variabile "j" uguale alla dimensione dell'array per uscire dal ciclo.
		}
	}
	for(j=i+1;j<dim;j++){				//A questo punto dovremo riprendere a riempire l'array dalla posizione "i+1" fino a "dim-1",
		printf("a[%d]= ",j);				//senza trascurare il fatto che questa volta l'array dovrà essere ordinato fino alla fine in
		scanf("%d",&a[j]);				//in maniera decrescente.
		if(a[j-1]<a[j]){					//Imponiamo che l'elemento inserito sia minore o uguale del precedente.
			printf("Errore! Inserire un valore piu' piccolo di %d.\n",a[j-1]);
			j--;
		}
	}
	printf("\nArray prima della modifica:\n");
	stampa(a,dim);
	printf("Array dopo la modifica:\n");
	t=clock();
	a=simple_merge(a,i,dim);
	t=clock()-t;
	stampa(a,dim);
	printf("Tempo d'esecuzione dell'algoritmo: %f.\n\n",(float)t/CLOCKS_PER_SEC);
	system("PAUSE");
	return 0;
}


void stampa(int *a, int dim){
	int i;
	for(i=0;i<dim;i++)
		printf("%d ",a[i]);
	printf("\n\n");
}

/*
In questo caso, il nostro array è diviso in due sottoarray: A[1::(i-1)] ordinato in senso crescente e A[i::n] in senso decrescente.
Tenendo conto di questa informazione, modifichiamo la procedura Merge tenendo conto del fatto che il confronto stavolta va fatto scorrendo A[1::i-1]
da 1 a (i-1), mentre A[i::n] da n a i, poiché quest'ultimo è ordinato in senso opposto.
Il costo computazionale dell'algoritmo è dell'ordine di n.
*/

int* simple_merge(int* a,int i, int dim){
	int j,k;
	int *b;
	b=(int*)malloc(dim*sizeof(int));
	for(j=0,k=0;j<i&&dim-1-k>=i;){		//Con j scorro l'array A da 1 a (i-1), con k scorro l'array da (dim-1) ad i.
		if(a[j]>a[dim-1-k]){
			b[j+k]=a[dim-1-k];				//Prendo il più piccolo valore tra A[j] e A[dim-1-k] e lo metto nella posizione "j+k"
			k++;									//dell'array temporaneo B e incremento di un'unità j se ho preso l'elemento dal
		}											//sottoarray A[1::(i-1)], altrimenti incremento k.
		else{
			b[j+k]=a[j];						//Se scorro completamente uno dei due sotto array non è più necessario eseguire dei
			j++;									//confronti dunque basterà ricopiare la parte rimanente del sotto array rimanente.
		}
	}
	if(j==i)
		for(;j+k<dim;k++)						//Se ho finito di scorrere A[1::(i-1)], completo l'array B ricopiando al contrario
			b[j+k]=a[dim-1-k];                  //A[i::(dim-1-k)
	else
        for(;j+k<dim;j++)						//Se ho finito di scorrere A[i::(dim-1)}, completo l'array B ricopiando al contrario
			b[j+k]=a[j];                        //A[j::(i-1)
	return b;
}

