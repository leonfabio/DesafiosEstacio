#include <stdio.h>
#include <string.h>

#define TAM 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Declarações das funções
void inserirItem(Item mochila[], int *cont);
void removerItem(Item mochila[], int *cont);
void listarItens(Item mochila[], int cont);
void buscarItens(Item mochila[], int cont);

int main() {
    Item mochila[TAM];
    int cont = 0;   // contador de itens na mochila
    int opcao;

    do {
		printf("\n=================\n");
		printf("\n--DESAFIO NOVATO--\n");
		printf("\n=================\n");
        printf("\n MOCHILA FREE FIRE \n");
		printf("\nItens na mochila %d/10\n\n",cont);
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar itens\n");
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
                buscarItens(mochila, cont);
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

// ------------------------ FUNÇÃO INSERIR ------------------------
void inserirItem(Item mochila[], int *cont) {
    if (*cont >= TAM) {
        printf("Mochila cheia! Nao é possível inserir mais itens.\n");
        return;
    }

    printf("Digite o nome do item: ");
    scanf("%s", mochila[*cont].nome);

    printf("Digite o tipo do item: ");
    scanf("%s", mochila[*cont].tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &mochila[*cont].quantidade);

    (*cont)++;
    printf("Item inserido com sucesso!\n");
}

// ------------------------ FUNÇÃO REMOVER ------------------------
void removerItem(Item mochila[], int *cont) {
    if (*cont == 0) {
        printf("A mochila está vazia, nada para remover.\n");
        return;
    }

    char nomeBuscado[30];
    printf("Digite o nome do item que deseja remover: ");
    scanf("%s", nomeBuscado);

    int i, encontrado = 0;

    for (i = 0; i < *cont; i++) {
        if (strcmp(mochila[i].nome, nomeBuscado) == 0) {
            encontrado = 1;

            // Desloca os itens para "tampar" o buraco
            for (int j = i; j < (*cont) - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            (*cont)--;
            printf("Item removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Item não encontrado.\n");
    }
}

// ------------------------ FUNÇÃO LISTAR ------------------------
void listarItens(Item mochila[], int cont) {
    if (cont == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    printf("\n--- Itens da mochila ---\n");
    for (int i = 0; i < cont; i++) {
        printf("Item %d:\n", i + 1);
        printf("  Nome: %s\n", mochila[i].nome);
        printf("  Tipo: %s\n", mochila[i].tipo);
        printf("  Quantidade: %d\n\n", mochila[i].quantidade);
    }
}

void buscarItens(Item mochila[], int cont) {
	if (cont == 0) {
        printf("A mochila está vazia, nada para remover.\n");
        return;
    }
    char nomeBuscado[30];
    printf("Digite o nome do item que deseja localizar: ");
    scanf("%s", nomeBuscado);
    
    int i, encontrado = 0;

    for (i = 0; i < cont; i++) {
        if (strcmp(mochila[i].nome, nomeBuscado) == 0) {
            encontrado = 1;
			printf("Item encontrado!\n");
			printf("Item %d:\n", i + 1);
			printf("  Nome: %s\n", mochila[i].nome);
			printf("  Tipo: %s\n", mochila[i].tipo);
			printf("  Quantidade: %d\n\n", mochila[i].quantidade);
			
            break;
        }
    }

    if (!encontrado) {
        printf("Item não encontrado.\n");
    }
};
