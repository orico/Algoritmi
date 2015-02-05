Sia una sequenza `A={a0 ,…, ap-1 , ap  ,ap+1 ,…,an-1}` di `n` numeri, non necessariamente interi, tale che

1. Per  ogni  `i <> j`   con   `0 <= i, j < n`  allora `ai <> aj`
2. Esiste un indice `p` detto picco, `1 < p < n-1`, tale che per ogni `i`,`j`,`k`,`l` con `0 <= i < j < p` e `p > k > l >= n` allora `ai < aj < ap` e `ap > ak > al`
3. Si richiede di implementare in linguaggio C un algoritmo che data la sequenza A, trovi il picco p effettuando nel caso pessimo `O(log n)` confronti tra numeri.
4. Si preveda che l’algoritmo possa leggere la sequenza A da un file binario che memorizza come primo elemento n(come intero) e a seguire i valori di A come double.
5. Commentare opportunamente il codice implementato.
