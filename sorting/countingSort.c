void counting_sort(int A[], int k, int n)
{

    int i, j;

    int B[15], C[100];

    for (i = 0; i <= k; i++)

        C[i] = 0;

    for (j = 1; j <= n; j++)

        C[A[j]] = C[A[j]] + 1;

    for (i = 1; i <= k; i++)

        C[i] = C[i] + C[i-1];

    for (j = n; j >= 1; j--)

    {

        B[C[A[j]]] = A[j];

        C[A[j]] = C[A[j]] - 1;

    }

    printf("The Sorted array is : ");

    for (i = 1; i <= n; i++)

        printf("%d ", B[i]);

}
