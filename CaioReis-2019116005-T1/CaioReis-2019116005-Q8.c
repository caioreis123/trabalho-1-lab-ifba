#define TAM 5
#define BARCO1 1
#define BARCO2 1
#define BARCO3 1
#include <stdio.h>

void limpatela(){
  int i=0;
 
  while(i != 100){
    putchar('\n');
    i++;
  }
}

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
  int linha1, coluna1, linha2, coluna2, menorLinha, menorColuna, maiorLinha, maiorColuna, cont;

  printf("\nDigite a linha da extremidade 1\n");
  scanf("%d", &linha1);

  printf("Digite a coluna da extremidade 1\n");
  scanf("%d", &coluna1);
  
  if(tamBarco>1){
  printf("Digite a linha da extremidade 2\n");
  scanf("%d", &linha2);

  printf("Digite a coluna da extremidade 2\n");
  scanf("%d", &coluna2);
  }

  if(tamBarco>1){
    if(linha1<linha2){
      menorLinha=linha1;
      maiorLinha=linha2;
    }
    else{
      menorLinha=linha2;
      maiorLinha=linha1;
    }

    if(coluna1<coluna2){
      menorColuna=coluna1;
      maiorColuna=coluna2;
    }
    else{
     menorColuna=coluna2; 
     maiorColuna=coluna1; 
    }
  }
  else{
    menorLinha=linha1;
    menorColuna=coluna1;
    linha2=linha1;
    coluna2=coluna1;
  }

  if((linha1<0 || linha1>TAM-1) || (coluna1<0 ||coluna1>TAM-1)){
    printf("Celula fora do limite do jogo. Digite novos valores\n");    
    return 0;
  }

  if(tamBarco>1){
    if((linha2<0 || linha2>TAM-1) || (coluna2<0 ||coluna2>TAM-1)){
    printf("Celula fora do limite do jogo. Digite novos valores\n");
    return 0;
    }
  }

  if(tamBarco>1&&linha1==linha2){
    if(tamBarco!=(maiorColuna-menorColuna)+1){
      printf("O tamanho do barco difere dos espacos selecionados. Por favor, tente novamente\n");
      return 0;
    }
  }

  if(tamBarco>1&&coluna1==coluna2){
    if(tamBarco!=(maiorLinha-menorLinha)+1){
      printf("O tamanho do barco difere dos espacos selecionados. Por favor, tente novamente\n");
      return 0;
    }
  }

  if(linha1==linha2){
    for(cont=0;cont<tamBarco; cont++){
      if(tabuleiro[linha1][menorColuna+cont]!='~'){
        printf("Espaco ocupado. Digite novos valores.\n");
        return 0;
      }
    }
  }

  if(coluna1==coluna2){
    for(cont=0;cont<tamBarco; cont++){
      if(tabuleiro[menorLinha+cont][coluna1]!='~'){
        printf("Espaco ocupado. Digite novos valores.\n");
        return 0;
      }
    }
  }
  
  //a inserção de valores no tabuleiro está acontecendo mesmo depois que acusa barco ocupado

  if(linha1==linha2){
    for(cont=0;cont<tamBarco; cont++){
      tabuleiro[linha1][menorColuna+cont]='N';      
    }
    return 1;
  }

  if(coluna1==coluna2){
    for(cont=0;cont<tamBarco; cont++){
      tabuleiro[menorLinha+cont][coluna1]='N';
    }
    return 1;
  }

  printf("Nao eh possivel posicionar o barco dessa forma. Por favor tente novamente\n");
  return 0;
}

