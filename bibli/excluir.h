#ifndef EXCLUIR_H_INCLUDED
#define EXCLUIR_H_INCLUDED

#define MAX_LINE_SIZE 150

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/excluirLinha.c"
#include "../utils/listFilByCodeExcluir.c"
#include "../utils/listFuncByCodeExcluir.c"
#include "../utils/listProdByCodeExcluir.c"

/* --------------------------- FILIAL ------------------------------- */

int verificarCodigoFilialExcluir(char *cod_fil)
{
  char arquivoDir[] = "filiais/arqfiliais.txt";
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

    if (strcmp(codigo, cod_fil) == 0)
    {
      listFilByCodeExcluir(linha, 1);
      match = 1;
      strcpy(linhaEncontrada, linha);
      return c;
      break;
    }
  
    c++;
  }

  if (match == 0)
  {

    printf("ERRO!! Nao foi encontrado filial com esse codigo\n");
    return -1;
  }

  fclose(aquivo);
}

void excluirFilial()
{

  char codigo[9];
  printf("-------------------------------------------\n");
  printf("|              EXCLUIR Filial             |\n");
  printf("-------------------------------------------\n\n");

  printf("DIGITE O CODIGO DA FILIAL: ");
  scanf(" %[^\n]s", codigo);

  int num_linha = verificarCodigoFilialExcluir(codigo);

  if (num_linha >= 0)
  {
    num_linha++;
    excluirLinha(num_linha, "filiais/arqfiliais.txt");
    printf("FILIAL EXCLUIDA!!\n\n");
  }
}

/* ------------------------ FUNCIONARIO ------------------------------- */

int verificarCodigoFuncionarioExcluir(char *cod_func)
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

    if (strcmp(codigo, cod_func) == 0)
    {
      listFuncByCodeExcluir(linha, 1);
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

  int num_linha = verificarCodigoFuncionarioExcluir(codigo);

  if (num_linha >= 0)
  {
    num_linha++;
    excluirLinha(num_linha, "funcionarios/arqfunc.txt");
    printf("FUNCIONARIO EXCLUIDO!!\n\n");
  }
}

/* --------------------------- PRODUTOS ------------------------------- */

int verificarCodigoProdMoveisExcluir(char *cod_Prod)
{
  char arquivoDir[] = "produtos/arqmoveis.txt";
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

    if (strcmp(codigo, cod_Prod) == 0)
    {
      listProdByCodeExcluir(linha, 1);
      match = 1;
      strcpy(linhaEncontrada, linha);
      return c;
      break;
    }
  
    c++;
  }

  if (match == 0)
  {

    printf("ERRO!! Nao foi encontrado filial com esse codigo\n");
    return -1;
  }

  fclose(aquivo);
}

int verificarCodigoProdEletroExcluir(char *cod_Prod)
{
  char arquivoDir[] = "produtos/arqeletro.txt";
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

    if (strcmp(codigo, cod_Prod) == 0)
    {
      listProdByCodeExcluir(linha, 1);
      match = 1;
      strcpy(linhaEncontrada, linha);
      return c;
      break;
    }
  
    c++;
  }

  if (match == 0)
  {

    printf("ERRO!! Nao foi encontrado filial com esse codigo\n");
    return -1;
  }

  fclose(aquivo);
}

int verificarCodigoProdCalcadosExcluir(char *cod_Prod)
{
  char arquivoDir[] = "produtos/arqcalcados.txt";
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

    if (strcmp(codigo, cod_Prod) == 0)
    {
      listProdByCodeExcluir(linha, 1);
      match = 1;
      strcpy(linhaEncontrada, linha);
      return c;
      break;
    }
  
    c++;
  }

  if (match == 0)
  {

    printf("ERRO!! Nao foi encontrado filial com esse codigo\n");
    return -1;
  }

  fclose(aquivo);
}

int verificarCodigoProdConfecExcluir(char *cod_Prod)
{
  char arquivoDir[] = "produtos/arqconfec.txt";
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

    if (strcmp(codigo, cod_Prod) == 0)
    {
      listProdByCodeExcluir(linha, 1);
      match = 1;
      strcpy(linhaEncontrada, linha);
      return c;
      break;
    }
  
    c++;
  }

  if (match == 0)
  {

    printf("ERRO!! Nao foi encontrado filial com esse codigo\n");
    return -1;
  }

  fclose(aquivo);
}

