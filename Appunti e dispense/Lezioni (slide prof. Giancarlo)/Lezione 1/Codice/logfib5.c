#include <stdio.h>
#include <time.h>
#include <math.h>
//#include <stdlib.h>


void Product2_by_2(int A[2][2], int B[2][2])
{
    int C[2][2];
    C[0][0]=A[0][0]*B[0][0]+A[0][1]*B[1][0];
    C[0][1]=A[0][0]*B[0][1]+A[0][1]*B[1][1];
    C[1][0]=A[1][0]*B[0][0]+A[1][1]*B[1][0];
    C[1][1]=A[1][0]*B[0][1]+A[1][1]*B[1][1];
    A[0][0]=C[0][0];
    A[0][1]=C[0][1];
    A[1][0]=C[1][0];
    A[1][1]=C[1][1];
    
}

void Powermatrix(int M[2][2], int n)
{
//Questa procedura calcola ricorsivamente M^n per quadrati successivi: M^(n/2) * M^(n/2) = M^n
//Per n dispari una ulteriore moltiplicazione é da effettuarsi
 int Temp[2][2];
          
 if (n>1)
 {
  Powermatrix(M,n/2);
  Product2_by_2(M,M);
 }

 if (n%2==1)
 {
  Temp[0][0]=1;
  Temp[0][1]=1;
  Temp[1][0]=1;
  Temp[1][1]=0;
  Product2_by_2(M,Temp);
}
        
     
}


void main ()
{
/*
Calcolo del numero di Fibonacci di ordine n utilizzando potenze di matrici e la tecnica 
del doubling
*/

//M è una matrice 2x2 di interi tale che M[0][0] sarà il numero n di Fibonacci al variare di n
int M[2][2];  
//n è l'ordine del numero di Fibonacci che intendiamo calcolare
int n;
scanf("%d",&n);
/*creo una variabile t che tiene conto del tempo (numero di quanti che il programma impiega per trovare la soluzione) */
clock_t t;

t= clock();
//inizializzo la matrice M secondo le condizioni iniziali dell'algoritmo
M[0][0]=1;
M[0][1]=0;
M[1][0]=0;
M[1][1]=1;

//Calcola ricorsivamente M^(n-1)    
if(n>1)
   Powermatrix(M,n-1);

//sottraggo t al clock per avere il numero di quanti che il programma ha impiegato
t=clock()-t;
/*stampo i valori e per avere i secondi prendo t e lo divido per la macro clock_per_sec (si veda la libreria <time.h> */
printf("il valore di fib e' %d\n", M[0][0]);
printf("ci ho messo %d clicks (%f secondi)\n", t, ((float)t)/CLOCKS_PER_SEC);
scanf("%d");
}
