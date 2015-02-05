/*
 *  Funzione Merge per la fusione di due
 *  componenti ordinate dell'array.
 */

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

void MergeSort(int A[], int p, int r) {
  int q;

  if (p<r) {
    q = (p+r)/2;
    MergeSort(A, p, q);
    MergeSort(A, q+1, r);
    Merge(A, p, q, r);
  }
  return;
}

int main()
{
 MergeSort(V, 0, n-1);
}
