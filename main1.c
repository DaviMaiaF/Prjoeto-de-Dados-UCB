#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_CURSO 20

//Definição de Struct de dados
struct pessoa {
    char nome[MAX_NOME];
    char telefone[20];
    char curso[MAX_CURSO];
    float nota1;
    float nota2;
};

//Função para calcular média dos alunos
float calcularMedia(float nota1, float nota2) {
	return (nota1 + nota2) / 2;
}

int main() {
    FILE *arquivo;
    arquivo = fopen("C:/Users/davi.figueiredo/Documents/dados/DadosEntrada.csv", "r");

    if (arquivo == NULL) {
        printf("Impossivel abrir o arquivo.\n");
        exit(1);
    }

    struct pessoa Pessoa;
    float total;

    char linha[200];
    fgets(linha, sizeof(linha), arquivo);
    
	//looping de saída das informações
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%[^,],%[^,],%[^,],%f,%f", Pessoa.nome, Pessoa.telefone, Pessoa.curso, &Pessoa.nota1, &Pessoa.nota2);
        
        total = calcularMedia(Pessoa.nota1, Pessoa.nota2);
        printf("\nNome: %s", Pessoa.nome);
        printf("\nTelefone: %s", Pessoa.telefone);
        printf("\nCurso: %s", Pessoa.curso);
        printf("\nNota 1: %.2f", Pessoa.nota1);
        printf("\nNota 2: %.2f", Pessoa.nota2);
        printf("\nNota Final: %.2f\n", total);
    }

    fclose(arquivo);
    return 0;
}
