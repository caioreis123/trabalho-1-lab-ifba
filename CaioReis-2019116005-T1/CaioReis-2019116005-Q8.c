#define NUM_NAVIOS 5
#define TAM 10
#include <stdio.h>

void exibeTabuleiroProprio(char tabuleiro[TAM][TAM]){
  int linha, coluna;

  printf(" ");
  for(coluna=0;coluna<TAM;coluna++) printf("%d", coluna);
  for (linha=0;linha<TAM;linha++){
    printf("%d ", linha);
    for (coluna=0; coluna<TAM; coluna++){
      printf("%c",tabuleiro[linha][coluna]);
    }
    printf("\n");
  }
}

void colocaBarcos(char tabuleiro[TAM][TAM], int tamBarco){
  int extremidade, linha1, coluna1, linha2, coluna2, sucesso=0, cont;

    while(!sucesso){
      printf("Digite a linha da extremidade 1\n");
      scanf("%d", &linha1);
      getchar();
      printf("Digite a coluna da extremidade 1\n");
      scanf("%d", &coluna1);
      getchar();

      if(tabuleiro[linha1][coluna1]!='~') printf("Celula ja ocupada. Digite novamente\n");
      else{
        tabuleiro[linha1][coluna1]='N';
        sucesso=1;
      }    
    }

    sucesso=0;

    while(!sucesso){
      printf("Digite a linha da extremidade 2\n");
      scanf("%d", &linha2);
      getchar();
      printf("Digite a coluna da extremidade 2\n");
      scanf("%d", &coluna2);
      getchar();

      if(tabuleiro[linha2][coluna2]!='~') printf("Celula ja ocupada. Digite novamente\n");
      else{
        tabuleiro[linha2][coluna2]='N';
        sucesso=1;
      }    
    }    

    for(cont=0;cont<tamBarco, cont++){
      if
    }
  
}

void preencheTabuleiro(char tabuleiro[TAM][TAM]){
  int a;

  exibeTabuleiroProprio(tabuleiro);
  printf("Tamanho do barco a ser colocado: 4\n");
  colocaBarcos(tabuleiro, 4);
  exibeTabuleiroProprio(tabuleiro);
  printf("Tamanho do barco a ser colocado: 3\n");
  colocaBarcos(tabuleiro, 3);
  exibeTabuleiroProprio(tabuleiro);
  for(a=0; a<3; a++){
    printf("Tamanho do barco a ser colocado: 1\n");
    colocaBarcos(tabuleiro, 1);
    exibeTabuleiroProprio(tabuleiro);
  }
}

void inicializarTabuleiros(char tabuleiro1[TAM][TAM], char tabuleiro2[TAM][TAM]){ 
  int linha, coluna;

  for (linha=0;linha<TAM;linha++){
    for (coluna=0; coluna<TAM; coluna++){
      tabuleiro1[linha][coluna]='~';
      tabuleiro2[linha][coluna]='~';
    }
  }

  int jogador;
  for(jogador=1;jogador<3;jogador++){
    printf("Tabuleiro do jogador %d\n", jogador);
    if(jogador==1){
    preencheTabuleiro(tabuleiro1);
    }
    else{
    preencheTabuleiro(tabuleiro2);
    }
  }
}

void trocaTurno(int *turno){
  if(*turno==1) *turno=2;
  else *turno=1;
}

int main(){
  char tabuleiro1[TAM][TAM];
  char tabuleiro2[TAM][TAM];
  int continua=1;
  int turno=1;

  while(continua){

    trocaTurno(&turno);
  }
}