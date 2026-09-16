#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#define TAM_DISCIPLINA 30
#define TAM_NOME_DISCIPLINA 100
#define TAM_ALUNOS_DISCIPLINA 40

typedef struct {
    char nome[TAM_NOME_DISCIPLINA];
    int codigo;
    int semestre;
    int matriculaProfessor;

    int alunos[TAM_ALUNOS_DISCIPLINA];
    int qtdAlunos;

    int ativo;

} Disciplina;

Disciplina cadastrarDisciplina();
Disciplina atualizarDisciplina(Disciplina disciplina);

int inserirAlunoDisciplina
(Disciplina disciplina, int matriculaAluno);

int removerAlunoDisciplina
(Disciplina disciplina,int matriculaAluno);

int menuDisciplina(Disciplina listaDisciplina[],int qtdDisciplina);

void listarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);

#endif
