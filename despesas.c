#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma despesa
typedef struct {
    char descricao[100];
    float valor;
} Despesa;

// Função para adicionar uma despesa à lista
void adicionarDespesa(Despesa despesas[], int *contador) {
    char descricao[100];
    float valor;

    // Solicitar informações do usuário
    printf("Digite a descrição da despesa: ");
    scanf("%99s", descricao);

    printf("Digite o valor da despesa: ");
    scanf("%f", &valor);

    // Adiciona a despesa à lista
    if (*contador < 100) {
        snprintf(despesas[*contador].descricao, sizeof(despesas[*contador].descricao), "%s", descricao);
        despesas[*contador].valor = valor;

        (*contador)++;
    } else {
        printf("A lista de despesas está cheia.\n");
    }
}

// Função para exibir todas as despesas
void exibirDespesas(const Despesa despesas[], int contador) {
    printf("Despesas:\n");
    for (int i = 0; i < contador; i++) {
        printf("%d. %s: R$ %.2f\n", i + 1, despesas[i].descricao, despesas[i].valor);
    }
}

// Função principal
int main() {
    Despesa despesas[100];  // Lista de despesas
    int contador = 0;       // Contador de despesas
    char opcao;

    do {
        // Exibe o menu
        printf("\nMenu:\n");
        printf("1. Adicionar Despesa\n");
        printf("2. Exibir Despesas\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                adicionarDespesa(despesas, &contador);
                break;
            case '2':
                exibirDespesas(despesas, contador);
                break;
            case '3':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != '3');

    return 0;
}
