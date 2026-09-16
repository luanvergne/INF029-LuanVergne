#ifndef ALUNO_H
#define ALUNO_H
#include "pessoa.h"

#define TAM_ALUNO 3

typedef struct {
    int matricula; Pessoa pessoa; int ativo;
} Aluno;

Aluno cadastrarAluno();
Aluno atualizarAluno(Aluno aluno);

int excluirAluno(Aluno listaAluno[], int qtdAluno);
int menuAluno(Aluno listaAluno[], int qtdAluno);

void listarAluno(Aluno listaAluno[], int qtdAluno);

#endif
