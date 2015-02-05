#include <stdio.h>
#include <malloc.h>
#include <time.h>

int LCS(int *, int *, int, int);
int massimo(int **, int *, int, int);
void StampaMatrice(int **, int, int);
void StampaSottoSequenza(int **, int *, int, int, int);
int CercaIndice(int **, int, int, int);

int main(){

  int *X;
  int *Y;
  int dim_x, dim_y;
  int i;

  printf("Inserire dimensione array x: ");
  scanf("%d", &dim_x);

  printf("Inserire dimensione array y: ");
  scanf("%d", &dim_y);

  X = malloc(dim_x * sizeof(int));
  Y = malloc(dim_y * sizeof(int));

  srand(time(NULL));
  for(i = 0; i < dim_x; i++){
    X[i] = rand() % 10;
    printf("%d\t", X[i]);
    /*printf("X[%d]: ", i);
    scanf("%d", &X[i]);*/
  }

  printf("\n");

  for(i = 0; i < dim_y; i++){
    Y[i] = rand() % 10;
    printf("%d\t", Y[i]);
    /*printf("Y[%d]: ", i);
    scanf("%d", &Y[i]);*/
  }

  printf("\n\n");

  printf("La lunghezza della piu' lunga sottosequenza comune crescente e': %d\n", LCS(X, Y, dim_x, dim_y));

  return 0;
}

int LCS(int *X, int *Y, int dim_x, int dim_y){

  int **C;
  int i, j;
  int max_C = 0;

  C = malloc(dim_x * sizeof(int *));
  for(i = 0; i < dim_x; i++)
    C[i] = malloc(dim_y *sizeof(int));

  for(i = 0; i < dim_x; i++)
    for(j = 0; j < dim_y; j++){
      if(X[i] != Y[j]) C[i][j] = 0;
      else{
        C[i][j] = 1 + massimo(C, X, i, j);
        if(C[i][j] > max_C) max_C = C[i][j];
      }
    }

  StampaSottoSequenza(C, X, max_C, dim_x, dim_y);

  return max_C;
}

int massimo(int **C, int *X, int i, int j){
  int s, t;
  int aux = 0;

  for(s = 0; s < i; s++){
    if(X[s] < X[i])
      for(t = 0; t < j; t++)
        if(C[s][t] > aux) aux = C[s][t];
  }

  return aux;
}

void StampaMatrice(int **c, int n, int m){

  int i, j;
  for(i=0;i<n;i++){
    printf("\n");
    for(j=0;j<m;j++)
      printf("%d\t", c[i][j]);
  }

  printf("\n\n");
}

void StampaSottoSequenza(int **C, int *X, int max_C, int dim_x, int dim_y){

  int *A;
  int i;
  int indice;

  A = malloc(max_C * sizeof(int));

  for(i = max_C; i > 0; i--){
    //cerca il primo i in C e ritorna un indice
    indice = CercaIndice(C, i, dim_x, dim_y);

    if(i == max_C) A[i - 1] = X[indice];
    else if(X[indice] < A[i]) A[i - 1] = X[indice];
  }

  printf("La piu' lunga sottosequenza e' formata dagli elementi\t");
  for(i = 0; i < max_C; i++)
    printf("%d\t", A[i]);

  printf("\n");
}

int CercaIndice(int **C, int max_C, int dim_x, int dim_y){

  int i, j;

  for(i = 0; i < dim_x; i++)
    for(j = 0; j < dim_y; j++)
      if(C[i][j] == max_C) return i;
}
