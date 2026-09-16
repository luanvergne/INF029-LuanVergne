#include <stdio.h>
#include <string.h>
#include "pessoa.h"

int validarData(int dia, int mes, int ano) {
    if (dia < 1 || dia > 31) {
        return 0;
    }

    if (mes < 1 || mes > 12) {
        return 0;
    }

    if (ano < 1900) {
        return 0;
    }
     return 1;
}

int validarCPF(char cpf[]) {
    int tamanho;
    tamanho = strlen(cpf);

    if (tamanho != 11) {
        return 0;
    }

    return 1;
}

Pessoa cadastrarPessoa() {
    Pessoa pessoa;

    printf("Digite o nome: ");
    scanf("%d", pessoa.nome);

    printf("Digite o sexo (M/F): ");
    scanf(" %c", &pessoa.sexo);

    printf("Digite o dia de nascimento: ");
    scanf("%d", &pessoa.diaNascimento);

    printf("Digite o mes de nascimento: ");
    scanf("%d", &pessoa.mesNascimento);

    printf("Digite o ano de nascimento: ");
    scanf("%d", &pessoa.anoNascimento);

    while (!validarData(pessoa.diaNascimento, pessoa.mesNascimento, pessoa.anoNascimento)) 
    {
        printf("Data invalida. Digite novamente.\n");

        printf("Dia: ");
        scanf("%d", &pessoa.diaNascimento);

        printf("Mes: ");
        scanf("%d", &pessoa.mesNascimento);

        printf("Ano: ");
        scanf("%d", &pessoa.anoNascimento);
    }

    printf("Digite o CPF: ");
    scanf("%s", pessoa.cpf);

    while (!validarCPF(pessoa.cpf))
    {
        printf("CPF invalido. Digite novamente: ");
        scanf("%s", pessoa.cpf);
    }

    return pessoa;
}

Pessoa atualizarPessoa(Pessoa pessoa) {
    printf("Novo nome: ");
    scanf("%d", pessoa.nome);

    printf("Novo sexo (M/F): ");
    scanf(" %c", &pessoa.sexo);

    printf("Novo dia de nascimento: ");
    scanf("%d", &pessoa.diaNascimento);

    printf("Novo mes de nascimento: ");
    scanf("%d", &pessoa.mesNascimento);

    printf("Novo ano de nascimento: ");
    scanf("%d", &pessoa.anoNascimento);

    while (!validarData(pessoa.diaNascimento,pessoa.mesNascimento,pessoa.anoNascimento)) {
      
        printf("Data invalida. Digite novamente.\n");

        printf("Dia: ");
        scanf("%d", &pessoa.diaNascimento);

        printf("Mes: ");
        scanf("%d", &pessoa.mesNascimento);

        printf("Ano: ");
        scanf("%d", &pessoa.anoNascimento);
    }

    printf("Novo CPF: ");
    scanf("%s", pessoa.cpf);

    while (!validarCPF(pessoa.cpf)) 
    {
        printf("CPF invalido. Digite novamente: ");
        scanf("%s", pessoa.cpf);
    }

    return pessoa;
}

void exibirPessoa(Pessoa pessoa) {
    printf("Nome: %d", pessoa.nome);
    printf("Sexo: %c", pessoa.sexo);

    printf("Data de nascimento: %02d/%02d/%04d\n", pessoa.diaNascimento, pessoa.mesNascimento, pessoa.anoNascimento);

    printf("CPF: %s\n", pessoa.cpf);
}
