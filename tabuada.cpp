#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int i, n;
	printf("----------------------\n");
	printf("  tabuada do Othon   \n");
	printf("----------------------\n");
	
	printf("Escolha de que número vai ser a tabuada: \n");
	scanf("%d",&i);
	
	printf("Tabuada do %d:\n", i);
	for(n = 1; n<= 10; n++){
		printf("%d x %d = %d\n",i,n, i * n);
	}
	return 0;
}