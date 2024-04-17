#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_CURSO 20

// Definição de Struct de dados
struct pessoa {
    char nome[MAX_NOME];
    char telefone[20];
    char curso[MAX_CURSO];
    float nota1;
    float nota2;
};

// Função para calcular média dos alunos
float calcularMedia(float nota1, float nota2) {
    return (nota1 + nota2) / 2;
}

// Função para processar o arquivo e escrever as informações no novo arquivo
void processarArquivo(FILE *arquivoEntrada, FILE *arquivoSaida) {
    struct pessoa Pessoa;
    float total;

    char linha[200];
    fgets(linha, sizeof(linha), arquivoEntrada);
    
    // Looping de saída das informações
    while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL) {
        sscanf(linha, "%[^,],%[^,],%[^,],%f,%f", Pessoa.nome, Pessoa.telefone, Pessoa.curso, &Pessoa.nota1, &Pessoa.nota2);
        
        total = calcularMedia(Pessoa.nota1, Pessoa.nota2);

        // Verifica se o aluno passou ou não
        char situacao[20];
        if (total >= 7.0) {
            strcpy(situacao, "APROVADO");
        } else {
            strcpy(situacao, "REPROVADO");
        }	 
        
        // Formata a string com as informações desejadas
        char infoFormatada[100];
        sprintf(infoFormatada, "%s,%.2f,%s\n", Pessoa.nome, total, situacao);
        
        // Escreve a string formatada no novo arquivo
        fprintf(arquivoSaida, "%s", infoFormatada);
    }
}

int main() {
    FILE *arquivoEntrada;
    arquivoEntrada = fopen("C:/Users/davi.figueiredo/Documents/est_dados/DadosEntrada.csv", "r");

	if (arquivoEntrada == NULL) {
        printf("Impossivel abrir o arquivo de entrada.\n");
        exit(1);
    }
	FILE *arquivoSaida;
	arquivoSaida = fopen("C:/Users/davi.figueiredo/Documents/est_dados/DadosEntrada.csv", "w");

    if (arquivoSaida == NULL) {
        printf("Impossivel abrir o arquivo.\n");
        exit(1);
    }

    processarArquivo(arquivoEntrada, arquivoSaida);

    fclose(arquivoEntrada);
    fclose(arquivoSaida);
    return 0;
}
