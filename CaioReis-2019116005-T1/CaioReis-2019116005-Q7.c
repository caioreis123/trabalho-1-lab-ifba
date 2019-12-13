#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void validarJogada(int jogadas[3][3], int vez);
void marcarJogada(char letra, int numero, int vez, int jogadas[3][3]);

void marcarJogada(char letra, int numero, int vez, int jogadas[3][3]){
  int linha, coluna, marca;

  if(letra=='A') linha=0;
  if(letra=='B') linha=1; 
  if(letra=='C') linha=2;
  if(numero==1) coluna=0;
  if(numero==2) coluna=1;
  if(numero==3) coluna=2;
  if(vez==1) marca = 1;
  if(vez==2) marca = -1;
  if(jogadas[linha][coluna]!=0){
    printf("Celula ja ocupada. Escolha outro espaco\n");
    validarJogada(jogadas, vez);
  } else{
  jogadas[linha][coluna]=marca; 
  }  
}

void desenhaTabuleiro(int jogadas[3][3]){
  int coluna=0;  
  printf("    1    2     3\n");
  printf("A ");
  for(coluna=0;coluna<3;coluna++){
    if(jogadas[0][coluna]==0){
      printf("   ");
    } else if (jogadas[0][coluna]==1){
      printf(" X ");
    } else{
      printf(" O ");
    }
    if(coluna!=2){
      printf(" | ");
    }
  }
  printf("\n_________________\n");
  printf("B ");
  for(coluna=0;coluna<3;coluna++){
    if(jogadas[1][coluna]==0){
      printf("   ");
    } else if (jogadas[1][coluna]==1){
      printf(" X ");
    } else{
      printf(" O ");
    }
    if(coluna!=2){
      printf(" | ");
    }
  }
  printf("\n_________________\n");
  printf("C ");
  for(coluna=0;coluna<3;coluna++){
    if(jogadas[2][coluna]==0){
      printf("   ");
    } else if (jogadas[2][coluna]==1){
      printf(" X ");
    } else{
      printf(" O ");
    }
    if(coluna!=2){
      printf(" | ");
    }
  }
  printf("\n");      
}

void validarJogada(int jogadas[3][3], int vez){
  char letra;
  int numero;
  char jogada[100];
  int valido=0;
  int cont;

  while(!valido){
  printf("\nEscolha a celula que deseja jogar. \n[Exemplo: B2]\n");
  scanf("%s", jogada);
  getchar();
  
  letra = toupper(jogada[0]);
  numero = jogada[1]-'0';
    if((letra>='A'&&letra<='C')&&(numero>=1&&numero<=3)&&(strlen(jogada)==2)){
      valido=1;
    }
    else printf("\nCelula invalida. Digite novamente\n");  
  }
  marcarJogada(letra, numero, vez, jogadas);
}

int checarEmpate(int jogadas[3][3], int vez){
  int i, j, ocupado=0;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      if(jogadas[i][j]!=0) ocupado++;
    }
  }
  if(ocupado==9) {
    printf("EMPATE!\n");
    desenhaTabuleiro(jogadas);
    return 0;
  }else return 1;
}

int checarVitoria(int jogadas[3][3], int vez){
  int coluna=0, linha=0, soma=0, ambas=0;

  //checando linhas:
  for(linha=0; linha<3; linha++){
    for(coluna=0; coluna<3; coluna++){
      soma+=jogadas[linha][coluna];
    }
    if(soma==3||soma==-3){
      printf("\nVITORIA DO JOGADOR %d!\n", vez);
      desenhaTabuleiro(jogadas);
      return 0;
    } 
      else soma=0;
  }

  //checando colunas:
  for(coluna=0; coluna<3; coluna++){
    for(linha=0; linha<3; linha++){
      soma+=jogadas[linha][coluna];
    }
    if(soma==3||soma==-3){
      printf("\nVITORIA DO JOGADOR %d!\n", vez);
      desenhaTabuleiro(jogadas);
      return 0;
    } 
      else soma=0;
  }

  soma=0;

  //checando primeira diagonal:
  for(ambas=0; ambas<3; ambas++){
    soma+=jogadas[ambas][ambas];
  }
  if(soma==3||soma==-3){
    printf("\nVITORIA DO JOGADOR %d!\n", vez);
    desenhaTabuleiro(jogadas);
    return 0;
  } 
      
  soma=0;

  //checando segunda diagonal:
  for(linha=0, coluna=2; linha<3; linha++, coluna--){    
    soma+=jogadas[linha][coluna];    
  }
  if(soma==3||soma==-3){
    printf("\nVITORIA DO JOGADOR %d!\n", vez);
    desenhaTabuleiro(jogadas);
    return 0;
  }

  soma=0;     
  return 1;
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
  int jogadas[3][3];
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      jogadas[i][j]=0;
    }
  }
  while (continua){
  limpaTela();
  printf("\nVez do Jogador %d\n", vez);  
  desenhaTabuleiro(jogadas);
  validarJogada(jogadas, vez); 
  continua=checarVitoria(jogadas, vez);
  if(continua){
    continua=checarEmpate(jogadas, vez);
  }
  trocaVez(&vez);
  }
}