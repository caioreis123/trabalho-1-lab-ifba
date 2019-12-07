#define TAM 5
#define BARCO1 2
#define BARCO2 1
#define BARCO3 1
#include <stdio.h>

void exibeTabuleiroProprio(char tabuleiro[TAM][TAM], int jogador){
  int linha, coluna;

  printf("TABULEIRO DO JOGADOR: %d\n", jogador);
  printf("  ");
  for(coluna=0;coluna<TAM;coluna++) printf("%d ", coluna);
  printf("\n");
  for (linha=0;linha<TAM;linha++){
    printf("%d ", linha);
    for (coluna=0; coluna<TAM; coluna++){
      printf("%c ",tabuleiro[linha][coluna]);
    }
    printf("\n");
  }
}

int colocaBarcos(char tabuleiro[TAM][TAM], int tamBarco){
  int extremidade, linha1, coluna1, linha2, coluna2, menorLinha, menorColuna, cont;

  printf("Digite a linha da extremidade 1\n");
  scanf("%d", &linha1);

  printf("Digite a coluna da extremidade 1\n");
  scanf("%d", &coluna1);
  
  printf("Digite a linha da extremidade 2\n");
  scanf("%d", &linha2);

  printf("Digite a coluna da extremidade 2\n");
  scanf("%d", &coluna2);

  if(linha1<linha2) menorLinha=linha1;
  else menorLinha=linha2;

  if(coluna1<coluna2) menorColuna=coluna1;
  else menorColuna=coluna2;        

  if(linha1==linha2){
    for(cont=0;cont<tamBarco; cont++){
      if(tabuleiro[linha1][menorColuna+cont]!='~'){
        printf("Espaco ocupado. Digite novos valores.\n");
        colocaBarcos(tabuleiro, tamBarco);
      }
    }
  }

  if(coluna1==coluna2){
    for(cont=0;cont<tamBarco; cont++){
      if(tabuleiro[coluna1][menorLinha+cont]!='~'){
        printf("Espaco ocupado. Digite novos valores.\n");
        colocaBarcos(tabuleiro, tamBarco);
      }
    }
  }

  if(linha1==linha2){
    for(cont=0;cont<tamBarco; cont++){
      tabuleiro[linha1][menorColuna+cont]='N';      
    }
    return 1;
  }

  if(coluna1==coluna2){
    for(cont=0;cont<tamBarco; cont++){
      tabuleiro[coluna1][menorLinha+cont]='N';
      printf("colocou na mesma coluna!\n");      
    }
    return 1;
  }

  printf("Nao eh possivel posicionar o barco dessa forma. Por favor tente novamente\n");
  colocaBarcos(tabuleiro, tamBarco);
}

void preencheTabuleiro(char tabuleiro[TAM][TAM], int jogador){
  int a;  
  exibeTabuleiroProprio(tabuleiro, jogador);
  printf("Tamanho do barco a ser colocado: %d\n", BARCO1);
  colocaBarcos(tabuleiro, BARCO1);

  // ***********************************comentado só pra facilitar o teste. NÃO APAGUE!!!!!!!!!!!!!!!!!!!!

  // printf("Tabuleiro do jogador %d\n", jogador);
  // exibeTabuleiroProprio(tabuleiro, jogador);
  // printf("Tamanho do barco a ser colocado: %d\n", BARCO2);
  // colocaBarcos(tabuleiro, BARCO2);

  // for(a=0; a<3; a++){
  //   printf("Tabuleiro do jogador %d\n", jogador);
  //   exibeTabuleiroProprio(tabuleiro, jogador);
  //   printf("Tamanho do barco a ser colocado: %d\n", BARCO3);
  //   colocaBarcos(tabuleiro, BARCO3);
  // }
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
    
    if(jogador==1){      
      preencheTabuleiro(tabuleiro1, jogador);
    }
    else{      
      preencheTabuleiro(tabuleiro2, jogador);
    }
  }
}

void trocaTurno(int *turno){
  if(*turno==1) *turno=2;
  else *turno=1;
}

void tiro(char tabuleiro1[TAM][TAM], char tabuleiro2[TAM][TAM], int turno){

}

int main(){
  char tabuleiro1[TAM][TAM];
  char tabuleiro2[TAM][TAM];
  int continua=1;
  int turno=1;

  while(continua){
    inicializarTabuleiros(tabuleiro1, tabuleiro2);
    tiro(tabuleiro1, tabuleiro2, turno);
    trocaTurno(&turno);
  }
}