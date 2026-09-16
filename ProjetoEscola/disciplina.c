#include <stdio.h>
#include "disciplina.h"

Disciplina cadastrarDisciplina() {
    Disciplina disciplina;

    disciplina.qtdAlunos = 0;
    disciplina.ativo = 1;

    printf("-- Cadastrar Disciplina --");

    printf("Nome da disciplina: ");
    scanf("%d", &disciplina.nome);

    printf("Codigo: ");
    scanf("%d", &disciplina.codigo);

    printf("Semestre: ");
    scanf("%d", &disciplina.semestre);

    printf("Matricula do professor: ");
    scanf("%d", &disciplina.matriculaProfessor);

    printf("Disciplina cadastrada com sucesso!\n");

    return disciplina;
}

Disciplina atualizarDisciplina(Disciplina disciplina) {

    printf("-- Atualizar Disciplina --");

    printf("Novo nome: ");
    scanf("%d", &disciplina.nome);

    printf("Novo codigo: ");
    scanf("%d", &disciplina.codigo);

    printf("Novo semestre: ");
    scanf("%d", &disciplina.semestre);

    printf("Nova matricula do professor: ");
    scanf("%d", &disciplina.matriculaProfessor);

    printf("Disciplina atualizada com sucesso!\n");

    return disciplina;
}

int inserirAlunoDisciplina(
    Disciplina disciplina,
    int matriculaAluno
) {
    int i;

    if (disciplina.qtdAlunos >= TAM_ALUNOS_DISCIPLINA) {
        printf("A disciplina atingiu o limite de alunos.\n");
        return 0;
    }

    for (i = 0; i < disciplina.qtdAlunos; i++) {
        if (disciplina.alunos[i] == matriculaAluno) {
            printf("Aluno ja esta matriculado na disciplina.\n");
            return 0;
        }
    }

    disciplina.alunos[disciplina.qtdAlunos] =
        matriculaAluno;

    disciplina.qtdAlunos++;

    printf("Aluno inserido na disciplina.\n");

    return 1;
}

int removerAlunoDisciplina(Disciplina disciplina, int matriculaAluno) {
    int i;
    int j;

    for (i = 0; i < disciplina.qtdAlunos; i++) {

        if (disciplina.alunos[i] == matriculaAluno) {

            for (j = i; j < disciplina.qtdAlunos -1; j++) {
                disciplina.alunos[j] =
                    disciplina.alunos[j+1];
            }

            disciplina.qtdAlunos--;

            printf("Aluno removido da disciplina.");
            return 1;
        }
    }

    printf("Aluno nao encontrado na disciplina.\n");
    return 0;
}

void listarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina) {
    int i;

    printf("-- Lista de Disciplinas --");

    if (qtdDisciplina == 0) {
        printf("Nao tem disciplinas cadastradas.\n");
        return;
    }

    for (i = 0; i < qtdDisciplina; i++) {

        if (listaDisciplina[i].ativo) {

            printf("\nNome: %d\n",
                   listaDisciplina[i].nome);

            printf("Codigo: %d\n",
                   listaDisciplina[i].codigo);

            printf("Semestre: %d\n",
                   listaDisciplina[i].semestre);

            printf("Professor: %d\n",
                   listaDisciplina[i].matriculaProfessor);

            printf("Quantidade de alunos: %d\n",
                   listaDisciplina[i].qtdAlunos);
        }
    }
}

int menuDisciplina
(Disciplina listaDisciplina[], int qtdDisciplina) {
    int opcao;
    int codigo;
    int i;
    int encontrado;

    do {
        printf("\n======== Modulo Disciplina ========\n");
        printf("0 - Voltar\n");
        printf("1 - Cadastrar Disciplina\n");
        printf("2 - Listar Disciplinas\n");
        printf("3 - Atualizar Disciplina\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 0:
                break;

            case 1:
                if (qtdDisciplina >= TAM_DISCIPLINA) {
                    printf("Lista de disciplinas cheia.\n");
                } else {
                    listaDisciplina[qtdDisciplina] =
                        cadastrarDisciplina();

                    qtdDisciplina++;
                }
                break;

            case 2:
                listarDisciplina(
                    listaDisciplina,
                    qtdDisciplina
                );
                break;

            case 3:
                printf("Digite o codigo da disciplina: ");
                scanf("%d", &codigo);

                encontrado = 0;

                for (i = 0; i < qtdDisciplina; i++) {

                    if (listaDisciplina[i].codigo == codigo &&
                        listaDisciplina[i].ativo) {

                        listaDisciplina[i] =
                            atualizarDisciplina(
                                listaDisciplina[i]
                            );

                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Disciplina inexistente.\n");
                }

                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return qtdDisciplina;
}