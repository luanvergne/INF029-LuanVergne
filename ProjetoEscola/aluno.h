#ifndef ALUNO_H
#define ALUNO_H

#define TAM_ALUNO 3

typedef struct alu {
    int matricula;
    char sexo;
    int ativo;
} Aluno;


/* Funções do módulo Aluno */

int cadastrarAluno(Aluno lista_aluno[], int qtdAluno);

void listarAlunos(Aluno lista_aluno[], int qtdAluno);

void atualizarAluno(Aluno lista_aluno[], int qtdAluno);

int excluirAluno(Aluno lista_aluno[], int qtdAluno);

int menuAluno(Aluno lista_aluno[], int qtdAluno);

#endif
