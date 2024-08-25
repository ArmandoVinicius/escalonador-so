#include <stdio.h>
#include <string.h>
#include "getValues.h"
#include "values.h"

int main() {
  int funcResult = getValues("sistema1.txt");

  if (funcResult == -1) {
    return 0;
  } else if (funcResult == -2) {
    return 0;
  }

  for (int i = 0; i < 3; i++)
  {
    printf("Processo: %s\n", arr[i]);
    printf("Periodo: %d\n", period[i]);
    printf("Tempo de execucao: %d\n", executionTime[i]);
    printf("Deadline: %d\n", deadline[i]);
    printf("--------------------\n");
  }
}