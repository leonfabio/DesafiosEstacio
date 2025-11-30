#include <stdio.h>
#include <string.h>

#define MAX_JOGADORES 4 //Usei define para facilitar alterações futuras
#define TAM_STRING 50

//DEFINIÇÃO DA ESTRUTURA
struct Territorio {
	char nome[TAM_STRING];
	char cor[TAM_STRING];
	int tropas;	
};

//Função para limpar o buffer de entrada
void LimparBufferEntrada() {
	int c;
	while((c = getchar()) != '\n' && c != EOF); //EOF End Of File, macro int de valor -1
	}

int main(){
	
	struct Territorio jogadores[4];
	int totaljogadores = 0;
	int opcao;
	
	do{
		
		//Exibe as opçoes
		printf("===================================\n");
		printf("          DESAFIO WAR NOVATO\n");
		printf("===================================\n");
		printf("1 - Cadastrar novo jogador\n");
		printf("2 - Listar todos os jogadores\n");
		printf("0 - Sair\n\n\n");
		printf("===================================\n");
		
		printf("Escolha uma opção: ");
		scanf("%d", &opcao); //Le a opçao
		LimparBufferEntrada();  //Limpa o buffer
		
		switch(opcao){
			
			case 1 : //Cadastro de jogador e territorio
				printf("--- Cadastro de novo jogador ---\n\n");
				
				if (totaljogadores <= MAX_JOGADORES) {
					
					//ENTRADA DE DADOS
					printf("-- Cadastrando territorio %d --\n\n", totaljogadores+1);
					printf("O nome do território é um dos 5 continentes:\nAmerica, Europa, Asia, Africa e Oceania\n\n");
					printf("Digite o nome do território desejado: ");        
					fgets(jogadores[totaljogadores].nome, TAM_STRING, stdin);
					
					printf("Nomes das cores disponíveis:\nAzul, Verde, Vermelho, Amarela e Branca\n\n");
					printf("Digite o nome da cor do exército): ");
					fgets(jogadores[totaljogadores].cor, TAM_STRING, stdin);				
					
					printf("Digite o numero de tropas: ");
					scanf("%d", &jogadores[totaljogadores].tropas);
					LimparBufferEntrada();
					
					totaljogadores++;
					
					printf("Jogador cadastrado com sucesso!\n");
					
					} else {
						printf("Tabuleiro lotado! Nao e possivel cadastrar mais jogadores.\n");
					}
					
					printf("\nPressione Enter para continuar...");
					getchar(); //Pausa para o usuario ler a mensagem antes de voltar ao menu.
					break;
			
			case 2 : //Listagem de jogadores e territorios cadastrados
				printf("--- Lista de jogadores e territórios cadastrados ---\n\n");
				
				if (totaljogadores == 0) {
						printf("Nada cadastrado ainda.\n");
				} else {
					for (int i = 0; i < totaljogadores; i++) {
							printf("----------------------------------\n");
							printf("JOGADOR %d\n", i + 1);
							printf("Cor: %s\n", jogadores[i].cor);
							printf("Território: %s\n", jogadores[i].nome);
							printf("Numero de tropas: %d\n", jogadores[i].tropas);
						}
						printf("----------------------------------\n");
					}
					
					//A pausa é crucial para que o usuario veja a lista
					// antes do proximo loop limpar a tela
					printf("\nPressione Enter para continuar...");
					getchar();
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
		
		} while (opcao!=0);
	
	return 0;
	}
