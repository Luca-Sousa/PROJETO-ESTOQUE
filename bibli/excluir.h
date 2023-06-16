#ifndef EXCLUIR_H_INCLUDED
#define EXCLUIR_H_INCLUDED

#define MAX_LINE_SIZE 150

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/excluirLinha.c"

char codigo[9];
char nome[50];
char cpf[9];
char idade[3];
char tel[12];
char email[50];
char filial[50];
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
void listFuncByCode1(char *str, int show)
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
      strncpy(cpf, token, 8);
      cpf[8] = '\0';
      break;
    case 3:
      strncpy(idade, token, 2);
      idade[2] = '\0';
      break;
    case 4:
      strncpy(tel, token, 11);
      tel[11] = '\0';
      break;
    case 5:
      strncpy(email, token, 49);
      email[49] = '\0';
      break;
    case 6:
      strncpy(filial, token, 49);
      filial[49] = '\0';
      break;
    case 7:
      strncpy(rua, token, 49);
      rua[49] = '\0';
      break;
    case 8:
      strncpy(numero, token, 4);
      numero[4] = '\0';
      break;
    case 9:
      strncpy(bairro, token, 49);
      bairro[49] = '\0';
      break;
    case 10:
      strncpy(cidade, token, 49);
      cidade[49] = '\0';
      break;
    case 11:
      strncpy(estado, token, 2);
      estado[2] = '\0';
      break;
    case 12:
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
    printf("Cpf: %s\n", cpf);
    printf("Idade: %s\n", idade);
    printf("Telefone: %s\n", tel);
    printf("E-mail: %s\n", email);
    printf("Filial: %s\n", filial);
    printf("Rua: %s\n", rua);
    printf("Numero: %s\n", numero);
    printf("Bairro: %s\n", bairro);
    printf("Cidade: %s\n", cidade);
    printf("Estado: %s\n", estado);
    printf("Complemento: %s\n", complemento);
  }
}

int verificarCodigo1(char *cod_func)
{
  char arquivoDir[] = "funcionarios/arqfunc.txt";
  FILE *aquivo = fopen(arquivoDir, "r");

  if (aquivo == NULL)
  {
    printf("Erro ao abrir o arquivo: %s\n", arquivoDir);
    return 0;
  }

  char linha[MAX_LINE_SIZE];
  char codigo[9];
  int match = 0;

  int c = 0;
  while (fgets(linha, MAX_LINE_SIZE, aquivo) != NULL)
  {
    char *pos = strchr(linha, '\n');
    if (pos != NULL)
    {
      *pos = '\0';
    }

    strncpy(codigo, linha, 8);
    codigo[8] = '\0';

    // printf("CODIGOS: %s\n", codigo);
    if (strcmp(codigo, cod_func) == 0)
    {
      listFuncByCode1(linha, 1);
      match = 1;
      strcpy(linhaEncontrada, linha);
      return c;
      break;
    }
  
    c++;
  }

  if (match == 0)
  {

    printf("ERRO!! Nao foi encontrado funcionario com esse codigo\n");
    return -1;
  }

  fclose(aquivo);
}

void excluirFuncionario()
{

  char codigo[9];
  printf("-------------------------------------------\n");
  printf("|           EXCLUIR FUNCIONARIO           |\n");
  printf("-------------------------------------------\n\n");

  printf("DIGITE O CODIGO DO FUNCIONARIO: ");
  scanf(" %[^\n]s", codigo);

  int num_linha = verificarCodigo1(codigo);

  if (num_linha >= 0)
  {
    num_linha++;
    excluirLinha(num_linha, "funcionarios/arqfunc.txt");
    printf("FUNCIONARIO EXCLUIDO!!\n\n");
  }
}

#endif