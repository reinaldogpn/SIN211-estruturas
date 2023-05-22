typedef struct sNO
{
    /*tipo*/ info;
    struct sNO *prox;
}NO;

void inic(NO **topo) // na main: NO *ptrP; inic(&ptrP);
{
    *topo = NULL;
}

NO* alocarNO()
{
    return (NO*) malloc(sizeof(NO));
}

void desalocarNO(NO *q)
{
    free(q);
}

int vazia(NO *topo)
{
    if(topo == NULL)
        return 1;
    else
        return 0;
}

void push(NO **topo, /*tipo*/ elem)
{
    NO *novo;
    novo = alocarNO();

    if(novo != NULL)
    {
        novo->info = elem;
        novo->prox = *topo;
        *topo = novo;
        printf("**Elemento empilhado com sucesso!**\n\n");
    }
    else
        printf("\nERRO! Nao foi possivel alocar o no.\n");
}

/*tipo*/ pop(NO **topo)
{
    if(!vazia(*topo))
    {
        /*tipo*/ elem;
        NO* aux;
        aux = *topo;
        *topo = aux->prox;

        elem = aux->info;

        desalocarNO(aux);
        return elem;
    }
    else
        printf("\nPilha vazia!\n\n");
}

/*tipo*/ stacktop(NO *topo)
{
    if(vazia(topo))
    {
        printf("ERRO! pilha vazia.\n");
        return -1;
    }
    return topo->info;
}

void impressaoNaoClassica(NO *topo) // Imprime sem desempilhar
{
    if(!vazia(topo))
    {
        NO *aux;
        aux = topo;
        while(aux != NULL)
        {
            /* imprimir elementos */
            aux = aux->prox;
        }
    }
    else
        printf("ERRO! Pilha vazia!\n\n");
}

void impressaoClassica(NO *topo) // Imprime desempilhando
{
    if(!vazia(topo))
    {
        NO *aux;
        while(aux != NULL)
        {
            aux = topo;
            /* imprimir elementos usando o ponteiro aux */
            topo = aux->prox;
            desalocarNO(aux);
        }
        printf("\n");
    }
    else
        printf("ERRO! Pilha vazia!\n\n");
}
