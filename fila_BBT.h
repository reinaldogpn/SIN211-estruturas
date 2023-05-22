typedef struct sNO
{
    /*tipo*/ info;
    struct sNO *prox;
}NO;

typedef struct sFila
{
    NO *inicio;
    NO *fim;
}FILA;

void inic(FILA *ptrF)
{
    ptrF->inicio = NULL;
    ptrF->fim = NULL;
}

NO* alocarNO()
{
    return (NO*) malloc(sizeof(NO));
}

void desalocarNO(NO *q)
{
    free(q);
}

int vazia(FILA *ptrF)
{
    if(ptrF->inicio == NULL && ptrF->fim == NULL)
        return 1; // Fila vazia!
    else
        return 0; // A fila não está vazia!
}

void enfileirar(FILA *ptrF, /*tipo*/ elem)
{
    NO *novo;
    novo = alocarNO();
    if(novo != NULL)
    {
        novo->info = elem;
        novo->prox = NULL;

        if(vazia(ptrF) == 1)
        {
            ptrF->inicio = novo;
            ptrF->fim = novo;
        }
        else
        {
            (ptrF->fim)->prox = novo;
            ptrF->fim = novo;
        }
    }
    else
        printf("\nERRO! Nao foi possivel alocar o no.\n\n");
}
