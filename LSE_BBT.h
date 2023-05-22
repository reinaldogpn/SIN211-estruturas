#include <stdio.h>
#include <stdlib.h>

typedef struct sNO
{
    int info;
    struct sNO *prox;
}NO;

NO* inic(NO *lista)
{
    lista = NULL;
    return lista;
}

/* FUNÇÃO COM PONTEIRO PARA PONTEIRO;
void inic(NO **lista)
{
    *lista = NULL;
}
*/

NO* alocarNo()
{
    return (NO*) malloc(sizeof(NO));
}

void desalocarNo(NO *q)
{
    free(q);
}

int vazia(NO *lista)
{
    if(lista == NULL)
        return 1;
    else
        return 0;
}

/* FUNÇÃO COM PONTEIRO PARA PONTEIRO;
int vazia(NO **lista)
{
    if(*lista == NULL)
        return 1;
    else
        return 0;
}
*/

NO* inserir_inicio(NO *lista, int elem)
{
    NO *novo;
    novo = alocarNo();

    if(novo != NULL)
    {
        novo->info = elem;
        novo->prox = lista;

        lista = novo;

        return lista;
    }
    else
    {
        printf("\nERRO! Falha na alocacao do no.\n");
        return NULL;
    }
}

/* FUNÇÃO COM PONTEIRO PARA PONTEIRO;
void inserir_inicio(NO **lista, int elem)
{
    NO *novo;
    novo = alocarNo();

    if(novo != NULL)
    {
        novo->info = elem;
        novo->prox = *lista;
        *lista = novo;
    }
    else
        printf("\nERRO! Falha na alocacao do no.\n");
}
*/

NO* inserir_fim(NO *lista, int elem)
{
    NO *novo;
    NO *aux;

    novo = alocarNo();

    if(novo != NULL)
    {
        novo->info = elem;
        novo->prox = NULL;

        if(vazia(lista))
            lista = novo;
        else
        {
            aux = lista;

            while(aux->prox != NULL)
                aux = aux->prox;

            aux->prox = novo;
        }
        return lista;
    }
    else
    {
        printf("\nERRO! Falha na alocacao do no.\n");
        return NULL;
    }
}

/* FUNÇÃO COM PONTEIRO PARA PONTEIRO;
void inserir_fim(NO **lista, int elem)
{
    NO *novo;
    NO *aux;

    novo = alocarNo();

    if(novo != NULL)
    {
        novo->info = elem;
        novo->prox = NULL;

        if(vazia(*lista))
            *lista = novo;
        else
        {
            aux = *lista;

            while(aux->prox != NULL)
                aux = aux->prox;

            aux->prox = novo;
        }
    }
}
*/

NO* remover_inicio(NO *lista)
{
    NO *q;
    q = lista;

    if(!vazia(lista))
    {
        lista = q->prox;
        desalocarNo(q);
        return lista;
    }
    else
    {
        printf("\nERRO! Lista vazia.\n");
        return NULL;
    }
}

/* FUNÇÃO COM PONTEIRO PARA PONTEIRO;
void remover_inicio(NO **lista)
{
    NO *q;
    q = *lista;

    if(!vazia(*lista))
    {
        *lista = q->prox;
        desalocarNo(q);
    }
}
*/

NO* pesquisar(NO *lista, int elem)
{
    NO *aux;
    aux = lista;

    if(!vazia(lista))
    {
        while(aux != NULL)
        {
            if(aux->info == elem)
                return aux;

            aux = aux->prox;
        }
    }
    printf("\nERRO! Elemento nao encontrado.\n");
    return NULL;
}

NO* remover_valor(NO *lista, int elem)
{
    NO *q;
    NO *aux;

    if((q = pesquisar(lista, elem)) != NULL)
    {
        aux = lista;

        if(aux == q)
            remover_inicio(lista);
        else
        {
            while(aux->prox != q)
                aux = aux->prox;

            aux->prox = q->prox;
            desalocarNo(q);
        }
        return lista;
    }
    printf("\nERRO! Elemento nao removido.\n");
    return NULL;
}

/* FUNÇÃO COM PONTEIRO PARA PONTEIRO;
void remover_valor(NO **lista, int elem)
{
    NO *q;
    NO *aux;

    if((q = pesquisar(*lista, elem)) != NULL)
    {
        aux = *lista;

        if(aux == q)
            remover_inicio(lista);
        else
        {
            while(aux->prox != q)
                aux = aux->prox;

            aux->prox = q->prox;
            desalocarNo(q);
        }
    }
    else
        printf("\nERRO! Elemento nao removido.\n");
}
*/

void contagem(NO **lista, int elem)
{
    NO *q;
    NO *aux;

    if((q = pesquisar(*lista, elem)) != NULL)
    {
        aux = *lista;

        if(aux == q)
        {
            printf("\nElemento ja está no inicio da lista.\n");
            q->cont = (q->cont)+1;
        }
        else
        {
            while(aux->prox != q)
                aux = aux->prox;

            aux->prox = q->prox;
            q->cont = (q->cont)+1;
            aux = *lista;

            if(q->cont > aux->cont)
            {
                q->prox = aux;
                *lista = q;
            }
            else
            {
                // continuar ...
            }
        }
    }
}
