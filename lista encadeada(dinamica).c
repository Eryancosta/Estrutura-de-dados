#include <stdio.h>
#include <stdlib.h>

//estruturas  -->> bom seria ter um ponteiro para o no anterior e posterior em vez de apenas o posterior
typedef struct{
    int chave;
    struct NO *prox;
}NO;


//busca

NO *busca(NO *lista, int chave, NO **ant);
int inserir(int chave, NO **lista);
void print_lista(NO *lista);
int remocao(NO **lista, int chave);

int main()
{
    NO *lista = NULL;

    puts("\nInicio, verificacao de lista: \n");
    print_lista(lista);

    puts("\nInsercao");
    inserir(10, &lista);
    inserir(5, &lista);
    print_lista(lista);

    puts("\nremocao");
    remocao(&lista, 10);
    print_lista(lista);

    return 0;
}

//inserção
int inserir(int chave, NO **lista)
{
    NO *aux_i = *lista, *nova, *ant;
    aux_i = busca(*lista, chave, &ant);

    if (aux_i == NULL)
    {
        nova = (NO *)malloc(sizeof(NO));
        nova->chave = chave;
        nova->prox = *lista;
        *lista = nova;
        return 1;
    }
    else
    {
        printf("\nChave ja inserida\n");
        return 0;
    }
    
}

//print lista
void print_lista(NO *lista)
{
    NO *aux = lista;

    if (aux == NULL)
    {
       printf("\nLista Vazia");
    }
    else
    {
        while (aux != NULL)
        {
            printf("\n%d", aux->chave);
            aux = aux->prox;
        }    
    }  
}

//busca
NO *busca(NO *lista, int chave, NO **ant)
{
    NO *aux = NULL;

    aux = lista; //fazer aux apontar para o 1º elemento da lista
    *ant = NULL;

    while (aux !=NULL && aux->chave != chave)
    {
        *ant = aux;
        aux = aux->prox; //fazer apontar para o proximo elemento da lista
    }

    if (aux == NULL)
    {
        printf("\nElemento %d nao consta na lista\n", chave);
        return NULL;
    }
    else
        printf("\nElemento ja consta na lista");
        
}

//remoção
int remocao(NO **lista, int chave)
{
    NO *aux, *ant;

    aux = busca(*lista, chave, &ant);

    if (aux == NULL) // chave não encontrada
        return 0;
    else if (ant == NULL) // remoção do 1º nó
    {
        *lista = aux->prox;
        free(aux);
        return 1;
    }
    else
    {
        ant->prox = aux->prox;
        free(aux);
        return 1;
    }

    
    
}