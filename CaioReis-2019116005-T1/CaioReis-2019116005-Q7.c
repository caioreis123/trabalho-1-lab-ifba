#include <stdio.h>
#include <ctype.h>
#include<string.h>

void marcarJogada(char jogada[3], int vez, char jogadas[3][3]){
  jogada[0] = toupper(jogada[0]);
  printf("jogada eh: %s\n", jogada);
  if(strcmp(jogada, "A1\0")==0&&vez==1){
    jogadas[0][0]='X';
  }else if(strcmp(jogada, "A1")==0&&vez==2){
    jogadas[0][0]='O';
  }else if(strcmp(jogada, "A2")==0&&vez==1){
    jogadas[0][1]='X';
  }else if(strcmp(jogada, "A2")==0&&vez==2){
    jogadas[0][1]='O';
  }else if(strcmp(jogada, "A3")==0&&vez==1){
    jogadas[0][2]='X';
  }else if(strcmp(jogada, "A3")==0&&vez==2){
    jogadas[0][2]='O';
  }else if(strcmp(jogada, "B1")==0&&vez==1){
    jogadas[1][0]='X';
  }else if(strcmp(jogada, "B1")==0&&vez==2){
    jogadas[1][0]='O';
  }else if(strcmp(jogada, "B2")==0&&vez==1){
    jogadas[1][1]='X';
  }else if(strcmp(jogada, "B2")==0&&vez==2){
    jogadas[1][1]='O';
  }else if(strcmp(jogada, "B3")==0&&vez==1){
    jogadas[1][2]='X';
  }else if(strcmp(jogada, "B3")==0&&vez==2){
    jogadas[1][2]='O';
  }else if(strcmp(jogada, "C1")==0&&vez==1){
    jogadas[2][0]='X';
  }else if(strcmp(jogada, "C1")==0&&vez==2){
    jogadas[2][0]='O';
  }else if(strcmp(jogada, "C2")==0&&vez==1){
    jogadas[2][1]='X';
  }else if(strcmp(jogada, "C2")==0&&vez==2){
    jogadas[2][1]='O';
  }else if(strcmp(jogada, "C3")==0&&vez==1){
    jogadas[2][2]='X';
  }else if(strcmp(jogada, "C3")==0&&vez==2){
    jogadas[2][2]='O';
  }  
}

void desenhaTabuleiro(char jogadas[3][3], int vez){
  char jogada[3];  
  printf("Vez do Jogador %d\n", vez);  
  printf("\n");
  printf("    1    2   3\n");
  printf("A   %c |  %c | %c\n", jogadas[0][0], jogadas[0][1], jogadas[0][2]);
  printf("_________________\n");
  printf("B   %c |  %c | %c\n", jogadas[1][0], jogadas[1][1], jogadas[1][2]);
  printf("_________________\n");
  printf("C   %c |  %c | %c\n", jogadas[2][0], jogadas[2][1], jogadas[2][2]);
  printf("\n");
  printf("Escolha a celula que deseja jogar: \n");
  fgets(jogada,3,stdin);
  getchar();
  marcarJogada(jogada, vez, jogadas);  
}

int checarEmpate(char jogadas[3][3]){
  int i, j, ocupado=0;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      if(jogadas[i][j]!=' ') ocupado++;
    }
  }
  if(ocupado==9) {
    printf("EMPATE!\n");
    return 0;
  }else return 1;
}

void limpaTela(){
    int i=0;
 
    while(i != 100)
    {
        putchar('\n');
        i++;
    }
}

void trocaVez(int *vez){
  if(*vez==1){
    *vez=2;
  }else{
    *vez=1;
  }
}

void main(){
  int i, j, continua=1, vez=1;
  char jogadas[3][3];
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      jogadas[i][j]=' ';
    }
  }
  while (continua){
  // limpaTela();  
  desenhaTabuleiro(jogadas, vez); 
  trocaVez(&vez);
  continua=checarEmpate(jogadas);
  // continua=checarVitoria(jogadas);  
  }
}