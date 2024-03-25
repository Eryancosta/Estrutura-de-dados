#include<stdio.h>

int L[10] = {5,2,1,3,5,4,8,5,2,3};
int nr_ele = 3;

int busca(int chave)
{
    int i = 0;
    while (L[i]!= chave && i<nr_ele)
    {
        i++;
    }
    return i;    
}

int inserir(int chave)
{
    int z;
    z = busca(chave);
    if (z == 10)
    {
        return 0; //lista cheia
    }
    else if (z < nr_ele)
    {
        return 2; // elemento presente, já existente
    }
    else
    {
        L[z] = chave;
        nr_ele ++;
    }
    
    
    
}

int main()
{
    int z;
    
    z = inserir(10);
    z = busca(10);
    printf("%d", z);
    
    return 0;
}
