#include <stdio.h>
#include <locale.h>
#define TAML 26

typedef struct sLista
{
    char letras[TAML];
    int n;
} LISTA;

void lista_inicializar(LISTA *ptrL)
{
    ptrL->n = -1;
}

int lista_cheia(LISTA *ptrL)
{
    if(ptrL->n+1 == TAML)
        return 1;
    else
        return 0;
}

int lista_vazia(LISTA *ptrL)
{
    if(ptrL->n == -1)
        return 1;
    else
        return 0;
}

int lista_inserirFim(LISTA *ptrL, char elem)
{
    if (lista_cheia(ptrL))
    {
        printf("ERRO! Lista cheia.");
        return 1;
    }
    ptrL->n = ptrL->n+1;
    ptrL->letras[ptrL->n] = elem;
    return 0;
}

int lista_inserir(LISTA* ptrL, int k, char elem)
{
    if(lista_cheia(ptrL))
    {
        printf("ERRO! Lista cheia.");
        return 1;
    }

    if(k < 0 || k > ptrL->n+1)
    {
        printf("ERRO! Posição inválida.");
        return 1;
    }

    for(int i=(ptrL->n+1); i>k; i--)
    {
        ptrL->letras[i] = ptrL->letras[i-1];
    }

    ptrL->letras[k] = elem;
    ptrL->n = ptrL->n+1;
    return 0;
}

int lista_modificar(LISTA *ptrL, int k, char elem)
{
    if(k < 0 || k > ptrL->n+1)
    {
        printf("ERRO! Posição inválida.");
        return 1;
    }

    ptrL->letras[k] = elem;
    return 0;
}

int lista_exibirElem(LISTA *ptrL, int k)
{
    if(lista_vazia(ptrL))
    {
        printf("ERRO! Lista vazia.");
        return 1;
    }
    if(k < 0 || k > ptrL->n+1)
    {
        printf("ERRO! Posição inválida.");
        return 1;
    }

    printf("%c\n", ptrL->letras[k]);
    return 0;
}

int lista_remover(LISTA *ptrL, int k)
{
    if(lista_vazia(ptrL))
    {
        printf("ERRO! Lista vazia.");
        return 1;
    }
    if(k < 0 || k > ptrL->n+1)
    {
        printf("ERRO! Posição inválida.");
        return 1;
    }

    for(int i=k; i<(ptrL->n); i++)
    {
        ptrL->letras[i] = ptrL->letras[i+1];
    }

    ptrL->n = ptrL->n-1;
    return 0;
}

int lista_pesquisar(LISTA *ptrL, char elem)
{
    if(lista_vazia(ptrL))
    {
        printf("ERRO! Lista vazia.");
        return 1;
    }

    int i = 0;

    while(i<(ptrL->n))
    {
        if(ptrL->letras[i] == elem)
            return i;
        else if(i == (ptrL->n))
            return -1;
        else
            i++;
    }
}
