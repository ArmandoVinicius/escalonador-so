#include <stdio.h>
#include <string.h>

int main() {
  // Vetores para armazenar os valores
  char arr[3][2] = {"", "", ""};
  int period[3] = {0, 0, 0};
  int executionTime[3] = {0, 0, 0};
  int deadline[3] = {0, 0, 0};

  // Variáveis auxiliares para armazenar temporariamente os valores lidos
  // e para percores os 'vetores' (Estou considerando os valores de periodo,
  // tempo de execução e deadline como um vetor 3x3 e percorrendo ele para pegar os valores)
  int genericNumber;
  int counter = 0;
  int index = 0;

  // Abrindo o arquivo
  FILE *fp = fopen("sistema3.txt", "r");

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

    // Imprimindo os valores na tela
    for (int i = 0; i < 3; i++)
    {
      printf("Processo: %s\n", arr[i]);
      printf("Periodo: %d\n", period[i]);
      printf("Tempo de execucao: %d\n", executionTime[i]);
      printf("Deadline: %d\n", deadline[i]);
      printf("--------------------\n");
    }

    // Fechando o arquivo
    fclose(fp);
    printf("Arquivo fechado\n");
  }

  return 0;
}