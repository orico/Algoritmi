#include <stdio.h>

//unsigned int v[6] = { 1, 10, 15, 12, 19, 23 };

unsigned int v[2] = { 1, 10 };

/*
int binsearch(int *v,int l,int r, int val)
{
 int i = (l+r)/2;

 if (val==v[i]) return i;
 else
	 if (l==r) return -1;
	 else 
		 if (val > v[i]) return(binsearch(v,i+1,r,val));
			 else return(binsearch(v,l,i-1,val));
}*/


int *binsearch(int *v,int n, int val)
{
 if ((n<=1) || (val==v[n/2]) ) return (&v[n/2]);
 else 
 if (val > v[n/2]) return(binsearch(&v[(n/2)+1],(n/2)-1,val));
  else return(binsearch(v,n/2,val));
}


int main()
{
  int key=10;
  int n = 2;

  int *a = binsearch (v,n,key);
  if (*a==key)
    printf("Il numero e in pos: %d\n",a-v);
  else printf("Numero non trovato\n");
}