#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 150

char codigo[9];
char nome[50];
char rua[50];
char numero[5];
char bairro[50];
char cidade[50];
char estado[3];
char complemento[50];

char linhaEncontrada[MAX_LINE_SIZE];

/**
 * int show pode assumir 2 valore
 * 1: mostra qual foi o funcionario foi encontrado
 * 0: nao mostra o funcionario
 */
void listFilByCodeExcluir(char *str, int show)
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
      strncpy(rua, token, 49);
      rua[49] = '\0';
      break;
    case 3:
      strncpy(numero, token, 4);
      numero[4] = '\0';
      break;
    case 4:
      strncpy(bairro, token, 49);
      bairro[49] = '\0';
      break;
    case 5:
      strncpy(cidade, token, 49);
      cidade[49] = '\0';
      break;
    case 6:
      strncpy(estado, token, 2);
      estado[2] = '\0';
      break;
    case 7:
      strncpy(complemento, token, 49);
      complemento[49] = '\0';
      break;
    }

    token = strtok(NULL, ":");
    i++;
  }

  if (show == 1)
  {
    printf("Codigo: %s\n", codigo);
    printf("Nome: %s\n", nome);
    printf("Rua: %s\n", rua);
    printf("Numero: %s\n", numero);
    printf("Bairro: %s\n", bairro);
    printf("Cidade: %s\n", cidade);
    printf("Estado: %s\n", estado);
    printf("Complemento: %s\n", complemento);
  }
}