// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Caio Souza dos Reis
//  email: reis.caio@gmail.com
//  Matrícula: 2019116005
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y){
  int soma = 0;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //função utilizada para testes
  int fat = 1;
  return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data){
    int datavalida = 1, tudo=0, parte, diaInt, mesInt, anoInt;
    char diaStr[100], mesStr[100], anoStr[100]; 
    
    //capturar valores
    for(tudo=0, parte=0; data[tudo]!='/'; tudo++, parte++){       
       diaStr[parte] = data[tudo];       
    }
    diaStr[parte] = '\0';
    tudo++;

    for(parte=0; data[tudo]!='/'; tudo++, parte++){       
       mesStr[parte] = data[tudo];       
    }
     tudo++;
     mesStr[parte]='\0';
    for(parte=0; tudo<strlen(data); tudo++, parte++){       
       anoStr[parte] = data[tudo];       
    }
    anoStr[parte]='\0';     

    //validar tamanho:
    if(strlen(diaStr)!=2 && strlen(diaStr)!=1){
       datavalida=0;
    }

    if(strlen(mesStr)!=2 && strlen(mesStr)!=1){
       datavalida=0;
    }

    if(strlen(anoStr)!=4 && strlen(anoStr)!=2){
       datavalida=0;
    }

    //validar inteiros:
    diaInt = atoi(diaStr);
    mesInt = atoi(mesStr);
    anoInt = atoi(anoStr);

    if(anoInt<100&&anoInt<20) anoInt+=2000;
    if(anoInt<100&&anoInt>=20) anoInt+=1900;
    

   if (((diaInt >= 1 && diaInt <= 31) && (mesInt == 1 || mesInt == 3 || mesInt == 5 || mesInt == 7 || mesInt == 8 || mesInt == 10 || mesInt == 12)) ||
		(diaInt == 29 && mesInt == 2 && (anoInt % 400 == 0 || (anoInt % 4 == 0 && anoInt % 100 != 0))) ||
		((diaInt >= 1 && diaInt <= 30) && (mesInt == 4 || mesInt == 6 || mesInt == 9 || mesInt == 11)) ||
		((diaInt >= 1 && diaInt <= 28) && (mesInt == 2))) datavalida=1;
      else datavalida=0;   

 
    
    //retorno final
    return datavalida;

}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    
    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos;

    if (q1(datainicial) == 0)
        //datainicial inválida
        return 2;

    if (q1(datafinal) == 0)
        //datafinal inválida
        return 3;

   int tudo=0, parte, diaIni, mesIni, anoIni, diaFim, mesFim, anoFim;
   char diaStr[100], mesStr[100], anoStr[100]; 
    
    //capturar valores dataInicial
    for(tudo=0, parte=0; datainicial[tudo]!='/'; tudo++, parte++){       
       diaStr[parte] = datainicial[tudo];       
    }
    diaStr[parte] = '\0';
    tudo++;

    for(parte=0; datainicial[tudo]!='/'; tudo++, parte++){       
       mesStr[parte] = datainicial[tudo];       
    }
     tudo++;
     mesStr[parte]='\0';
    for(parte=0; tudo<strlen(datainicial); tudo++, parte++){       
       anoStr[parte] = datainicial[tudo];       
    }
    anoStr[parte]='\0';

   //converter inteiros:
    diaIni = atoi(diaStr);
    mesIni = atoi(mesStr);
    anoIni = atoi(anoStr);

   //capturar valores dataFinal
    for(tudo=0, parte=0; datafinal[tudo]!='/'; tudo++, parte++){       
       diaStr[parte] = datafinal[tudo];       
    }
    diaStr[parte] = '\0';
    tudo++;

    for(parte=0; datafinal[tudo]!='/'; tudo++, parte++){       
       mesStr[parte] = datafinal[tudo];       
    }
     tudo++;
     mesStr[parte]='\0';
    for(parte=0; tudo<strlen(datafinal); tudo++, parte++){       
       anoStr[parte] = datafinal[tudo];       
    }
    anoStr[parte]='\0';

   //converter inteiros:
    diaFim = atoi(diaStr);
    mesFim = atoi(mesStr);
    anoFim = atoi(anoStr);

    if(anoFim<anoIni || (anoFim==anoIni && mesFim<mesIni)|| (anoFim==anoIni&&mesFim==mesIni&&diaFim<diaIni)){
       return 4;
    }
   
   //se o dia final é menor do que o inicial é preciso pegar emprestado todos os dias do mês anterior
   // antes de realizar a subtração para achar a diferença entre os dias
   int mesFimAnterior = mesFim-1; //pq se pega emprestado os dias do mês anterior (por serem os que já passaram)
   if(diaFim<diaIni){
      if(mesFimAnterior==2){ //se o mes anterior for fevereiro, há tratamento especial
         if(anoFim % 400 == 0 || (anoFim % 4 == 0 && anoFim % 100 != 0)){ //verifica-se bissexto
            diaFim+=29;
         }
         else diaFim+=28;
      }
      if(mesFimAnterior == 1 || mesFimAnterior == 3 || mesFimAnterior == 5 || mesFimAnterior == 7 || mesFimAnterior == 8 || mesFimAnterior == 10 || mesFimAnterior == 12){
         diaFim+=31;
      }
      else diaFim=+30;
   mesFim--; //tendo em vista que voce adicionou os dias do mês anterior no saldo de dias, 
   //você precisa subtrair 1 mês para compensar e não contar em dobro.
   }

   if(mesFim<mesIni){
      mesFim+=12;
      anoFim--;
   }

   nDias = diaFim-diaIni;
   nMeses = mesFim-mesIni;
   nAnos = anoFim-anoIni;

    /*mantenha o código abaixo, para salvar os dados
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = 0, cont;
   //  char textoCopia[500];
   //  strcpy(textoCopia,"Renato Lima Novais");

    if(!isCaseSensitive){
       for(cont=0;cont<strlen(texto);cont++){
          texto[cont]=toupper(texto[cont]);
       }
       c=toupper(c);
    }  

    for(cont=0;cont<strlen(texto);cont++){
       if(texto[cont]==c){
          qtdOcorrencias++;
       }
    }
    return qtdOcorrencias;

}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = 0, contA=0, contB=0, contC=0;

   //  tirar os acentos:
   int i, acentos=0;
   
   
    for(contA=0; contA<strlen(strTexto);contA++){
       if(strBusca[0]==strTexto[contA]){
          while(strBusca[contB]==strTexto[contA]){
             contA++;
             contB++;             
          }
          if(contB==strlen(strBusca)){             
            posicoes[contC]=contA-(strlen(strBusca)-1)-acentos;
            contC++;
            posicoes[contC]=contA-acentos;
            contC++;            
          }
          contB=0;
       }
       if(strTexto[contA]<0&&strTexto[contA+1]<0)  {
               acentos++;
            }
    }
   

    qtdOcorrencias = contC/2;
    return qtdOcorrencias;

}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
   int invNum=0, grandeza=1, aux=num;

   while(aux){
      aux=aux/10;
      grandeza=grandeza*10;
   }
   grandeza=grandeza/10;
   aux=num;
   
   while(aux){
      invNum=invNum+(aux%10)*grandeza;
      aux=aux/10;
      grandeza=grandeza/10;
   }

   return invNum;

   // usando string:
   // char sNum1 [9999];
   // char sNum2 [9999];
   // int contA, contB;

   // sprintf(sNum1,"%d",num);
   // sprintf(sNum2,"%d",num);
   
   // for(contA=strlen(sNum1)-1, contB=0;contA>=0;contA--, contB++){
   //    sNum1[contB]=sNum2[contA];
   // }

   // num = atoi(sNum1);  

   //  return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias=0, contA=0, contB=0;
    char strBase[9999];
    char strBusca[9999];

   sprintf(strBase,"%d",numerobase);
   sprintf(strBusca,"%d",numerobusca);

   for(contA=0, contB=0;contA<strlen(strBase);contA++){
      while(strBase[contA]==strBusca[contB]&&contA<strlen(strBase)){
         contA++;
         contB++;
      }
      if(contB==strlen(strBusca)){
         qtdOcorrencias++;
      }
      contB=0;            
   }
  
    return qtdOcorrencias;
}
