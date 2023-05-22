#include <stdio.h>
#include <stdlib.h>
#include "pilhaBBT.h"

int main()
{
    NO *ptrP;
    inic(&ptrP);

    int opcao;
    char c;

    do
    {
        printf("\nSelecione uma das opcoes abaixo:\n\n");
        printf("1 - Empilhar novo elemento\n");
        printf("2 - Desempilhar um elemento\n");
        printf("3 - Retornar topo\n");
        printf("4 - Sair\n");
        printf("\n--> ");

        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                fflush(stdin);
                printf("\nDigite uma letra:\n");
                printf("--> ");
                scanf("%c", &c);
                push(&ptrP, c);
                break;
            case 2:
                pop(&ptrP);
                break;
            case 3:
                printf("%c\n", stacktop(ptrP));
                break;
            case 4:
                printf("Encerrando o programa . . .\n\n");
                break;
            default:
                printf("Opcao invalida!\n\n");
                break;
        }

    } while(opcao != 4);


    return 0;
}
