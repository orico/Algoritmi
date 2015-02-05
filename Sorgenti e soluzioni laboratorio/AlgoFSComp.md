# Prova compito d’esame

## ESERCIZIO 1
### Utilizzando l’algoritmo di Union-Find, senza la compressione dei cammini, effettuare le seguenti operazioni sull’insieme {1,2,...,15}. 
Si adotti la convenzione per cui Union (a,b) renda l’albero cui appartiene a sottoalbero di quello cui appartiene b.

Union (4, 7);

Union (5, 12);

Union (13, 2)

Find (4)

Union (7, 15)

Union (13, 15)

Find (15)

Union (1,2)

Union (14, 10)

Union (10, 9)

Find (10)

Union (14,6)

Union (7,9) 

Union (8,12)

Find (10)

Union (3,11)

Find (13)


## ESERCIZIO 2
### Si calcoli la complessita’ di tempo asintotica del seguente pezzo di programma in pseudocodice
```
i, j, r :integer;
r :=1
for i=1 to n
{ 
  j:=1
  while j<=i do 
  {
    r:=r*2;
    j:=j+1; 
  }
}
write (r)
```

cosa calcola questo programma?

## ESERCIZIO 3
### Descrivere brevemente l’algoritmo per il Minimum Cost Spannino Tree su un grafo non orientato pesato.
