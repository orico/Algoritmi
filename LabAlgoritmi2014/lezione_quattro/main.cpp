/*Da fare:
	- Creare la matrice per contenerei valori di backtracking e capire se serve dato che questo algoritmo è implementato senza utilizzare matrici.
	- Inserire all'interno del for nella funzione multiply il codice che permette di aggiornare i valori di backtracking.
	- Creare l'albero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <malloc.h>
#define NUM_MATRIX

struct albero
{
	int range_start;		//Inizio dell'intervallo
	int range_end;			//Fine dell'intervallo
	int divider;			//Il valore 'k' del libro
	struct albero* left;	//Figlio destro
	struct albero* right;	//Figlio sinistro
};

typedef struct albero* nodo;

//matrice che contiene i valori dei vari m_ij
int cache[1024][1024];
//matrice di backtracking
int bt[1024][1024];

//funzione che restituisce il minimo tra due numeri
int min (int a, int b)
{
	return a < b ? a : b;
}

//vettore contente le dimensioni delle matrici.
//d[0] è il numero di righe della prima matrice
//Le dimensioni della matrice i-esima sono d[i-1] * d[i]
int d[100];

//funzione multiply
int multiply(int from, int to)
{
    //nella diagonale
	if(from==to)
    {
		cache[from][to] = 0;
		return 0;
	}
    if(cache[from][to]!=-1)
    {
        return cache[from][to];
    }
    int iter,result = INT_MAX;
    //con questa variabile si capisce se ci sono stati aggiornamenti per result
	int old_result = result;
    //mette le parentesi ad ogni passo possibile e prende quello per il quale il calcolo è minimo
    for(iter=from; iter<to; iter++)
    {
        //aggiorna result ogni volta
        result = min(result,multiply(from,iter) + multiply(iter+1,to) + d[from-1]*d[iter]*d[to]);
		if(result < old_result)
		{
			old_result = result;
			bt[from][to] = iter;
		}
    }
    //Senza questa riga il tempo d'esecuzione è esponenziale perchè si rifà tutto il calcolo
	cache[from][to] = result;
    return result;
}

//funzione che costruisce l'albero
nodo make_tree(int i, int j)
{
	nodo p = (struct albero*) malloc(sizeof (struct albero));
	p->range_start = i;
	if(i < j)
    {
		p->range_end = j;
		p->divider = bt[i][j];
		p->left = make_tree(i, p->divider);
		p->right = make_tree(p->divider + 1, j);
	}
	else
	{
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

//stampa la parentesizzazione ottima per moltiplicare le matrici
void parentesizazzione(nodo tree)
{
    //se è una foglia
	if(tree->left == NULL && tree->right == NULL)
    {
		printf(" M%d ", tree->range_start);
	}
	else
	{
		printf("(");
		parentesizazzione(tree->left);
		printf("X");
		parentesizazzione(tree->right);
		printf(")");
	}
}


//Usata in fase di debug per stampare la matrice
void print_mat(int v[][1024], int n)
{
	int i, j;
	for(i = 1; i <= n; i++)
    {
		for(j = 1; j <= n; j++)
			printf("%d\t", v[i][j]);
		printf("\n");
	}
}


int main()
{
	nodo tree_head;
	//inizializzazione della cache a -1
	memset(cache, -1, sizeof(cache));
	int number_of_matrices;
	printf("inserisci il numero di matrici da moltiplicare: ");
	scanf("%d", &number_of_matrices);

	printf("inserisci le dimensioni delle matrici\n");
	scanf("%d", &d[0]);
    int iter;
	for (iter = 1; iter <= number_of_matrices; iter++)
    {
        scanf("%d", &d[iter]);
    }

	printf("il valore ottimo e' %d\n", multiply(1, number_of_matrices));
	printf("\nmatrice\n");
	print_mat(cache, number_of_matrices);

	printf("\nmatrice Trace Back\n");
	print_mat(bt, number_of_matrices);

	tree_head = make_tree(1, number_of_matrices);
	printf("\nParentesizzazione ottima: ");
	parentesizazzione(tree_head);
	printf("\n\n");

	system("PAUSE");
	return 0;
}
