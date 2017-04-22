
/**
 *  @author: Gustavo Henrique
 *
 *  Código de criptografia utilizando multiplicação
 *  de matrizes
 *
 */

#include <stdio.h>
#include <string.h>

int main(void){

	int i, j, k;

	int cod [2] [2]   = {3, 2, 1, 1};		// matriz codificadora 2x2
	int decod [2] [2] = {1, -2, -1, 3};		// matriz decodificadora 2x2

	char msg[40];							// mensagem a ser lida
	int msgNum[2] [20];						// mensagem convertida para números
	int msgNumCript[2] [20];				// mensagem criptografada
	int msgNumDescript[2] [20];				// mensagem descriptografada


	printf("  Criptografia utilizando matrizes\n\n");

	printf("Mensagem: ");
	scanf("%[^\n]", msg);						// leitura da mensagem a ser criptografada

	printf("\n\nMensagem a ser criptografada:           %s\n\n", msg);

	if(strlen(msg) % 2 == 1){					// verifica se a mensagem possui um número par de letras
		strncat(msg, " ", 1);					// se sim, adiciona um espaço em branco para facilitar a
	}											// montagem da matriz

	for(i=0, k=0; i<2; ++i){
		for(j=0; j<(strlen(msg) / 2); ++j){		// converte o vetor de caracteres lido para uma matriz
			msgNum[i] [j] = msg[k] - 96;		// iniciando a contagem por 'a' minusculo
			++k;
		}
	}

	printf("Mensagem convertida para números:     ");

	for(i=0; i<2; ++i){
		for(j=0; j<(strlen(msg) / 2); ++j){
			printf("%4d ", msgNum[i] [j]);
		}
	}

	printf("\n\n");

	// criptografia
	// algoritmo de multiplicação de matrizes
	for(i=0; i<2; ++i){
		for(j=0; j<(strlen(msg) / 2); ++j){
			msgNumCript[i] [j] = 0;		// inicializa cada casa da matriz com 0
										// multiplica-se os elementos de umalinha (cod) com uma
			for(k=0; k<2; ++k){			// coluna (msgNum) e soma com o que já está em msgNumCript
				msgNumCript[i] [j] = msgNumCript[i] [j] + ( cod[i] [k] * msgNum[k] [j] );
			}
		}
	}

	printf("Mensagem em numeros criptografada:    ");

	for(i=0; i<2; ++i){
		for(j=0; j<(strlen(msg) / 2); ++j){
			printf("%4d ", msgNumCript[i] [j]);
		}
	}

	printf("\n\n");

	// descriptografia
	// algoritmo de multiplicação de matrizes feito da mesma forma que o anterior
	for(i=0; i<2; ++i){
		for(j=0; j<(strlen(msg) / 2); ++j){
			msgNumDescript[i] [j] = 0;

			for(k=0; k<2; ++k){
				msgNumDescript[i] [j] = msgNumDescript[i] [j] + decod[i] [k] * msgNumCript[k] [j];
			}
		}
	}

	printf("Mensagem em numeros descriptografada: ");

	for(i=0; i<2; ++i){
		for(j=0; j<(strlen(msg) / 2); ++j){
			printf("%4d ", msgNumDescript[i] [j]);
		}
	}

	printf("\n\n");

	printf("Mensagem original:                      ");

	for(i=0; i<2; ++i){
		for(j=0; j<(strlen(msg) / 2); ++j){
			printf("%c", msgNumDescript[i] [j] + 96);	// imprime a letra correspondente
			                                            // ao número na tabela ASCII
		}
	}

	printf("\n");

	return 0;
}
