#include<stdio.h>

// questo programma calcola l'n-esimo numero di fibonacci con l'algoritmo fibonacci5

int main()
{
    int m[2][2],i,j,k=1,n,a[2][2];

    // MATRICE m
    m[0][0]=1;
    m[0][1]=0;
    m[1][0]=0;
    m[1][1]=1;

    printf("STAMPA MATRICE m\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
            printf("%d\t",m[i][j]);
        printf("\n");
    }

    // MATRICE a
    a[0][0]=1;
    a[0][1]=1;
    a[1][0]=1;
    a[1][1]=0;

    printf("Inserisci n: ");
    scanf("%d",&n);

    while(k<n-1)
    {
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                m[i][j]=m[i][j]*a[i][j];
        k++;
    }
    printf("\n");

    printf("STAMPA MATRICE m\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
            printf("%d\t",m[i][j]);
        printf("\n");
    }

return 0;
}
