#include <stdlib.h>
#include <conio.h>
#define COL 6
#define ROW 5
#define FALSE 0
#define TRUE 1

void inicializa(char matriz[ROW][COL]);
void mostrarPainel(char matriz[ROW][COL]);
void comprar(char matriz[ROW][COL]);
void reservar(char matriz[ROW][COL]);
void legenda();
int menuOpcao();
int colunaY();
int linhaX();

//estrutura dos dados
 struct dados {
          char nome[30];
          char bairro[30];
          int regnum;
   };  
      
   struct dados cod[50];
      int n=0;

int main (void){
  char matriz[ROW][COL];
  int opcao;
  int loopContinue=TRUE;
  
  inicializa(matriz); //Iniciliza a matriz com valores(Livre)
    
  do{
     system("cls");//Limpa a tela                
     opcao=menuOpcao();                   
     switch(opcao){
        case 1:
          system("cls");
          system("cls"); 
          mostrarPainel(matriz);//Mostra o Painel atualizado
          comprar(matriz); // Realiza a compra da poltrona no painel, marcando c/ um X
          break;
        
        case 2:
          system("cls");
          system("cls");
          mostrarPainel(matriz);
          reservar(matriz); //Realiza a reserva da poltrona no painel, marcando c/ um R
          break;
        
        case 3:
          system("cls");
          mostrarPainel(matriz);
          getch();
          break;   
        
        case 4:
          loopContinue = FALSE; //condicao para saída do programa
     }
  }while(loopContinue);
        
  getchar();    
  return 0;       
}
void inicializa(char matriz[ROW][COL]){
     int i,j;
     for(i=1;i<=ROW;i++)
       for(j=1;j<=COL;j++)
          matriz[i][j] = '.';
}

void mostrarPainel(char matriz[ROW][COL]){
  
  int i,j;
  printf("\n\n         %c   PAINEL DE OCUPACOES   %c\n\n",16,17);
  printf("          ");
  
  for(i=1;i<=COL;i++)
    printf("%d     ",i);
  
  for(i=1;i<=ROW;i++){
     printf("\n\n     %d",i);
     for(j=1;j<=COL;j++)
       printf("   (%c)",matriz[i][j]);     
  }
  //apresenta o menu na tela
  legenda();
}        
 
int menuOpcao(){
    int opcao=4;
    do {
         system("cls"); 
         printf("\n\n                    %c  MENU  %c\n\n",16,17);
        
         printf("                %c  1- Comprar        %c\n",16,17);
        
         printf("                %c  2- Reservar       %c\n",16,17);
        
         printf("                %c  3- Mostrar Painel %c\n",16,17); // Aqui é a pesquisa, aonde ele vai mostrar as poltronas livres e ocupadas
        
         printf("                %c  4- Exit           %c\n\n",16,17);
        
         printf("                   opcao: ");scanf("%d",&opcao);
         
         if(opcao <= 0 || opcao > 4){
            printf("\n\n\n    DIGITE APENAS VALORES CORESPONDENTES AO MENU !!");
            getch();
         }
            
     }while(opcao <= 0 || opcao > 4);
    
    return opcao;
}
//apresenta  a legenda na tela
void legenda(){
   printf("\n\n\n        .-Livre  X-Ocupado  R-Reservado\n\n");

}  
    //efetiva a compra da poltrona
void comprar(char matriz[ROW][COL]){
   int row, col;
   printf("\n           COMPRA DAS POLTRONAS\n\n");
   row = linhaX();
   col = colunaY();
   
   if(matriz[row][col]=='.'){
       matriz[row][col] = 'X';
       printf("\n\n      COMPRA EFETIVADA COM SUCESSO !!");
   }   
   else if (matriz[row][col]=='X')
             printf("\n\n      POLTRONA ESTA OCUPADA!! ESCOLHA OUTRA !!\n\n");
        else if(matriz[row][col]=='R')
               printf("\n\n    POLTRONA ESTA RESERVADA!! ESCOLHA OUTRA !!\n\n");
   
   getch();
   
               
} 
//reserva das poltronas
void reservar(char matriz[ROW][COL]){
   int row, col;
    printf("\n\n         RESERVA DAS POLTRONAS\n\n");
   row = linhaX();
   col = colunaY();
   
   if(matriz[row][col]=='.'){
       matriz[row][col] = 'R';
       printf("\n\n      RESERVA EFETIVADA COM SUCESSO !!");
   }   
   else if (matriz[row][col]=='X')
             printf("\n\n      POLTRONA JA OCUPADA!! ESCOLHA OUTRA !!\n\n");
        else if(matriz[row][col]=='R')
               printf("\n\n      POLTRONA JA RESERVADA !! ESCOLHA OUTRA !!\n\n");
    
    getch();
              
}
//ler a linha oferecida pelo usuario
int linhaX(){
   int row;
   printf("          Linha: "); scanf("%d",&row);
     if(row>5)
     {
       printf("\t\n Esta poltrona nao existe!!! ");
       }
   return row;
}
//ler a coluna oferecida pelo usuario
int colunaY(){
   int col;
   printf("          Coluna: "); scanf("%d",&col);
   if(col>6)
     {
       printf("\t\n Esta poltrona nao existe!!! ");
       }
   return col;                         
}