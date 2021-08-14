#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void tabuleiro(char casa2[3] [3]){
	setlocale(LC_ALL,"Portuguese");
	system("cls");
	printf("\t %c | %c | %c \n", casa2[0] [0], casa2[0] [1], casa2[0] [2]);
	printf("\t-----------\n");
	printf("\t %c | %c | %c \n", casa2[1] [0], casa2[1] [1], casa2[1] [2]);
	printf("\t-----------\n");
	printf("\t %c | %c | %c \n", casa2[2] [0], casa2[2] [1], casa2[2] [2]);	
}

int main(){
	char res;
	int cont_jogadas, l, c, vez = 0, i, j;
	do{
		char casa[3] [3] = { {'1', '2','3'},
                          {'4','5','6'},
                          {'7','8','9'}, };
                          
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			casa[i][j] = ' ';
		}
	}
		cont_jogadas = 1;
		do{
			tabuleiro(casa);
			if(vez%2 == 0){
				printf("Jogador do X\n");
			}else{
				printf("Jogador da O\n");
			}
			printf("Escolha a linha: ");
			scanf("%i",&l);
			printf("Escolha a coluna: ");
			scanf("%i",&c);	
			if(l < 1 || c < 1 || l > 3 || c > 3){
				l = 0;
				c = 0;
			}else if(casa[l-1]  [c-1] != ' '){
				l = 0;
				c = 0;
			}else{
				if(vez%2 == 0){
					casa[l-1] [c-1] = 'X';
				}else{
					casa[l-1] [c-1] = 'O';
				}
				vez++;
				cont_jogadas++;
			}
			if(casa [0] [0] == 'X' && casa[0] [1] == 'X' && casa[0] [2] == 'X'){cont_jogadas = 11;}
			if(casa [1] [0] == 'X' && casa[1] [1] == 'X' && casa[1] [2] == 'X'){cont_jogadas = 11;}
			if(casa [2] [0] == 'X' && casa[2] [1] == 'X' && casa[2] [2] == 'X'){cont_jogadas = 11;}
			if(casa [0] [0] == 'X' && casa[1] [0] == 'X' && casa[2] [0] == 'X'){cont_jogadas = 11;}
			if(casa [0] [1] == 'X' && casa[1] [1] == 'X' && casa[2] [1] == 'X'){cont_jogadas = 11;}
			if(casa [0] [2] == 'X' && casa[1] [2] == 'X' && casa[2] [2] == 'X'){cont_jogadas = 11;}
			if(casa [0] [0] == 'X' && casa[1] [1] == 'X' && casa[2] [2] == 'X'){cont_jogadas = 11;}
			if(casa [0] [2] == 'X' && casa[1] [1] == 'X' && casa[2] [0] == 'X'){cont_jogadas = 11;}
			
			if(casa [0] [0] == 'O' && casa[0] [1] == 'O' && casa[0] [2] == 'O'){cont_jogadas = 12;}
			if(casa [1] [0] == 'O' && casa[1] [1] == 'O' && casa[1] [2] == 'O'){cont_jogadas = 12;}
			if(casa [2] [0] == 'O' && casa[2] [1] == 'O' && casa[2] [2] == 'O'){cont_jogadas = 12;}
			if(casa [0] [0] == 'O' && casa[1] [0] == 'O' && casa[2] [0] == 'O'){cont_jogadas = 12;}
			if(casa [0] [1] == 'O' && casa[1] [1] == 'O' && casa[2] [1] == 'O'){cont_jogadas = 12;}
			if(casa [0] [2] == 'O' && casa[1] [2] == 'O' && casa[2] [2] == 'O'){cont_jogadas = 12;}
			if(casa [0] [0] == 'O' && casa[1] [1] == 'O' && casa[2] [2] == 'O'){cont_jogadas = 12;}
			if(casa [0] [2] == 'O' && casa[1] [1] == 'O' && casa[2] [0] == 'O'){cont_jogadas = 12;}
			
		}while(cont_jogadas<=9);
		tabuleiro(casa);
		if(cont_jogadas == 11){
			printf("Vitória do Jogador X!\n");
		}if(cont_jogadas == 12){
			printf("Vitória do Jogador Y!\n");
		}
		printf("Deseja jogar novamente? [S-N]\n");
		scanf("%s",&res);	
	}while(res == 's');
	                     
	return 0;	
}
