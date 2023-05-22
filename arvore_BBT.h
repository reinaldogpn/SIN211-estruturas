#include <stdio.h>
#include <stdlib.h>

typedef struct sNo
{
    /*tipo*/ info;
    struct sNO *esq;
    struct sNO *dir;
}NO;

typedef struct //sArvore ou ABP
{
    NO *ptRaiz;
}//Deque ou ABP;

void inicializar(NO **raiz)
{
    *raiz = NULL;
}

NO* alocarNO()
{
    return (NO*) malloc(sizeof(NO));
}

void desalocarNO(NO *raiz)
{
    free(raiz);
}

void imprimir(NO* raiz)
{
    printf(%/*tipo*/, raiz->info);
}

void pre_ordem(NO* raiz)
{
    if(raiz != NULL)
    {
        imprimir(raiz);
        pos_ordem(raiz->esq);
        pos_ordem(raiz->esq);
    }
}

void em_ordem(NO* raiz)
{
    if(raiz != NULL)
    {
        em_ordem(raiz->esq);
        imprimir(raiz);
        em_ordem(raiz->dir);
    }
}

void pos_ordem(NO* raiz)
{
    if(raiz != NULL)
    {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->esq);
        imprimir(raiz);
    }
}

// OPERAÇÕES PARA ABP

NO* pesquisar(NO** raiz, /*tipo*/ elem)
{
    NO* aux;
    aux = raiz;

    if(aux == NULL)
        return NULL;
    else if(elem < aux->info)
        return pesquisar(aux->esq, elem);
    else if(elem > aux->info)
        return pesquisar(aux->dir, elem);
    else
        return aux;
}

void inserir(NO **raiz, /*tipo*/ elem)
{
    NO *aux = *raiz;
    NO *aux2 = NULL;

    NO *novo = alocarNO();
    if(novo == NULL) {
        printf("ERRO! Problema na alocacao!\n");
        return;
    }

    novo->info = elem;
    novo->esq = NULL;
    novo->dir = NULL;

    while(aux != NULL)
    {
        aux2 = aux;
        if(elem./*campo*/ < aux->/*tipo*/./*campo*/)
            aux = aux->esq;
        else
            aux = aux->dir;
    }

    if(aux2 == NULL)
        *raiz = novo;
    else
    {
        if(elem./*campo*/ < aux2->info./*campo*/)
            aux2->esq = novo;
        else
            aux2->dir = novo;
    }
    printf("\n** Aluno inserido com sucesso! **\n\n");
}

NO* remover(NO* raiz, char elem)
{
    if(raiz == NULL)
        return NULL;
    else if(raiz->info > elem)
        raiz->esq = remover(raiz->esq, elem);
    else if(raiz->info < elem)
        raiz->dir = remover(raiz->dir, elem);
    else
    {
        if(raiz->esq == NULL && raiz->dir == NULL)
        {
            desalocarNO(raiz);
            raiz = NULL;
        }
        else if(raiz->esq == NULL)
        {
            NO* temp = raiz;
            raiz = raiz->dir;
            desalocarNO(temp);
        }
        else if(raiz->dir == NULL)
        {
            NO* temp = raiz;
            raiz = raiz->esq;
            desalocarNO(temp);
        }
        else
        {
            NO* pai = raiz;
            NO* f = raiz->esq;

            while(f->dir != NULL)
            {
                pai = f;
                f = f->dir;
            }
            raiz->info = f->info;
            f->info = elem;
            raiz->esq = remover(raiz->esq, elem);
        }
    }
    printf("\n** Elemento removido com sucesso! **\n\n");
    return raiz;
}

int calcularElementos(NO* raiz)
{
    if(raiz != NULL)
    {
        int elemDir = calcularElementos(raiz->dir);
        int elemEsq = calcularElementos(raiz->esq);
        int soma = (elemDir + elemEsq) +1;
        return soma;
    }
}
