#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
    float a1,r,an,Sn,q;
    int op,n;

    printf("1  - Progressão Aritmética - PA\n");
    printf("2 - Progressão Geométrica - PG\n");
    printf("3 - Sair\nEscolha sua opcão: ");
    scanf("%i",&op);
    switch(op) {
        case 1:
            printf("\tProgressão Aritmética - PA\n");
            printf("\nDigite o valor do primeiro termo: ");
            scanf("%f",&a1);
            printf("\nDigite o valor da razão: ");
            scanf("%f",&r);
            printf("\nNúmero de termos: ");
            scanf("%i",&n);
            an = (a1 + (n - 1) * r);
            Sn = (n*(a1 + an))/2;
            printf("\nÚltimo termo da P.A. - an: %.2f\n\n",an);
            printf("A Soma do termos da P.A. - Sn: %.2f\n\n",Sn);

            break;

        case 2:
            printf("\tProgressão Geométrica - PG\n");
            printf("\nDigite o valor do primeiro termo: ");
            scanf("%f",&a1);
            printf("\nDigite o valor da razão: ");
            scanf("%f",&q);
            printf("\nNúmero de termos: ");
            scanf("%i",&n);
            an = a1 * pow(q,(n-1));
            Sn = a1 * (pow(q,n) - 1)/(q - 1);
            printf("\nÚltimo termo da P.G. - an: %.2f\n\n",an);
            printf("A Soma do termos da P.G. finita - Sn: %.2f\n\n",Sn);

            break;
    }

  return 0;
}