#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "pessoa.h"

#define TAM_PROFESSOR 50

typedef struct {
    int matricula;
    Pessoa pessoa;
    int ativo;
} Professor;

Professor cadastrarProfessor();
Professor atualizarProfessor (Professor professor);

int excluirProfessor(Professor listaProfessor[], int qtdProfessor);

int menuProfessor(Professor listaProfessor[], int qtdProfessor);

void listarProfessor(Professor listaProfessor[], int qtdProfessor);

#endif
