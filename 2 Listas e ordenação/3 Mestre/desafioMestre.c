#include <stdio.h>
#include <string.h>

#define TAM 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
    int prioridade;
} Item;

// Declaração das funções
void inserirItem(Item mochila[], int *cont);
void removerItem(Item mochila[], int *cont);
void listarItens(Item mochila[], int cont);
void ordenarItens(Item mochila[], int cont);
void ordenarPorNome(Item mochila[], int cont);
void ordenarPorTipo(Item mochila[], int cont);
void ordenarPorPrioridade(Item mochila[], int cont);
void buscaBinaria(Item mochila[], int cont);

// Funções auxiliares
void troca(Item *a, Item *b);

int main() {
    Item mochila[TAM];
    int cont = 0;
    int opcao;

    do {
        printf("\n=======================\n");
		printf("\n   --DESAFIO MESTRE--\n");
		printf("\n=======================\n");
        printf("\n MOCHILA FREE FIRE \n");
		printf("\nItens na mochila %d/10\n\n",cont);
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Ordenar itens\n");
        printf("5 - Busca binaria por nome\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &cont);
                break;

            case 2:
                removerItem(mochila, &cont);
                break;

            case 3:
                listarItens(mochila, cont);
                break;

            case 4:
                ordenarItens(mochila, cont);
                break;

            case 5:
                buscaBinaria(mochila, cont);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}

/* ===================== INSERIR ===================== */
void inserirItem(Item mochila[], int *cont) {
    if (*cont >= TAM) {
        printf("Mochila cheia!\n");
        return;
    }

    printf("Digite o nome: ");
    scanf("%s", mochila[*cont].nome);

    printf("Digite o tipo: ");
    scanf("%s", mochila[*cont].tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &mochila[*cont].quantidade);

    printf("Digite a prioridade: ");
    scanf("%d", &mochila[*cont].prioridade);

    (*cont)++;
    printf("Item inserido com sucesso!\n");
}

/* ===================== REMOVER ===================== */
void removerItem(Item mochila[], int *cont) {
    if (*cont == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    char nomeBuscado[30];
    printf("Digite o nome do item a remover: ");
    scanf("%s", nomeBuscado);

    int encontrado = 0;

    for (int i = 0; i < *cont; i++) {
        if (strcmp(mochila[i].nome, nomeBuscado) == 0) {
            encontrado = 1;

            for (int j = i; j < (*cont) - 1; j++)
                mochila[j] = mochila[j + 1];

            (*cont)--;
            printf("Item removido.\n");
            return;
        }
    }

    if (!encontrado)
        printf("Item nao encontrado.\n");
}

/* ===================== LISTAR ===================== */
void listarItens(Item mochila[], int cont) {
    if (cont == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    printf("\n--- Itens da mochila ---\n");
    for (int i = 0; i < cont; i++) {
        printf("Item %d:\n", i + 1);
        printf("  Nome: %s\n", mochila[i].nome);
        printf("  Tipo: %s\n", mochila[i].tipo);
        printf("  Quantidade: %d\n", mochila[i].quantidade);
        printf("  Prioridade: %d\n\n", mochila[i].prioridade);
    }
}

/* ===================== ORDENAR ===================== */
void ordenarItens(Item mochila[], int cont) {
    int opcao;

    if (cont == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    printf("\n===== ORDENAR POR =====\n");
    printf("1 - Nome (alfabetico)\n");
    printf("2 - Tipo\n");
    printf("3 - Prioridade\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            ordenarPorNome(mochila, cont);
            break;
        case 2:
            ordenarPorTipo(mochila, cont);
            break;
        case 3:
            ordenarPorPrioridade(mochila, cont);
            break;
        default:
            printf("Opcao invalida.\n");
    }
}

/* ===================== ORDENAR NOME ===================== */
void ordenarPorNome(Item mochila[], int cont) {
    int comparacoes = 0;

    for (int i = 0; i < cont - 1; i++) {
        for (int j = 0; j < cont - i - 1; j++) {
            comparacoes++;
            if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {
                troca(&mochila[j], &mochila[j + 1]);
            }
        }
    }

    printf("Itens ordenados por nome.\n");
    printf("Analise de desempenho: Foram necessarias %d comparacoes.\n", comparacoes);
}

/* ===================== ORDENAR TIPO ===================== */
void ordenarPorTipo(Item mochila[], int cont) {
    int comparacoes = 0;

    for (int i = 0; i < cont - 1; i++) {
        for (int j = 0; j < cont - i - 1; j++) {
            comparacoes++;
            if (strcmp(mochila[j].tipo, mochila[j + 1].tipo) > 0) {
                troca(&mochila[j], &mochila[j + 1]);
            }
        }
    }

    printf("Itens ordenados por tipo.\n");
    printf("Analise de desempenho: Foram necessarias %d comparacoes.\n", comparacoes);
}

/* ===================== ORDENAR PRIORIDADE ===================== */
void ordenarPorPrioridade(Item mochila[], int cont) {
    int comparacoes = 0;

    for (int i = 0; i < cont - 1; i++) {
        for (int j = 0; j < cont - i - 1; j++) {
            comparacoes++;
            if (mochila[j].prioridade > mochila[j + 1].prioridade) {
                troca(&mochila[j], &mochila[j + 1]);
            }
        }
    }

    printf("Itens ordenados por prioridade.\n");
    printf("Analise de desempenho: Foram necessarias %d comparacoes.\n", comparacoes);
}

/* ===================== TROCA DE POSIÇÃO ===================== */
void troca(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

/* ===================== BUSCA BINARIA ===================== */
void buscaBinaria(Item mochila[], int cont) {
    if (cont == 0) {
        printf("Mochila vazia, impossivel buscar.\n");
        return;
    }

    // Verifica se está ordenado por nome
    for (int i = 0; i < cont - 1; i++) {
        if (strcmp(mochila[i].nome, mochila[i + 1].nome) > 0) {
            printf("Erro: Os itens nao estao ordenados por nome!\n");
            return;
        }
    }

    char chave[30];
    printf("Digite o nome para buscar: ");
    scanf("%s", chave);

    int inicio = 0, fim = cont - 1;
    int comparacoes = 0;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        comparacoes++;

        int cmp = strcmp(chave, mochila[meio].nome);

        if (cmp == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[meio].nome);
            printf("Tipo: %s\n", mochila[meio].tipo);
            printf("Quantidade: %d\n", mochila[meio].quantidade);
            printf("Prioridade: %d\n", mochila[meio].prioridade);
            printf("\nAnalise de desempenho: %d comparacoes.\n", comparacoes);
            return;
        } else if (cmp > 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    printf("\nItem nao encontrado.\n");
    printf("Analise de desempenho: %d comparacoes.\n", comparacoes);
}
