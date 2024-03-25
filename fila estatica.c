#include<stdio.h>
#define N 3

int fila[N];

int i=N;//inicio da fila
int f=N;//fim da fila


int inserir(int x)
{
    if (i == N)
    {
        printf("\nFila vazia\n");
        i=0;
        f=0;
        fila[f] = x;
        return 1;

    }
    else if ((f+1)%N == i)
    {
        printf("\nFila cheia\n");
        return 0;
    }
    else
    {
        f = (f+1)%N;
        fila[f] = x;
        return 1;
    }   
}

int remover()
{
    if (i==N && f==N)
    {
        return 0;
    }
    else if (i==f)
    {
        i = N;
        f = N;
        return 1;
    }
    else
    {
        i = (i+1)%N;
        return 1;
    }
    
}

void print_fila()
{
    int x=i;
    if (i==N && f==N)
    {
        printf("\nFila Vazia\n");
    }
    else
    {
        x = i;
        printf("%d\n", fila[x]);
        x = (x+1)%N;
        do
        {
            printf("%d\n", fila[x]);
            x = (x+1)%N;
        } while (x!=f);
        
        printf("\n\n");
    }
    
    
}
int main()
{
    print_fila();
    inserir(10);
    print_fila();
    inserir(20);
    print_fila();
    inserir(30);
    print_fila();
    inserir(40);


    return 0;
}
