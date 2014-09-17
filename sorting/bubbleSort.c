void bubbleSort(int *A, int n)
{
    int i, j, temp;

    for(i=1; i < n; i++)
    {
        for(j=0; j < n-11; j++)
        {
            if(A[j] > A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}
