#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOGADORES 5 //Usei define para facilitar alterações futuras
#define TAM_STRING 50

//DEFINIÇÃO DA ESTRUTURA
struct Territorio {
	char nome[TAM_STRING];
	char cor[TAM_STRING];
	int tropas;	
};

void LimparBufferEntrada();
void exibirMenu();
void liberarMemoria(struct Territorio *jogadores);
void cadastrarJogador(struct Territorio *jogadores, int *totaljogadores);
void listarJogador(struct Territorio *jogadores, int totaljogadores);
void menuBatalha(struct Territorio *jogadores, int totaljogadores);
void batalhar(struct Territorio *jogadores, int *totaljogadores);

int main(){
    
    //Acesso ao conteudo da struct *
    struct Territorio *jogadores = (struct Territorio *) malloc(MAX_JOGADORES * sizeof(struct Territorio));
    
    //Verificação da alocação
    if (jogadores == NULL) {
		printf("ERRO: Falha ao alocar memória.\n");
		return 1; //O retorno 1 indica erro
	}	
	
	int totaljogadores = 0;
	int opcao;
	
	do{
		
		exibirMenu();
		scanf("%d", &opcao); //Le a opçao
		LimparBufferEntrada();  //Limpa o buffer
		
		switch(opcao){
			
			case 1 : //Cadastro de jogador e territorio
					cadastrarJogador(jogadores, &totaljogadores);
					break;
			
			case 2 : //Listagem de jogadores e territorios cadastrados
					listarJogador(jogadores, totaljogadores);
					break;
					
			case 3:
					menuBatalha(jogadores, totaljogadores);
					break;

			
			case 0 : //Saindo
					printf("\nSaindo do sistema...\n");
					break;			
			
			default: //Opção inválida
					printf("\nOpção inválida! Tente novamente.\n");
					printf("\nPressione Enter para continuar...");
					getchar();
					break;
			
			}
			
			//printf("--- FASE DE ATAQUE ---\n\n");
			//printf("Escolha o atacante(1 a 5, ou 0 para sair): ");
		
		} while (opcao!=0);
	
	liberarMemoria(jogadores);
	return 0;
	}
	
void LimparBufferEntrada() {
	int c;
	while((c = getchar()) != '\n' && c != EOF); //EOF End Of File, macro int de valor -1
	};
	
void liberarMemoria(struct Territorio *jogadores){
	
	free(jogadores);
	printf("Memoria liberada com sucesso.\n");
	
	};

void exibirMenu(){
	
		printf("===================================\n");
		printf("       DESAFIO WAR AVENTUREIRO\n");
		printf("===================================\n");
		printf("1 - Cadastrar novo jogador\n");
		printf("2 - Listar todos os jogadores\n");
		printf("3 - Simular batalhas\n");
		printf("0 - Sair\n");
		printf("===================================\n\n\n");
		
		printf("Escolha uma opção: ");
	
	};
	
void cadastrarJogador(struct Territorio *jogadores, int *totaljogadores){
	
	printf("--- Cadastro de novo jogador ---\n\n");
				
				if (*totaljogadores < MAX_JOGADORES) {
					int indice = *totaljogadores;
					
					//ENTRADA DE DADOS
					printf("-- Cadastrando territorio %d --\n\n", indice+1);
					printf("O nome do território é um dos 5 continentes:\nAmerica, Europa, Asia, Africa e Oceania\n\n");
					printf("Digite o nome do território desejado: ");        
					fgets(jogadores[indice].nome, TAM_STRING, stdin);
					
					printf("Nomes das cores disponíveis:\nAzul, Verde, Vermelho, Amarela e Branca\n\n");
					printf("Digite o nome da cor do exército: ");
					fgets(jogadores[indice].cor, TAM_STRING, stdin);				
					
					printf("Digite o numero de tropas: ");
					scanf("%d", &jogadores[indice].tropas);
					LimparBufferEntrada();
					
					jogadores[indice].nome[strcspn(jogadores[indice].nome, "\n")] = '\0';
					jogadores[indice].cor[strcspn(jogadores[indice].cor, "\n")] = '\0';

					
					(*totaljogadores)++;
					
					printf("Jogador cadastrado com sucesso!\n");
					
					} else {
						printf("Tabuleiro lotado! Nao e possivel cadastrar mais jogadores.\n");
					}
					
					printf("\nPressione Enter para continuar...");
					getchar();
	};
	