void excluirProduto()
{
  char nomearq[30];
  int op_prod;
  int num_linha;
  char codigo[9];

  printf("------------------------------------------------------------\n");
  printf("|  [1]MOVEIS [2]ELETRODOMESTICOS [3]CALCADOS [4]CONFECCAO  | \n");
  printf("------------------------------------------------------------\n\n\n");
  printf("QUAL DEPARTAMENTO DESEJA EXCLUIR?\n>>");
  scanf("%d", &op_prod);
  switch (op_prod)
  {
  case 1:
    system("cls");
    printf("|--------------------------|\n");
    printf("|  DEPARTAMENTO DE MOVEIS  |\n");
    printf("|--------------------------|\n");
    // strcpy(nomearq, "produtos/arqmoveis.txt");

    printf("----------------------------\n");
    printf("|      EXCLUIR PRODUTO     |\n");
    printf("----------------------------\n\n");

    printf("DIGITE O CODIGO DO PRODUTO: ");
    scanf(" %[^\n]s", codigo);

    num_linha = verificarCodigoProdMoveisExcluir(codigo);

    if (num_linha >= 0)
    {
      num_linha++;
      excluirLinha(num_linha, "produtos/arqmoveis.txt");
      printf("PRODUTO EXCLUIDO!!\n\n");
    }

    break;
  case 2:
    system("cls");
    printf("|------------------------------------|\n");
    printf("|  DEPARTAMENTO DE ELETRODOMESTICOS  |\n");
    printf("|------------------------------------|\n");
    // strcpy(nomearq, "produtos/arqeletro.txt");

    printf("--------------------------------------\n");
    printf("|           EXCLUIR PRODUTO          |\n");
    printf("--------------------------------------\n\n");

    printf("DIGITE O CODIGO DO PRODUTO: ");
    scanf(" %[^\n]s", codigo);

    num_linha = verificarCodigoProdEletroExcluir(codigo);

    if (num_linha >= 0)
    {
      num_linha++;
      excluirLinha(num_linha, "produtos/arqeletro.txt");
      printf("PRODUTO EXCLUIDO!!\n\n");
    }

    break;
  case 3:
    system("cls");
    printf("|----------------------------|\n");
    printf("|  DEPARTAMENTO DE CALCADOS  |\n");
    printf("|----------------------------|\n");
    // strcpy(nomearq, "produtos/arqcalcados.txt");

    printf("------------------------------\n");
    printf("|       EXCLUIR PRODUTO      |\n");
    printf("------------------------------\n\n");

    printf("DIGITE O CODIGO DO PRODUTO: ");
    scanf(" %[^\n]s", codigo);

    num_linha = verificarCodigoProdCalcadosExcluir(codigo);

    if (num_linha >= 0)
    {
      num_linha++;
      excluirLinha(num_linha, "produtos/arqcalcados.txt");
      printf("PRODUTO EXCLUIDO!!\n\n");
    }

    break;
  case 4:
    system("cls");
    printf("|-----------------------------|\n");
    printf("|  DEPARTAMENTO DE CONFECCAO  |\n");
    printf("|-----------------------------|\n");
    // strcpy(nomearq, "produtos/arqconfec.txt");

    printf("-------------------------------------------\n");
    printf("|             EXCLUIR PRODUTO             |\n");
    printf("-------------------------------------------\n\n");

    printf("DIGITE O CODIGO DO PRODUTO: ");
    scanf(" %[^\n]s", codigo);

    num_linha = verificarCodigoProdConfecExcluir(codigo);

    if (num_linha >= 0)
    {
      num_linha++;
      excluirLinha(num_linha, "produtos/arqconfec.txt");
      printf("PRODUTO EXCLUIDO!!\n\n");
    }

    break;
  default:
    break;
  }
}

//   char codigo[9];
//   printf("-------------------------------------------\n");
//   printf("|             EXCLUIR PRODUTO             |\n");
//   printf("-------------------------------------------\n\n");

//   printf("DIGITE O CODIGO DO PRODUTO: ");
//   scanf(" %[^\n]s", codigo);

//   int num_linha = verificarCodigoFunc(codigo);

//   if (num_linha >= 0)
//   {
//     num_linha++;
//     excluirLinha(num_linha, "funcionarios/arqfunc.txt");
//     printf("FUNCIONARIO EXCLUIDO!!\n\n");
//   }
// }


#endif