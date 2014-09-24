#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//( Punto A ) Funzione ricorsiva
int Fr(int,int);
//( Punto B ) Funzione utilizzante la programmazione dinamica
int Frd(int,int);
//Funzione che stampa i tempi empirici delle due funzioni precedenti
void tempi();

int main () {
    // Indici
    int n,k;
    //Variabili temporali
    clock_t t1;

    do {
    //Inserimento indici n e k
    printf("Inserisci n e k\n-->");
    scanf("%d",&n);
    printf("-->");
    scanf("%d",&k);
    // se k è maggiore di n viene richiesto nuovamente l'inserimento.
    // la relazione di ricorrenza ci impone k minore o uguale a n
    } while(n<k);

    //tempo della prima funzione
    t1=clock();
    printf("Risultato 1------>%d",Fr(n,k)); //Stampa risultato
    t1=clock()-t1;     //tempo empirico e stampa
    printf("\nTempo di Fr %f", ((float)t1/CLOCKS_PER_SEC));

    t1=clock();
    printf("\nRisultato 2------>%d",Frd(n,k));
    t1=clock()-t1;
    printf("\nTempo di Frd %f\n", ((float)t1/CLOCKS_PER_SEC));

    system("pause");

    //Richiamo funzione per il calcolo dei tempi empirici
    tempi();

    printf("\n");
    system("pause");
return 0;
}

//Punto A  Funzione Ricorsiva
//Costo esponenziale
int Fr(int n,int k){
    //caso base K=0 e caso limite K=N
    if(k==0 || n==k) return 1;
    //Chiamata ricorsiva
    else return (Fr(n-1,k-1) + Fr(n-1,k));
}

//Punto B Programmazione Dinamica
//Funzione con costo O(n^2)
int Frd(int n, int k){
    //Dimensione matrice e dichiarazione
    int d=n+1;
    int m[d][d];
    //indici di matrice
    int i, j;
	//Riempimento della matrice NxN secondo la regola di ricorrenza
    for(i=0; i<d; i++)    {
        for(j=0; j<d; j++)      {
            if(j==0) m[i][j]=1; //La prima colonna conterrà solo 1 (caso base)
            else if(j>i) m[i][j]=0; //Per tutti i k>n avremo [n,k]=0
            else if(i==j) m[i][j]=1; //Per k=n avremo [n,k]=1 (caso limite)
            else m[i][j]=m[i-1][j-1]+m[i-1][j];
        }
    }
    //La soluzione al nostro problema sarà nella cella [n,k]
    return m[n][k];
}

//Calcolo dei tempi per ogni 0<N<=30 e 0<=K<=N
void tempi()    {
    int i, k;
    clock_t t;
	//Questo ciclo controlla N
    for(i=1; i<=30; i++)   {
		//Questo ciclo controlla tutti i K fissato N
        for(k=0; k<=i; k++)     {
			//Prima funzione
            t=clock();
            Fr(i,k);
            t=clock()-t;
            printf("\nN=%d K=%d Fr  %f",i, k, ((float)t/CLOCKS_PER_SEC));
			//Seconda funzione
            t=clock();
            Frd(i,k);
            t=clock()-t;
            printf("\nN=%d K=%d Frd  %f",i, k, ((float)t/CLOCKS_PER_SEC));
        }
    }
}

/*
n/k		0	1	2	3	4	5	6	7
	------------------------------------------------------------------
0	|	1	0	0	0	0	0	0	0
1	|	1	1	0	0	0	0	0	0
2	|	1	2	1	0	0	0	0	0
3	|	1	3	3	1	0	0	0	0
4	|	1	4	6	4	1	0	0	0
5	|	1	5	10	10	5	1	0	0
6	|	1	6	15	20	15	6	1	0
7	|	1	7	21	35	35	21	7	1
*/
