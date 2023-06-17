#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 150

char codigo[9];
char nome[50];
char cor[50];
char referencia[50];
char fornecedor[50];
char departamento[50];
char filial[50];
char quantidade[25];

char linhaEncontrada[MAX_LINE_SIZE];

void listProdByCodeAlterar(char *str, int show)
{
  char *token;

  // Primeira chamada: separa o primeiro token
  token = strtok(str, ":");

  // Enquanto houver tokens na string
  int i = 0;
  while (token != NULL)
  {
    switch (i)
    {
    case 0:
      strncpy(codigo, token, 8);
      codigo[8] = '\0';
      break;
    case 1:
      strncpy(nome, token, 49);
      nome[49] = '\0';
      break;
    case 2:
      strncpy(cor, token, 49);
      cor[49] = '\0';
      break;
    case 3:
      strncpy(referencia, token, 49);
      referencia[49] = '\0';
      break;
    case 4:
      strncpy(fornecedor, token, 49);
      fornecedor[49] = '\0';
      break;
    case 5:
      strncpy(departamento, token, 49);
      departamento[49] = '\0';
      break;
    case 6:
      strncpy(filial, token, 49);
      filial[49] = '\0';
      break;
    case 7:
      strncpy(quantidade, token, 24);
      quantidade[24] = '\0';
      break;
    }

    token = strtok(NULL, ":");
    i++;
  }

  if (show == 1)
  {
    printf("Codigo: %s\n", codigo);
    printf("Nome: %s\n", nome);
    printf("Cor: %s\n", cor);
    printf("Referencia: %s\n", referencia);
    printf("Fornecedor: %s\n", fornecedor);
    printf("Departamento: %s\n", departamento);
    printf("Filial: %s\n", filial);
    printf("Quantidade: %s\n", quantidade);
  }
}