void preencheTabuleiro(char tabuleiro[TAM][TAM], int jogador){
  int a, sucesso=0;  
  exibeTabuleiroProprio(tabuleiro, jogador);
  printf("Tamanho do barco a ser colocado: %d\n", BARCO1);
  while(!sucesso){
    sucesso=colocaBarcos(tabuleiro, BARCO1);
  }  
  limpatela();
  sucesso=0;

  // comentando para testes. não apague!!***********

  exibeTabuleiroProprio(tabuleiro, jogador);
  printf("Tamanho do barco a ser colocado: %d\n", BARCO2);
  while(!sucesso){
    sucesso=colocaBarcos(tabuleiro, BARCO2);
  }  
  limpatela();
  sucesso=0;

  for(a=0; a<3; a++){
    exibeTabuleiroProprio(tabuleiro, jogador);
    printf("Tamanho do barco a ser colocado: %d\n", BARCO3);
    while(!sucesso){
    sucesso=colocaBarcos(tabuleiro, BARCO3);
    }
    sucesso=0;
    limpatela();
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
}

void trocaJogador(int *jogador){
  if(*jogador==1) *jogador=2;
  else *jogador=1;
}

int tabuleiroAdversario(char tabuleiro[TAM][TAM]){
  int linha, coluna;

  printf("TABULEIRO DO ADVERSARIO:\n");
  printf("  ");
  for(coluna=0;coluna<TAM;coluna++) printf("%d ", coluna);
  printf("\n");
  for (linha=0;linha<TAM;linha++){
    printf("%d ", linha);
    for (coluna=0; coluna<TAM; coluna++){
      if(tabuleiro[linha][coluna]=='N') printf("~ ");      
      else printf("%c ",tabuleiro[linha][coluna]);
    }
    printf("\n");
  }

  printf("Escolha onde deseja atirar\n");
  printf("Digite a linha\n");
  scanf("%d", &linha);
  printf("Digite a coluna\n");
  scanf("%d", &coluna);

  if(linha>TAM-1||linha<0||coluna>TAM-1||coluna<0){
    printf("Celula fora dos limites. Digite outro valor.\n");
    return 0;
  }
  
  if(tabuleiro[linha][coluna]=='N'){
    tabuleiro[linha][coluna]='O';
    limpatela();
    printf("Acertou o tiro!\n");
    return 1;
  }
  else 
  if(tabuleiro[linha][coluna]=='~'){
    tabuleiro[linha][coluna]='X';
    limpatela();
    printf("Agua!\n");
    return 1;
  } else 
  if(tabuleiro[linha][coluna]=='X'){
    printf("Voce ja atirou ai. Escolha outro lugar. \n");
    return 0;
  }
}

void tiro(char tabuleiro1[TAM][TAM], char tabuleiro2[TAM][TAM], int jogador){
  int linha, coluna, sucesso=0;

  if(jogador==1){
    exibeTabuleiroProprio(tabuleiro1, jogador);
    printf("\n\n");
    while (!sucesso){
      sucesso=tabuleiroAdversario(tabuleiro2);
    }
  }
  else{
    exibeTabuleiroProprio(tabuleiro2, jogador);
    printf("\n\n");
    while (!sucesso){
      sucesso=tabuleiroAdversario(tabuleiro1);
    }
  } 
}

int checarVitoria(char tabuleiro1[TAM][TAM], char tabuleiro2[TAM][TAM], int jogador){
  int linha, coluna, vitoria1=1, vitoria2=1;

  for (linha=0;linha<TAM;linha++){
    for (coluna=0; coluna<TAM; coluna++){
      if(tabuleiro2[linha][coluna]=='N') vitoria1=0;
    }
  }

  for (linha=0;linha<TAM;linha++){
    for (coluna=0; coluna<TAM; coluna++){
      if(tabuleiro1[linha][coluna]=='N') vitoria2=0;
    }
  }
  if(vitoria1==1){
    printf("JOGADOR 1 VENCEU!\n");
    return 0;
  }
  if(vitoria2==1){
    printf("JOGADOR 2 VENCEU!\n");
    return 0;
  }
  printf("e o jogo continua... \n");
  return 1;  
}

int main(){
  char tabuleiro1[TAM][TAM];
  char tabuleiro2[TAM][TAM];
  int continua=1;
  int jogador=1;

  inicializarTabuleiros(tabuleiro1, tabuleiro2);
  preencheTabuleiro(tabuleiro1, 1);
  preencheTabuleiro(tabuleiro2, 2);
  while(continua){
    tiro(tabuleiro1, tabuleiro2, jogador);
    trocaJogador(&jogador);
    continua=checarVitoria(tabuleiro1, tabuleiro2, jogador);    
  }
}