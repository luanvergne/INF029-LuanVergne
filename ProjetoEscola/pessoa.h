#ifndef PESSOA_H
#define PESSOA_H

#define TAM_NOME 100
#define TAM_CPF 12

typedef struct {
    char nome[TAM_NOME];
    char sexo;
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
    char cpf[TAM_CPF];
} Pessoa;

Pessoa cadastrarPessoa();
Pessoa atualizarPessoa(Pessoa pessoa);

int validarData(int dia, int mes, int ano);
int validarCPF(char cpf[]);

void exibirPessoa(Pessoa pessoa);

#endif
