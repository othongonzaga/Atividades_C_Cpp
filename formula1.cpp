#include <stdio.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	int pilotos[4], pontuacoes[4];
	
	printf("Digite o número do primeiro piloto e sua pontuação:\n");
	scanf("%i %i", &pilotos[0], &pontuacoes[0]);
	
	printf("Digite o número do segundo piloto e sua pontuação:\n");
	scanf("%i %i", &pilotos[1], &pontuacoes[1]);
	
  printf("Digite o número do terceiro piloto e sua pontuação:\n"); 
	scanf("%i %i", &pilotos[2], &pontuacoes[2]);
	
	printf("Digite o número do quarto piloto e sua pontuação:\n");
	scanf("%i %i", &pilotos[3], &pontuacoes[3]);

	int i = 1, b, x, d = 1, cont;

  // insertion sort
	for (i = 0;i <= 3; i++){
		x = pontuacoes[i]; // número na posição atual
		b = i - 1; // posição anterior
		while ((b >= 0) && (pontuacoes[b] > x)){ // compara se o número esta do vetor E se o número atual é menor do que o número que está na posição b
			pontuacoes[b+1] = pontuacoes[b]; 
			pilotos[b+1] = pilotos[b];
			b = b - 1;
		}
		pontuacoes[b+1] = x;
	}

  //ex:
	// 7 8 1 9 (1ªvez) b = -1 (aqui) não
	// 7 8 1 9 (2ªvez) b = 0 e 8 > 7 (aqui) não
	// 7 8 8 9 (3ªvez) b = 1 e 1 < 8 ok
	// 7 7 8 9 (4ªvez) b = 0 e 7 < 8 ok
	// 1 7 8 9 (5ªvez) b = -1 (aqui) não
	// 1 7 8 9 (6ªvez) b = 2 e 9 > 8 (aqui) não

	cont = 1;

	for (int i = 3; i > 1; i--) {
		printf("\n%iª posição: piloto %i com %i pontos",cont , pilotos[i], pontuacoes[i]);
		cont++;
	}
  
  return 0;
}