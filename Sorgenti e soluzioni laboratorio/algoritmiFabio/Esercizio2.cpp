/* Supponiamo di avere n files aventi rispettivamente dimensione F[1]; F[2];    ; F[n];
le dimensioni sono numeri interi strettamente positivi e sono espresse in MB. Disponiamo
di un CD-ROM avente capacità m MB, m ´e fissato e dato in input. Il CD-ROM
potrebbe non essere sufficientemente capiente per memorizzare tutti gli n files. Utilizzando
la tecnica greedy:
1. Scrivere un algoritmo efficiente per determinare il numero massimo di files che
possibile memorizzare sul CD-ROM senza eccederne la capacità. Non richiesto
che l’algoritmo stampi anche quali file memorizzare. */

#include<stdio.h>
#include<stdlib.h>

void quickSort (int *array, int left, int right);

int main() {
  int cap, n, i, j, aus, peso[100], val[100],somma;
  float c[100];
  printf("Inserire la capacita' del CD in MB: ");
  scanf("%d",&cap);

  printf("Inserire il numero di files: ");
  scanf("%d",&n);
  
  for(i=0; i<n; i++){     // Memorizziamo in un array i pesi dei vari files.
    printf("Peso file n.%d = ",i);
    scanf("%d",&peso[i]);
  }
    
  for(i=0; i<n; i++){     // Memorizziamo in un array i valori dei vari files.
    printf("Valore file n.%d = ",i);
    scanf("%d",&val[i]);
  }

  for(i=0; i<n; i++) {     // Memorizziamo in un array i profitti, dati dal rapporto valore su peso, dei vari files.
     c[i] = ((float)val[i]/(float)peso[i]);
     printf("\nProfitto file n. %d = %.2f" ,i,c[i]);
  }
  
  printf("\n\n");

// Ordiniamo in maniera decrescente i profitti dei files, 
//applicando l'ordinamento anche ai pesi per mantenere la relazione tra il peso ed il profitto di ciascun file.
  
  quickSort(((int*)c), 0, n-1);
 
  printf("Files ordinati in base al loro profitto: ");
  for(i=0; i<n; i++) {
  
     printf("%.2f  ",c[i]);
}
  printf("\n");     
  
// Incrementiamo il valore 'somma' fino a quando non eccediamo la capienza massima del CD.
// Tenendo conto che, se un file non entra nel CD, l'inserimento non si arresta ma procede coi successivi files.  
  for(i=0,j=0;i<n;i++,j++)
  {
  	somma=somma+peso[i];

  	if(somma>cap)
  	{
  		somma=somma-peso[i];
  		j--;
  	}
  }
	
  
  printf("\nIl numero di FILE usati per il CD e' di %d elementi con %dMB di spazio utilizzato su %dMB di spazio disponbile.\n",j,somma,cap);

system("PAUSE");
return 0;
}

// Funzione quicksort modificata che ordina un array in modo decrescente.
void quickSort (int *array, int left, int right) {
   int i=left, j=right, temp=0;   // Inizializzo gli indici i,j e la variabile temp per fare gli scambi
   int pivot=array[(left+right)/2];  // Scelgo il pivot
   do {
      while (array[i]>pivot) i++;  // Avanzo i finchè non trovo un valore minore del pivot
      while (array[j]<pivot) j--;  // Arretro j finchè non trovo un valore maggiore del pivot
      if (i<=j) {
        temp = array[i];  // Effettuo lo scambio
        array[i]=array[j];
		array[j]=temp; 
		i++; j--;
      }
   } while (i<=j);
   if (left<j) quickSort(array,left,j);  // Chiamo ricorsivamente la funzione quicksort
   if (i<right) quickSort(array,i,right);
}