void listarJogador(struct Territorio *jogadores, int totaljogadores){
				
				if (totaljogadores == 0) {
						printf("Ninguem cadastrado ainda.\n");
				} else {
					printf("--- MAPA DO MUNDO - ESTADO ATUAL ---\n\n");
					
					for (int i = 0; i < totaljogadores; i++) {
							printf("----------------------------------\n");
							printf("%d.", i + 1);
							printf("%s ", jogadores[i].nome);
							printf("(Exército: %s, ", jogadores[i].cor);
							printf("Tropas: %d)\n", jogadores[i].tropas);
						}
						printf("----------------------------------\n");
					}

					printf("\nPressione Enter para continuar...");
					getchar();
	
	};
	
void batalhar(struct Territorio *jogadores, int *totaljogadores) {

    if (*totaljogadores < 2) {
        printf("\nPelo menos dois jogadores são necessários para batalhar!\n");
        printf("Pressione Enter para continuar...");
        getchar();
        return;
    }

    int atacante, defensor;

    do {
        printf("\n\n===== SIMULAÇÃO DE BATALHA =====\n");
        printf("Digite o numero do jogador atacante (1 a %d) ou 0 para sair: ", *totaljogadores);
        scanf("%d", &atacante);
        LimparBufferEntrada();

        if (atacante == 0) return;

        printf("Digite o numero do jogador defensor (1 a %d) ou 0 para sair: ", *totaljogadores);
        scanf("%d", &defensor);
        LimparBufferEntrada();

        if (defensor == 0) return;

        atacante--;
        defensor--;

        if (atacante < 0 || atacante >= *totaljogadores ||
            defensor < 0 || defensor >= *totaljogadores) {
            printf("Jogador inválido! Tente novamente.\n\n");
            continue;
        }

        if (atacante == defensor) {
            printf("Um jogador não pode batalhar contra si mesmo!\n\n");
            continue;
        }

        if (jogadores[atacante].tropas <= 0) {
            printf("O atacante não possui tropas suficientes!\n\n");
            continue;
        }

        if (jogadores[defensor].tropas <= 0) {
            printf("O defensor não possui tropas suficientes!\n\n");
            continue;
        }

        int dadoAtacante = (rand() % 6) + 1;
        int dadoDefensor = (rand() % 6) + 1;

        printf("\n--- RESULTADO DA BATALHA ---\n");
        printf("Atacante (%s) tirou: %d\n", jogadores[atacante].nome, dadoAtacante);
        printf("Defensor  (%s) tirou: %d\n", jogadores[defensor].nome, dadoDefensor);

        if (dadoAtacante > dadoDefensor) {
            jogadores[defensor].tropas--;
            printf("Defensor perde 1 tropa!\n");
        } else if (dadoDefensor > dadoAtacante) {
            jogadores[atacante].tropas--;
            printf("Atacante perde 1 tropa!\n");
        } else {
            printf("Empate! Ninguém perde tropas.\n");
        }

        printf("Tropas restantes: \n");
        printf("- Atacante (%s): %d\n", jogadores[atacante].nome, jogadores[atacante].tropas);
        printf("- Defensor  (%s): %d\n", jogadores[defensor].nome, jogadores[defensor].tropas);

        printf("\nPressione Enter para continuar...");
        getchar();

    } while (1);
};

void menuBatalha(struct Territorio *jogadores, int totaljogadores) {

    int opcao;

    do {
        printf("\n===================================\n");
        printf("          MENU DE BATALHA\n");
        printf("===================================\n");
        printf("1 - Iniciar batalha\n");
        printf("0 - Voltar ao menu principal\n");
        printf("===================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        LimparBufferEntrada();

        if (opcao == 1) {
            batalhar(jogadores, &totaljogadores); // Chama a função de batalha
        }

    } while (opcao != 0);

    printf("\nVoltando ao menu principal...\n");
    getchar();
	};


