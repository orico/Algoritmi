#include <stdio.h>
#include <time.h>
#include <math.h>

void main (int argc, char** argv)
{
/* Calcolo del numero n di Fibonacci utilizzando il metodo delle potenze di matrici.
Si veda il libro di Italiano et Al. */
//M è una matrice 2x2 di interi tale che M[0][0] sarà il numero n di Fibonacci al variare di n
int M[2][2];

//n è l'ordine del numero di Fibonacci che intendiamo calcolare
//i è una variabile temporale che tiene conto del passo induttivoint n, i;

/*oldm1 e oldm2 sono due variabili temporanee utilizzate per fare il prodotto di matrici */
int oldM1;
int oldM2;
    
/*creo una variabile t che tiene conto del tempo (numero di quanti che il programma impiega per trovare la soluzione) */ 
clock_t t;
t=clock();
    
//input al programma 
n=atoi(argv[1]);

//inizializzo la matrice M secondo le condizioni iniziali dell'algoritmo
M[0][0]=1;
M[0][1]=0;
M[1][0]=0;
M[1][1]=1;

// calcolo M^i per i che va da 1 a n 
for (i=1; i<n; i++)
{
oldM1=M[0][0];
oldM2=M[1,0];
M[0][0]= M[0][0]+M[0][1];
M[0][1]=oldM1;
M[1][0]=M[1][0]+M[1][1];
M[1][1]=oldM2;
}
//fine del calcolo

//sottraggo t al clock per avere il numero di quanti che il programma ha impiegato
t=clock()-t;
    
/*stampo i valori e per avere i secondi prendo t e lo divido per la macro clock_per_sec (si veda la libreria <time.h> */
printf("il valore di fib e' %d\n", M[0][0]);
printf("ci ho messo %d clicks (%f secondi)\n", t, ((float)t)/CLOCKS_PER_SEC);

}