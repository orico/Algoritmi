 #include<stdio.h>
#include<conio.h>
int main()
{
            int p[20],w[20],r[20];
            int n,m,i,j,u;
            float temp;
            float c[20],x[20];
clrscr();
printf("\n\tGREEDY KNAPSACK PROBLEM");
            printf("\nEnter the capacity of knapsack: ");
scanf("%d",&m);
printf("\nEnter the items available for knapsack: ");
scanf("%d",&n);
            printf("\nEnter the Profits: \n");
            for(i=0;i<n;i++)
            {
                        scanf("%d",&p[i]);
                        r[i]=i;
            }
            printf("\nEnter the weight: \n");
            for(i=0;i<n;i++)
            {
                        scanf("%d",&w[i]);
            }
            for(i=0;i<n;i++)
            {
                        c[i]= (float)p[i]/(float)w[i];

            }
            for(i=0;i<n;i++)
            {
                        for(j=0;j<i;j++)
                        {
                                    if(c[i]>c[j])
                                    {
                                                temp=c[i];
                                                c[i]=c[j];
                                                c[j]=temp;
                                                temp=r[i];
                                                r[i]=r[j];
                                                r[j]=temp;
                                    }
                        }
            }
printf("\nProfit by weight fraction\n");
            for(i=0;i<n;i++)
            {
                        printf("%f\n",c[i]);
            }
printf("\nsorted order of index\n");
            for(i=0;i<n;i++)
            {
                        printf("%d\n",r[i]+1);
            }
            for(i=0;i<n;i++)
            {
                        x[i]=0.0;
            }
            u=m;
            for(i=0;i<n;i++)
            {
                        if(w[r[i]]>u)
                        break;
                        x[i]=1.0;
                        u=u-w[r[i]];
            }
            if(i<=n)
            x[i]=(float)u/(float)w[r[i]];
printf("\nValue for Fractions: \n");
            for(i=0;i<n;i++)
            {
                        printf("X%d = %f\n",r[i]+1,x[i]);
            }
getch();
return 0;
}
