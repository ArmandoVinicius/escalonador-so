#include <stdio.h>
#include <string.h>
#include "getValues.h"

char arr[3][2] = {"", "", ""};
int period[3] = {0, 0, 0};
int executionTime[3] = {0, 0, 0};
int deadline[3] = {0, 0, 0};

int main() {
  getValues("sistema1.txt", arr, period, executionTime, deadline);

  for (int i = 0; i < 3; i++)
  {
    printf("Processo: %s\n", arr[i]);
    printf("Periodo: %d\n", period[i]);
    printf("Tempo de execucao: %d\n", executionTime[i]);
    printf("Deadline: %d\n", deadline[i]);
    printf("--------------------\n");
  }
}