#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 300
void Merge(int *,int,int,int);
void mergesort(int *,int,int);
int contaConsecutivi(int *,int,int);
void stampa_array(int V[],int);
int main()
{
    int V[MAX];
    int n,i,consecutivi;
    printf("Inserisci grandezza vettore:\n");
    scanf("%d",&n);
//    V=(int *)malloc(sizeof(int)*n);
//    srand(time(NULL));
    for(i=0;i<n;i++){
        printf("V[%d]: ", i);
        scanf("%d", &V[i]);
    }
    mergesort(V,0,n-1);
    consecutivi=contaConsecutivi(V,0,n-1);
    stampa_array(V,n);
    printf("\nCOPPIE=:%d",consecutivi);
}
int contaConsecutivi(int *A, int low, int high)
{
    if(low == high)
        return 0;
    if(low == high-1)
    {
        if(A[low] == A[high]-1)
            return 1;
        else
            return 0;
    }
    else
    {
        int middle = (low+high)/2;
        int consecutivi = contaConsecutivi(A,low, middle) + contaConsecutivi(A,middle+1, high);

        if(A[middle] == A[middle+1]-1)
            consecutivi = consecutivi+1;
            return consecutivi;
    }
}
void Merge(int A[], int p, int q, int r) {
  int i, j, k, B[MAX];

  i = p;
  j = q+1;
  k = 0;
  while (i<=q && j<=r) {
    if (A[i]<A[j]) {
      B[k] = A[i];
      i++;
    } else {
      B[k] = A[j];
      j++;
    }
    k++;
  }
  while (i<=q) {
    B[k] = A[i];
    i++;
    k++;
  }
  while (j<=r) {
    B[k] = A[j];
    j++;
    k++;
  }
  for (k=p; k<=r; k++)
    A[k] = B[k-p];


  return;
}


/*
 *  Funzione ricorsiva MergeSort.
 */

void mergesort(int A[], int p, int r) {
  int q;

  if (p<r) {
    q = (p+r)/2;
    mergesort(A, p, q);
    mergesort(A, q+1, r);
    Merge(A, p, q, r);
  }
  return;
}

void stampa_array(int V[], int n) {
  int i;

  for (i=0; i<n; i++) {
    printf("%d ", V[i]);
  }
  printf("\n");
  return;
}
