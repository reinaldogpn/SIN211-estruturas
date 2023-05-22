#include <stdio.h>
#include <stdlib.h>

typedef struct s/*tipo*/
{
    /*info*/

} /*tipo*/;

typedef struct sNo
{
    /*tipo*/ info;
    int fb;
    struct sNo *esq;
    struct sNo *dir;
} NO;

void inicializar(NO **raiz)
{
    *raiz = NULL;
}

NO *alocarNO()
{
    return (NO *)malloc(sizeof(NO));
}

void desalocarNO(NO *q)
{
    free(q);
}

void avl_RotEsqDir(NO **raiz)
{
    NO *fE;
    NO *ffD;
    fE = (*raiz)->esq;
    ffD = fE->dir;

    fE->dir = ffD->esq;
    ffD->esq = fE;

    (*raiz)->esq = ffD->dir;
    ffD->dir = *raiz;

    if (ffD->fb == +1)
        (*raiz)->fb = -1;
    else
        (*raiz)->fb = 0;

    if (ffD->fb == -1)
        fE->fb = +1;
    else
        fE->fb = 0;

    *raiz = ffD;

    printf("\n*** Rotacao dupla esquerda-direita realizada.\n\n");
}

void avl_RotDirEsq(NO **raiz)
{
    NO *fD;
    NO *ffE;
    fD = (*raiz)->dir;
    ffE = fD->esq;

    fD->esq = ffE->dir;
    ffE->dir = fD;

    (*raiz)->dir = ffE->esq;
    ffE->esq = *raiz;

    if (ffE->fb == +1)
        (*raiz)->fb = -1;
    else
        (*raiz)->fb = 0;

    if (ffE->fb == -1)
        fD->fb = +1;
    else
        fD->fb = 0;

    *raiz = ffE;

    printf("\n*** Rotacao dupla direita-esquerda realizada.\n\n");
}

void avl_RotDir(NO **raiz)
{
    NO *aux;
    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = *raiz;
    (*raiz)->fb = 0;
    *raiz = aux;

    printf("\n*** Rotacao simples a direita realizada.\n\n");
}

void avl_RotEsq(NO **raiz)
{
    NO *aux;
    aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = *raiz;
    (*raiz)->fb = 0;
    *raiz = aux;

    printf("\n*** Rotacao simples a esquerda realizada.\n\n");
}

void avl_Aux1(NO **raiz)
{
    NO *fE;
    fE = (*raiz)->esq;

    if (fE->fb == +1)
        avl_RotDir(&(*raiz));
    else
        avl_RotEsqDir(&(*raiz));
    (*raiz)->fb = 0;
}

void avl_Aux2(NO **raiz)
{
    NO *fD;
    fD = (*raiz)->dir;
    if (fD->fb == -1)
        avl_RotEsq(&(*raiz));
    else
        avl_RotDirEsq(&(*raiz));

    (*raiz)->fb = 0;
}

int avl_inserir(NO **raiz, /*tipo*/ elem)
{
    int ok;

    if (*raiz == NULL)
    {
        *raiz = alocarNO();
        if (*raiz == NULL)
        {
            printf("ERRO! Problema na alocacao de memoria.\n\n");
            return 0;
        }

        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        (*raiz)->info = elem;
        (*raiz)->fb = 0;

        return 1;
    }

    if (elem./*info*/ < (*raiz)->info./*info*/)
    {
        ok = avl_inserir(&(*raiz)->esq, elem);

        if (ok)
        {
            switch ((*raiz)->fb)
            {
            case -1:
                (*raiz)->fb = 0;
                ok = 0;
                break;
            case 0:
                (*raiz)->fb = +1;
                break;
            case 1:
                avl_Aux1(&(*raiz));
                ok = 0;
                break;
            case 2:
                break;
            case 3:
                break;
            }
        }
    }
    else if (elem./*info*/ > (*raiz)->info./*info*/)
    {
        ok = avl_inserir(&(*raiz)->dir, elem);

        if (ok)
        {
            switch ((*raiz)->fb)
            {
            case +1:
                (*raiz)->fb = 0;
                break;
            case 0:
                (*raiz)->fb = -1;
                break;
            case -1:
                avl_Aux2(&(*raiz));
                ok = 0;
                break;
            }
        }
    }
    else
    {
        ok = 0;
    }

    return ok;
}

void em_ordem(NO *raiz)
{
    if (raiz != NULL)
    {
        em_ordem(raiz->esq);
        /*imprimir*/
        em_ordem(raiz->dir);
    }
}

void pos_ordem(NO *raiz)
{
    if (raiz != NULL)
    {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        /*imprimir*/
    }
}