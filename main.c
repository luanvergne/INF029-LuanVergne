#include <stdio.h>

#include "aluno.h"


int main(void) {

    Aluno lista_aluno[TAM_ALUNO];

    int qtdAluno = 0;
    int sair = 0;
    int opcao;

    while (!sair) {

        printf("\n");
        printf("======== Projeto Escola ========\n\n");

        printf("0 - Sair\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n\n");

        printf("Digite a sua opção: ");
        scanf("%d", &opcao);

        printf("\n");

        switch (opcao) {

            case 0:
                sair = 1;
                break;

            case 1:
                qtdAluno = menuAluno(lista_aluno, qtdAluno);
                break;

            case 2:
                printf("======== Módulo Professor ========\n");
                break;

            case 3:
                printf("======== Módulo Disciplina ========\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    printf("Programa encerrado.\n");

    return 0;
}
