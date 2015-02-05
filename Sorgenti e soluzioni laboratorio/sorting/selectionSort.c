void selectionSort(int *A, int n)
{
    int k=0, m, j, temp;

    for ( c = 0 ; c < ( n - 1 ) ; c++ )
   {
       position = c;

      for ( d = c + 1 ; d < n ; d++ )
      {
         if( A[position] > A[d] )
             position = d;
      }
      if ( position != c )
      {
         swap = A[c];
         A[c] = A[position];
         A[position] = swap;
      }
   }
}
