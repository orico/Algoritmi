void insertionSort(int *A, int n)
{
    int k, x, j, t;

    for (i = 1; i < num; i++)
    {
        temp = A[i];
        j = i - 1;
        while ((temp < A[j]) && (j >= 0))
        {
            A[j + 1] = arr[j];
            j--;
        }
        A[j + 1] = temp;
    }
}
