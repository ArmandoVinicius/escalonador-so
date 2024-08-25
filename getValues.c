#include "getValues.h"
#include <stdio.h>
#include <string.h>

// Inicialização dos vetores para armazenar os valores dos parâmetros de cada processo

int getValues(char* filename, char arr[][2], int period[], int executionTime[], int deadline[]) {
  // Variáveis auxiliares para armazenar temporariamente os valores lidos
  // e para percores os 'vetores' (Estou considerando os valores de periodo,
  // tempo de execução e deadline como um vetor 3x3 e percorrendo ele para pegar os valores)
  int genericNumber;
  int counter = 0;
  int index = 0;

  // Abrindo o arquivo
  FILE *fp = fopen(filename, "r");

  if(fp == NULL) {
    printf("Erro na abertura do arquivo\n");
  } else {
    // Lendo os nomes dos processos
    for(int j = 0; j < 3; j++) {
      fscanf(fp, "%s", arr[j]);
    }

    // É necessário fazer essa separação, pois a primeira linha contém
    // valores "Char" e as demais contém valores "Int"

    // Lendo os valores de periodo, tempo de execucao e deadline
    while(fscanf(fp, "%d", &genericNumber) == 1) {
      switch (counter) {
        case 0:
          // Se counter == 0, significa que estamos na primeira linha
          // ou seja, a linha que tem os valores de periodo
          period[index] = genericNumber;
          break;
        case 1:
          // Se counter == 1, significa que estamos na linha dos tempos de execucao
          executionTime[index] = genericNumber;
          break;
        case 2:
          // Se counter == 2, significa que estamos na linha dos deadlines
          deadline[index] = genericNumber;
          break;
        default:
          printf("Erro\n");
          break;
      }
      
      // Usando as variáveis para percorer os 'vetores'
      // Index é equivalente a coluna e counter a linha
      // Quando index chegar a 3, significa que os valores que indicam
      // o mesmo parâmetro já foram lidos, então incrementamos o counter
      // para seguir para o próximo parâmetro (Parâmetros: Periodo, Tempo de Exec, Deadline)
      index++;
      if (index == 3) {
        index = 0;
        
        counter++;
      }
    }

    // Fechando o arquivo
    fclose(fp);
    printf("Arquivo fechado\n");
  }

  return 0;
}