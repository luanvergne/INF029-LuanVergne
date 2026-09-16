#include <stdio.h>

#include "aluno.h"


int cadastrarAluno(Aluno lista_aluno[], int qtdAluno) {

    printf("-- Cadastrar Aluno --\n");

    if (qtdAluno == TAM_ALUNO) {
        printf("Lista de alunos cheia!\n");
        return qtdAluno;
    }

    int matricula;

    printf("Digite a matrícula: ");
    scanf("%d", &matricula);

    if (matricula < 0) {
        printf("Matrícula inválida!\n");
        return qtdAluno;
    }

    lista_aluno[qtdAluno].matricula = matricula;
    lista_aluno[qtdAluno].ativo = 1;

    qtdAluno++;

    printf("Aluno cadastrado com sucesso!\n");

    return qtdAluno;
}


void listarAlunos(Aluno lista_aluno[], int qtdAluno) {

    printf("-- Listar Aluno --\n");

    if (qtdAluno == 0) {
        printf("Não há alunos matriculados.\n");
        return;
    }

    for (int i = 0; i < qtdAluno; i++) {

        if (lista_aluno[i].ativo) {
            printf(
                "Matrícula ativa no momento: %d\n",
                lista_aluno[i].matricula
            );
        }
    }
}


void atualizarAluno(Aluno lista_aluno[], int qtdAluno) {

    printf("-- Atualizar Aluno --\n");

    int matricula;
    int achou = 0;

    printf("Digite a matrícula: ");
    scanf("%d", &matricula);

    if (matricula < 0) {
        printf("Matrícula inválida!\n");
        return;
    }

    for (int i = 0; i < qtdAluno; i++) {

        if (
            matricula == lista_aluno[i].matricula &&
            lista_aluno[i].ativo
        ) {

            int nova_matricula;

            printf("Digite a nova matrícula: ");
            scanf("%d", &nova_matricula);

            if (nova_matricula < 0) {
                printf("Nova matrícula inválida!\n");
                return;
            }

            lista_aluno[i].matricula = nova_matricula;

            achou = 1;

            break;
        }
    }

    if (achou) {
        printf("Aluno atualizado com sucesso!\n");
    }
    else {
        printf("Matrícula inexistente!\n");
    }
}


int excluirAluno(Aluno lista_aluno[], int qtdAluno) {

    printf("-- Excluir Aluno --\n");

    int matricula;
    int achou = 0;

    printf("Digite a matrícula: ");
    scanf("%d", &matricula);

    if (matricula < 0) {
        printf("Matrícula inválida!\n");
        return qtdAluno;
    }

    for (int i = 0; i < qtdAluno; i++) {

        if (
            matricula == lista_aluno[i].matricula &&
            lista_aluno[i].ativo
        ) {

            for (int j = i; j < qtdAluno - 1; j++) {
                lista_aluno[j] = lista_aluno[j + 1];
            }

            qtdAluno--;

            achou = 1;

            break;
        }
    }

    if (achou) {
        printf("Aluno excluído com sucesso!\n");
    }
    else {
        printf("Matrícula inexistente!\n");
    }

    return qtdAluno;
}


int menuAluno(Aluno lista_aluno[], int qtdAluno) {

    int sairAluno = 0;
    int opcaoAluno;

    while (!sairAluno) {

        printf("\n");
        printf("======== Módulo Aluno ========");

        printf("0 - Sair\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Listar Aluno\n");
        printf("3 - Atualizar Aluno\n");
        printf("4 - Excluir Aluno\n\n");

        printf("Digite a sua opção: ");
        scanf("%d", &opcaoAluno);

        printf("\n");

        switch (opcaoAluno) {

            case 0:
                sairAluno = 1;
                break;

            case 1:
                qtdAluno = cadastrarAluno(lista_aluno, qtdAluno);
                break;

            case 2:
                listarAlunos(lista_aluno, qtdAluno);
                break;

            case 3:
                atualizarAluno(lista_aluno, qtdAluno);
                break;

            case 4:
                qtdAluno = excluirAluno(lista_aluno, qtdAluno);
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    return qtdAluno;
}
