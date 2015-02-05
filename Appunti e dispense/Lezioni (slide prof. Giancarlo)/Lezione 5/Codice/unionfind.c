/* Copyright (c) 2013 the authors listed at the following URL, and/or
 2 the authors of referenced articles or incorporated external code:
 3 http://en.literateprograms.org/Disjoint_set_data_structure_(C)?action=history&offset=20120929194600
 4 
 5 Permission is hereby granted, free of charge, to any person obtaining
 6 a copy of this software and associated documentation files (the
 7 "Software"), to deal in the Software without restriction, including
 8 without limitation the rights to use, copy, modify, merge, publish,
 9 distribute, sublicense, and/or sell copies of the Software, and to
10 permit persons to whom the Software is furnished to do so, subject to
11 the following conditions:
12 
13 The above copyright notice and this permission notice shall be
14 included in all copies or substantial portions of the Software.
15 
16 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
17 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
18 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
19 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY20 CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Retrieved from: http://en.literateprograms.org/Disjoint_set_data_structure_(C)?oldid=18651
*/

#include <stdlib.h>
#include <stdio.h>
#include "union_find.h"

int main() {
    int n;		//Numero di insiemi da creare
	int i, x;	//x conterrà il valore di un elemento inserito prima di creare l'insieme corrispondente
    forest f;

	/*Creazione della foresta*/
	printf("Numero di insiemi da creare: ");
	scanf("%d", &n);
	Make_Forest(&f, n);

	//Inizializzazione
	for(i = 0; i < n; i++){
		printf("Inserisci elemento: ");
		scanf("%d", &x);
		MakeSet(&f, &x);
	}

	system("pause");

    return 0;
}