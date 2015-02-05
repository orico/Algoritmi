 #include <stdio.h>
#include <time.h>
#include <math.h>


void  main ()
{
int n, a, b, c, i;
clock_t t;
    
    
scanf("%d",&n);

c=1;
a=1;
b=1;
t=clock();
    
for(i=3; i<=n; i++)
{
c=a+b;
a=b;
b=c;
}
t=clock()-t;
printf("il valore di fib e' %d\n", c);
    
printf("ci ho messo %d clicks (%f secondi)\n", t, ((float)t)/CLOCKS_PER_SEC);

}
