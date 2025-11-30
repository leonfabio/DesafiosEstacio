#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JOGADORES 4

//DEFINIÇÃO DA ESTRUTURA
struct Territorio {
	char nome[30];
	char cor[10];
	int tropas;	
};

//Função para limpar o buffer de entrada
void LimparBufferEntrada() {
	int c;
	while((c = getchar()) != '\n' && c != EOF); //EOF End Of File, macro int de valor -1
	}

int main() {

    //DECLARAÇÃO DA STRUCT DE ARRAYS
    //struct Territorio jogadores[4];
    
    //Acesso ao conteudo da struct *
    struct Territorio *jogadores;
    
    //Declaração da alocação do espaço na memoria
    jogadores = (struct Territorio *) malloc(JOGADORES * sizeof(struct Territorio));
    
    //Verificação da alocação
    if (jogadores == NULL) {
		printf("ERRO: Falha ao alocar memória.\n");
		return 1; //O retorno 1 indica erro
	}

    printf("========================================================\n\n");
    printf("Vamos cadastrar os 5 territórios iniciais do nosso mundo\n\n");
    printf("========================================================\n\n");

	//PERCORRENDO O ARRAY PARA ENTRADA DE DADOS
    for (int i=0; i<=4; i++) {
		
		//ENTRADA DE DADOS
        printf("-- Cadastrando territorio %d --\n\n", i+1);
        printf("O nome do território é um dos 5 continentes:\nAmerica, Europa, Asia, Africa e Oceania\n\n");
        printf("Digite o nome do território: ");        
        fgets(jogadores[i].nome, 30, stdin);
        		
		printf("Nomes das cores disponíveis:\nAzul, Verde, Vermelho, Amarela e Branca\n\n");
        printf("Digite o nome da cor do exército): ");
        fgets(jogadores[i].cor, 10, stdin);      
		
        printf("Digite o numero de tropas: ");
        scanf("%d", &jogadores[i].tropas);
        
        printf("\n\n");
		
        LimparBufferEntrada();
    };

    printf("===================================\n\n");
    printf("    MAPA DO MUNDO - ESTADO ATUAL   \n\n");
    printf("===================================\n\n");

	//PERCORRENDO O ARRAY PARA SAÍDA DE DADOS
    for (int j=0; j<=4; j++) {
		
        //SAÍDA DE DADOS
        printf("TERRITÓRIO %d: \n\n", j+1);
        printf("- Nome: %s", jogadores[j].nome);
        printf("- Cor: %s", jogadores[j].cor);
        printf("- Tropas: %d\n\n", jogadores[j].tropas);
    };
    
    free(jogadores);
	printf("Memoria liberada com sucesso.\n");

    printf("\nPressione Enter para continuar...");
    getchar(); //Espera para o usuário visualizar a saída na tela

    return 0;
};
