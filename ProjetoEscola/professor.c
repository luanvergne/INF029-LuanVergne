#include <stdio.h>
#include "professor.h"

Professor cadastrarProfessor() {
    Professor professor;

    printf("-- Cadastrar Professor --");

    printf("Digite a matricula: ");
    scanf("%d", &professor.matricula);

    while (professor.matricula < 0) {
        printf("Matricula invalida.\n");
        printf("Digite novamente: ");
        scanf("%d", &professor.matricula);
    }

    professor.pessoa = cadastrarPessoa();
    professor.ativo = 1;

    printf("Professor cadastrado com sucesso!\n");

    return professor;
}

Professor atualizarProfessor(Professor professor) {
    printf("-- Atualizar Professor --");

    printf("Nova matricula: ");
    scanf("%d", &professor.matricula);

    professor.pessoa = atualizarPessoa(professor.pessoa);

    printf("Professor atualizado com sucesso!\n");

    return professor;
}

void listarProfessor
   (Professor listaProfessor[],int qtdProfessor) {
    int i;

    printf("-- Lista de Professores --");

    if (qtdProfessor == 0) {
        printf("Nao ha professores cadastrados.\n");
        return;
    }

    for (i = 0; i < qtdProfessor; i++) {
        if (listaProfessor[i].ativo) {
            printf("\nMatricula: %d\n", listaProfessor[i].matricula);

            exibirPessoa(listaProfessor[i].pessoa);
        }
    }
}

int excluirProfessor(
    Professor listaProfessor[],
    int qtdProfessor
) {
    int matricula;
    int i;
    int j;

    printf("\n-- Excluir Professor --\n");

    printf("Digite a matricula: ");
    scanf("%d", &matricula);

    for (i = 0; i < qtdProfessor; i++) {

        if (listaProfessor[i].matricula == matricula &&
            listaProfessor[i].ativo) {

            for (j = i; j < qtdProfessor - 1; j++) {
                listaProfessor[j] =
                    listaProfessor[j + 1];
            }

            qtdProfessor--;

            printf("Professor excluido com sucesso!\n");

            return qtdProfessor;
        }
    }

    printf("Matricula inexistente.");

    return qtdProfessor;
}

int menuProfessor(
    Professor listaProfessor[],
    int qtdProfessor
) {
    int opcao;
    int matricula;
    int i;
    int encontrado;

    do {
        printf("\n======== Modulo Professor ========\n");
        printf("0 - Voltar\n");
        printf("1 - Cadastrar Professor\n");
        printf("2 - Listar Professores\n");
        printf("3 - Atualizar Professor\n");
        printf("4 - Excluir Professor\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 0:
                break;
            
            case 1:
                if (qtdProfessor >= TAM_PROFESSOR) {
                    printf("Lista de professores cheia.\n");
                } else {
                    listaProfessor[qtdProfessor] =
                        cadastrarProfessor();

                    qtdProfessor++;
                }
                break;

            case 2:
                listarProfessor(
                    listaProfessor,
                    qtdProfessor
                );
                break;

            case 3:
                printf("Digite a matricula: ");
                scanf("%d", &matricula);

                encontrado = 0;

                for (i = 0; i < qtdProfessor; i++) {
                    if (listaProfessor[i].matricula == matricula &&
                        listaProfessor[i].ativo) {

                        listaProfessor[i] =
                            atualizarProfessor(
                                listaProfessor[i]
                            );

                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Matricula inexistente.\n");
                }

                break;

            case 4:
                qtdProfessor =
                    excluirProfessor(
                        listaProfessor,
                        qtdProfessor
                    );
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return qtdProfessor;
}