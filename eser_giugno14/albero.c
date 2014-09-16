#include<stdio.h>
#include<stdlib.h>

struct a
{
    int inf;
    struct a* sx;
    struct a* dx;
};

int* crea_vettore(FILE*,int*);
struct a* crea_albero(int *,struct a*,int,int);
void stampa_albero(struct a*);
int successor(int,struct a*);
int predecessor(int,struct a*);

int main()
{
    struct a* alb;
    int *v,size;
    FILE* fp;

    fp=fopen("file.txt","r");
    if(fp==NULL)
        printf("Errore durante l'apertura del file\n");
    else
    {
		v=crea_vettore(fp,&size);
		printf("Appo',vettore creato!\n");
        alb=crea_albero(v,alb,1,size);
        printf("\nAlbero creato!\n");
        stampa_albero(alb);
        printf("\n");
        printf("Minimo: %d\n",minimum(alb));
        printf("Massimo: %d\n",maximum(alb));
        printf("Successore di 11: %d\n",successor(11,alb));
        printf("Predecessore di 7: %d\n",predecessor(7,alb));
    }

    fclose(fp);

  return 0;
}

int* crea_vettore(FILE* fp,int *size)
{
    int x,i=0,*v;
    while(fscanf(fp,"%d",&x) != EOF)
    {
        if(i==0)
        {
			printf("%d --> %d\n",i,x);
			*size=x;
			v=malloc(*size*sizeof(int));
        }
        else
        {
			printf("%d %d\n",i,x);
            v[i-1]=x;
        }
        i++;
    }
    for(i=0;i<*size;i++)printf("%d ",v[i]);
    return v;
}

struct a* crea_albero(int *v,struct a* alb,int i,int size)
{
	if(i<=size){
		if(v[i-1]==0){
			alb=NULL;
		}else{
			alb=malloc(sizeof(struct a*));
			alb->inf=v[i-1];
			alb->sx=crea_albero(v,alb->sx,2*i,size);
			alb->dx=crea_albero(v,alb->dx,2*i+1,size);
		}
	}else{
		alb=NULL;
	}
	return alb;
}

void stampa_albero(struct a* alb){
	if(alb!=NULL){
		printf("%d ",alb->inf);
		stampa_albero(alb->sx);
		stampa_albero(alb->dx);
		printf("\n");
	}else{
		printf("* ");
	}
}

int minimum(struct a* alb){
	if(alb->sx==NULL){
		return alb->inf;
	}else{
		return minimum(alb->sx);
	}
}

int maximum(struct a* alb){
	if(alb->dx==NULL){
		return alb->inf;
	}else{
		return maximum(alb->dx);
	}
}

int successor(int x,struct a* alb){
	if(alb!=NULL){
		//printf("%d - ",alb->inf);
		if(alb->inf>x){
			if(alb->sx!=NULL){
				if(alb->sx->inf>x){
					return successor(x,alb->sx);
				}else{
					return alb->inf;
				}
			}else{
				return alb->inf;
			}
		}else{
			if(alb->dx!=NULL){
				return successor(x,alb->dx);
			}
		}
	}
}

int predecessor(int x,struct a* alb){
	if(alb!=NULL){
		//printf("%d - ",alb->inf);
		if(alb->inf<x){
			if(alb->dx!=NULL){
				if(alb->dx->inf<x){
					return predecessor(x,alb->dx);
				}else{
					return alb->inf;
				}
			}else{
				return alb->inf;
			}
		}else{
			if(alb->sx!=NULL){
				return predecessor(x,alb->sx);
			}
		}
	}
}
