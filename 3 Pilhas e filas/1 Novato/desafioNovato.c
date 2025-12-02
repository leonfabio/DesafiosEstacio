#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILA 10   // capacidade total da fila
#define INICIAIS 5    // quantas peças iniciais serão geradas

typedef struct {
    char tipo;   // 'I','O','T','L'
    int id;      // número único
} Peca;

typedef struct {
    Peca fila[MAX_FILA];
    int frente;
    int tras;
    int tamanho;
} Fila;

// ------------------ Funções de fila ------------------

void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = 0;
    f->tamanho = 0;
}

int filaCheia(Fila *f) {
    return f->tamanho == MAX_FILA;
}

int filaVazia(Fila *f) {
    return f->tamanho == 0;
}

void enqueue(Fila *f, Peca p) {
    if (filaCheia(f)) {
        printf("A fila está cheia! Não é possível inserir.\n");
        return;
    }
    f->fila[f->tras] = p;
    f->tras = (f->tras + 1) % MAX_FILA;
    f->tamanho++;
}

Peca dequeue(Fila *f) {
    Peca p = {'X', -1};
    if (filaVazia(f)) {
        printf("A fila está vazia! Não é possível jogar peça.\n");
        return p;
    }
    p = f->fila[f->frente];
    f->frente = (f->frente + 1) % MAX_FILA;
    f->tamanho--;
    return p;
}

void exibirFila(Fila *f) {
    printf("Fila de peças: ");
    if (filaVazia(f)) {
        printf("[vazia]\n");
        return;
    }

    int i = f->frente;
    for (int c = 0; c < f->tamanho; c++) {
        printf("[%c%d]", f->fila[i].tipo, f->fila[i].id);
        i = (i + 1) % MAX_FILA;
    }
    printf("\n");
}

// ------------------ Gerar peças ------------------

char tipos[] = {'I','O','T','L'};

Peca gerarPeca(int id) {
    Peca p;
    p.tipo = tipos[rand() % 4];
    p.id = id;
    return p;
}

// ------------------ Programa principal ------------------

int main() {
    srand(time(NULL));

    Fila f;
    inicializarFila(&f);

    int idAtual = 0;

    // Gerar peças iniciais
    for (int i = 0; i < INICIAIS; i++)
        enqueue(&f, gerarPeca(idAtual++));

    int opcao;
    do {
        exibirFila(&f);
        printf("\n1 - Jogar peça (dequeue)\n");
        printf("2 - Inserir nova peça (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (!filaVazia(&f)) {
                Peca jogada = dequeue(&f);
                printf("Peça jogada: [%c%d]\n", jogada.tipo, jogada.id);
            }
        }
        else if (opcao == 2) {
            if (!filaCheia(&f)) {
                enqueue(&f, gerarPeca(idAtual++));
                printf("Peça inserida!\n");
            }
        }

        printf("\n");

    } while (opcao != 0);

    printf("Encerrando...\n");
    return 0;
}
