#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n,i,j,k;
    int max=0;
    int **scatole;
    int *z;

    srand(time(NULL));

    printf("Inserisci numero di scatole: ");
    scanf("%d",&n);

    z=(int*)malloc(n*sizeof(int));

    scatole=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        scatole[i]=(int*)malloc(3*sizeof(int));
        z[i]=1;
    }

    // generazione scatole
    for(i=0;i<n;i++)
    {
        printf("SCATOLA %d:\n",i+1);
        printf("Altezza, larghezza e lunghezza: ");
        scanf("%d %d %d",&scatole[i][1],&scatole[i][2],&scatole[i][3]);
        printf("\tAltezza: %d\n",scatole[i][1]);
        printf("\tLarghezza: %d\n",scatole[i][2]);
        printf("\tLunghezza: %d\n",scatole[i][3]);
    }

    // questo ciclo fa la scansione di ogni scatola dalla prima all'ultima
    for(i=0;i<n;i++)
    {
        // la variabile k ci serve da contatore per gestire le sequenze
        k=1;

        // la variabile j ci serve per confrontare ad ogni ciclo la scatole con quella
        // successiva
        j=0;

        for(j=i;j<n-1;j++)
        {
            // confronto la scatola con la successiva
            if(scatole[j][1]<scatole[j+1][1] && scatole[j][2]<scatole[j+1][2] && scatole[j][3]<scatole[j+1][3])
            {
                printf("\n %d Scatola %d < Scatola %d\n",i,j,j+1);
                // dato che la scatola è più piccola della successiva incrementa k
                k++;
            }
            else
                j=n; // questa istruzione ci serve per poi uscire dal ciclo in quanto
                     // la catena della sequenze si rompe
        }
        // trovata la massima sequenza al passi i scrivo in z il valore della
        // grandezza della sequenza k
        z[i]=k;
    }
    // stampo vettore z
    printf("\nVETTORE z\n");
    for(i=0;i<n;i++)
        printf("%d ",z[i]);

    // calcolo della sequenza massima
    for(i=0;i<n;i++)
    {
        if(z[i]>max)
            max=z[i];
    }
    printf("La massima sequenza è %d\n",max);

  return 0;
}
