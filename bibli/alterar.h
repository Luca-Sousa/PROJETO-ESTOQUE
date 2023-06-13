#ifndef ALTERAR_H_INCLUDED
#define ALTERAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/alterarLinha.c"

#define MAX_LINE_SIZE 150

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
void listFuncByCode(char *str, int show)
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

int verificarCodigo(char *cod_func)
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
      listFuncByCode(linha, 1);
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

void opcoesAlterar()
{
  int op;
  char new[50];

  printf("---------------------------------------------------------\n");
  printf("| [1]NOME     [2]CPF      [3]IDADE    [4]TELEFONE       |\n");
  printf("| [5]EMAIL    [6]FILIAL   [7]RUA      [8]NUMERO         |\n");
  printf("| [9]BAIRRO   [10]CIDADE  [11]ESTADO  [12]COMPLEMENTO   |\n");
  printf("---------------------------------------------------------\n\n");
  printf("QUAL OPCAO DESEJA ALTERAR?");
  printf("\n>>");
  scanf("%d", &op);
  printf("\n\n");
  switch (op)
  {
  case 1:
    printf("DIGITE O NOVO NOME: ");
    scanf(" %[^\n]s", new);
    strcpy(nome, new);
    break;
  case 2:
    printf("DIGITE O NOVO CPF: ");
    scanf(" %[^\n]s", new);
    strcpy(cpf, new);
    break;
  case 3:
    printf("DIGITE A NOVA IDADE: ");
    scanf(" %[^\n]s", new);
    strcpy(idade, new);
    break;
  case 4:
    printf("DIGITE O NOVO TELEFONE: ");
    scanf(" %[^\n]s", new);
    strcpy(tel, new);
    break;
  case 5:
    printf("DIGITE O NOVO EMAIL: ");
    scanf(" %[^\n]s", new);
    strcpy(email, new);
    break;
  case 6:
    printf("DIGITE A NOVA FILIAL: ");
    scanf(" %[^\n]s", new);
    strcpy(filial, new);
    break;
  case 7:
    printf("DIGITE A NOVA RUA: ");
    scanf(" %[^\n]s", new);
    strcpy(rua, new);
    break;
  case 8:
    printf("DIGITE O NOVO NUMERO: ");
    scanf(" %[^\n]s", new);
    strcpy(numero, new);
    break;
  case 9:
    printf("DIGITE O NOVO BAIRRO: ");
    scanf(" %[^\n]s", new);
    strcpy(bairro, new);
    break;
  case 10:
    printf("DIGITE A NOVA CIDADE: ");
    scanf(" %[^\n]s", new);
    strcpy(cidade, new);
    break;
  case 11:
    printf("DIGITE O NOVO ESTADO: ");
    scanf(" %[^\n]s", new);
    strcpy(estado, new);
    break;
  case 12:
    printf("DIGITE O NOVO COMPLEMENTO: ");
    scanf(" %[^\n]s", new);
    strcpy(complemento, new);
    break;
  default:
    printf("OPCAO INVALIDA: POR FAVOR DIGITE UMA OPCAO VALIDA\n\n");
    opcoesAlterar();
    break;
  }

  // char ops;

  // printf("DESEJA ALTERAR MAIS ALGUMA COISA? S/N: ");
  // scanf("%c", &ops);

  // if ((ops == 'S') || (ops == 's'))
  // {
  //   opcoesAlterar();
  // }
}

void alterarFuncionario()
{
  char cod_func[9];

  printf("DIGITE O CODIGO DO FUNCIONARIO: ");
  scanf(" %[^\n]s", cod_func);

  int num_linha = verificarCodigo(cod_func);
  if (num_linha >= 0)
  {
    printf("numero da linha:  %d\n", num_linha);
  }

  char novaLinha[MAX_LINE_SIZE];
  novaLinha[0] = '\0';

  if (num_linha >= 0)
  {

    opcoesAlterar();

    strcat(novaLinha, codigo);
    strcat(novaLinha, ":");
    strcat(novaLinha, nome);
    strcat(novaLinha, ":");
    strcat(novaLinha, cpf);
    strcat(novaLinha, ":");
    strcat(novaLinha, idade);
    strcat(novaLinha, ":");
    strcat(novaLinha, tel);
    strcat(novaLinha, ":");
    strcat(novaLinha, email);
    strcat(novaLinha, ":");
    strcat(novaLinha, filial);
    strcat(novaLinha, ":");
    strcat(novaLinha, rua);
    strcat(novaLinha, ":");
    strcat(novaLinha, numero);
    strcat(novaLinha, ":");
    strcat(novaLinha, bairro);
    strcat(novaLinha, ":");
    strcat(novaLinha, cidade);
    strcat(novaLinha, ":");
    strcat(novaLinha, estado);
    strcat(novaLinha, ":");
    strcat(novaLinha, complemento);
    strcat(novaLinha, "\n");
    alterarLinha(
        "funcionarios/arqfunc.txt",
        num_linha + 1,
        novaLinha);
  }
  else
  {
    alterarFuncionario();
  }
}

#endif