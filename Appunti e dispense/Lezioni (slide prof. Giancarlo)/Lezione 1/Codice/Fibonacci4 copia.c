#include <stdio.h>
#include <time.h>
#include <math.h>

void  main ()
{
    //metodo di Fibonacci iterativo che utilizza solo tre variabili. Ovvero tiene memoria di F_(n-1) e F_(n-2) ad ogni passo
    //n è l'ordine del numero di Fibonacci che intendiamo calcolare
    //a = F_(n-2), b = F_(n-1) e c = F_n, i = variabile temporale che utilizzo nel processo iterativo per calcolare
    //il numero di Fibonacci
    int n, a, b, c, i;
    
    //input al programma
    scanf("%d",&n);
    
    //creo una variabile t che tiene conto del tempo (numero di quanti che il programma impiega per trovare la soluzione)
    clock_t t;
    t = clock();

    //inizializzo i valori secondo le condizioni iniziali della relazione di ricorrenza.
    //L'output c è settato al valore di F_1 e F_2 e possiamo direttamente uscire dal programma per n=1 o n=2
    c=1;
    a=1;
    b=1;

    //Per n>=3 calcolo F_i iterativamente
    for(i=3; i<=n; i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    
    //sottraggo t al clock per avere il numero di quanti che il programma ha impiegato
    t=clock()-t;
    
    /*stampo il valore di Fibonacci, e per avere i secondi prendo t e lo divido per la macro clock_per_sec (si veda la libreria <time.h> */
    printf("il valore di fib e' %d\n", c);
    
    printf("ci ho messo %d clicks (%f secondi)\n", t, ((float)t)/CLOCKS_PER_SEC);

}
