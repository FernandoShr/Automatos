#include <stdio.h>
#include <stdlib.h>

#define SIZE 12
#define TAMPALAVRA 11

// Função para deletar o primeiro termo da array
void deletarPrimeiroTermo(char array[], int tamanho) {
  if (tamanho > 0) {
    // Mover todos os elementos para a esquerda
    for (int i = 0; i < tamanho - 1; i++) {
      array[i] = array[i + 1];
    }

    // Reduzir o tamanho da array
    (tamanho)--;
  } else {
    printf("Erro: A array está vazia, não há termo para deletar.\n");
  }
}

// Função para adicionar um elemento ao array
void adicionarElemento(char array[], int tamanho, char elemento) {
  // Verificar se há espaço no array
  if (tamanho < SIZE) {
    // Adicionar o novo elemento ao final do array
    array[tamanho] = elemento;

  } else {
    printf
        ("Erro: Array está cheio, não é possível adicionar mais elementos.\n");
  }
}

// Função para verificar se um array está presente em uma matriz
int arrayEstaNaMatriz(char matriz[][TAMPALAVRA], int linhas, int colunas, char array[], int tamanhoArray) {
    for (int i = 0; i <= linhas - tamanhoArray; i++) {
        for (int j = 0; j <= colunas - tamanhoArray; j++) {
            
            int encontrado = 1;
            for (int k = 0; k < tamanhoArray; k++) {
                if (matriz[i + k][j] != array[k]) {
                    encontrado = 0;
                    break;
                }
            }

            if (encontrado) {
                return 1;
            }
        }
    }

    // Se não for encontrado, retorna false
    return 0;
}

int iguais(char *v1, char *v2, int tam) {
  int i, cont = 1;
  for (i = 0; i < tam; i++) {
    if (v1[i] != v2[i]) {
      return 0;
    }
  }

  return 1;
}

int tamanhoPalavra(char *palavra) {
  int tam = 0;

  while (palavra[tam] != '\0') {
    tam++;
  }

  return tam;
}

int tamanhoArray (char array[]) {
  int tam = 0;
  char i;

  for(int j; array[j] != '\0'; j++) {

  
  }
  
}

int percorre(char *palavra, char estados[SIZE][TAMPALAVRA],
             char a[SIZE][TAMPALAVRA], char b[SIZE][TAMPALAVRA]) {

  int i = 0;
  int ultimoEstado = sizeof(estados) / sizeof(estados[0]);
  int estadoAceitacao = ultimoEstado - 1;
  int estadoInicial = 0;
  int estadoAtual = 0;

  while (palavra[i] != '\0') {

    if (palavra[i] == 'a') {
      continue;
      // estadoAtual = a[];
    }

    i++;
  }

  if (estadoAtual == estadoAceitacao) {
    return 1;
  }

  return 0;
}

int tamArr(char array[])
{
  int tam = 0;
  while(array[tam] != '\0')
  {
    tam++;
  }
  return tam;
}

void constroi(char *palavra, char estados[SIZE][TAMPALAVRA],
              char a[SIZE][SIZE], char b[SIZE][SIZE]) {

  // Constroi estados

  estados[0][0] = 'e';
  estados[0][1] = 'p';
  estados[0][2] = 's';

  int tamPalavra = tamanhoPalavra(palavra); // tam = 5
  int j = tamPalavra;                       // j = 5

  for (int i = 1; i <= tamPalavra; i++) {

    for (int k = 0; k < (tamPalavra + 1) - j; k++) {
      estados[i][k] = palavra[k];
    }

    j--;
  }

  // Constroi resposta para 'a'

  tamPalavra = tamanhoPalavra(palavra); // tam = 5
  j = tamPalavra;                       // j = 5

// Copia o estados para o a
  for (int i = 1; i <= tamPalavra; i++) {
    for(int k = 0; k < tamArr(estados[i]); k++)
    {
      a[i][k] = estados[i][k];
      if(tamArr(estados[i]) - k == 1)
      {
        a[i][tamArr(estados[i])] = 'a';
        a[i][tamArr(estados[i])] = '\0'; // Acrescenta "\0" no final
      }
    }

  }

// Só para printar a matriz A
/*
  for (int i = 1; i <= tamPalavra; i++) {
    for(int k = 0; k < tamArr(estados[i]) + 1; k++)
    {
      printf("%c", a[i][k]);
    }
    printf("\n");
  }
  */

  // Copia o estados para o b
  for (int i = 1; i <= tamPalavra; i++) {
    for(int k = 0; k < tamArr(estados[i]); k++)
    {
      b[i][k] = estados[i][k];
      if(tamArr(estados[i]) - k == 1)
      {
        b[i][tamArr(estados[i])] = 'b'; // Acrescenta "b" no final
        b[i][tamArr(estados[i])] = '\0'; // Acrescenta "\0" no final
      }
    }

  }

// Só para printar a matriz B
/*
  for (int i = 1; i <= tamPalavra; i++) {
    for(int k = 0; k < tamArr(estados[i]) + 1; k++)
    {
      printf("%c", b[i][k]);
    }
    printf("\n");
  }
*/

  // Constroi resposta para 'b'
  
  tamPalavra = tamanhoPalavra(palavra); // tam = 5
  j = tamPalavra;                       // j = 5

  for (int i = 1; i <= tamPalavra; i++) {

    for (int k = 0; k < (tamPalavra + 1) - j; k++) {
      b[i][k] = palavra[k];
    }
    
    if(i == tamPalavra){
      continue;
    }else{
      b[i][tamPalavra +1 -j] =  'b';
    }
    
    j--;
  }
  
  int qtdA = sizeof(a) / sizeof(a[0]);
  // int qtdB = sizeof(b[0]) / sizeof(b[0][0]);
  int qtdB = tamArr(b[0]);
  int linhasEstados = tamPalavra + 1; 
  int colunasEstados = TAMPALAVRA;


  int teste = arrayEstaNaMatriz(estados, linhasEstados, colunasEstados, b[0], qtdB);
  
  printf("TESTE: %d\n", teste);
  
  printf("Estados:\n");
  for (int i = 0; i < tamanhoPalavra(palavra)+1; i++) {
    for (int j = 0; j < tamanhoPalavra(palavra); j++) {
      printf("%c", estados[i][j]);        
    }
    printf("\n");
  }
  printf("a:\n");
  for (int i = 0; i < tamanhoPalavra(palavra)+1; i++) {
    for (int j = 0; j < tamanhoPalavra(palavra)+1; j++) {
      printf("%c", a[i][j]);        
    }
    printf("\n");
  }
  printf("b:\n");
  for (int i = 0; i < tamanhoPalavra(palavra); i++) {
    for (int j = 0; j < tamanhoPalavra(palavra); j++) {
      printf("%c", b[i][j]);        
    }
    printf("\n");
  }
}

int main() {

  char palavra[TAMPALAVRA];
  char estados[SIZE][TAMPALAVRA];
  char a[SIZE][SIZE];
  char b[SIZE][SIZE];

  scanf("%s", &palavra);

  constroi(palavra, estados, a, b);

  return 0;
}