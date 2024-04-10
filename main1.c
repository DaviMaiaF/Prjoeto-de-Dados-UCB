#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_CURSO 20

struct pessoa {
    char nome[MAX_NOME];
    char telefone[20];
    char curso[MAX_CURSO];
};

struct notas {
    float nota1, nota2;
};

int main() {
    FILE *arquivo;
    arquivo = fopen("C:/Users/gabriel.cezar/Downloads/DadosEntrada.csv", "r");

    if (arquivo == NULL) {
        printf("Impossivel abrir o arquivo.\n");
        exit(1);
    }

    struct pessoa Pessoa;
    struct notas Notas;
    float total;

    char linha[200];
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%[^,],%[^,],%[^,],%f,%f", Pessoa.nome, Pessoa.telefone, Pessoa.curso, &Notas.nota1, &Notas.nota2);
        
        total = (Notas.nota1 + Notas.nota2) / 2;
        printf("\nNome: %s", Pessoa.nome);
        printf("\nTelefone: %s", Pessoa.telefone);
        printf("\nCurso: %s", Pessoa.curso);
        printf("\nNota 1: %.2f", Notas.nota1);
        printf("\nNota 2: %.2f", Notas.nota2);
        printf("\nNota Final: %.2f\n", total);
    }

    fclose(arquivo);
    return 0;
}
