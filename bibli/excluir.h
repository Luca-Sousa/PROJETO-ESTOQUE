#ifndef EXCLUIR_H_INCLUDED
#define EXCLUIR_H_INCLUDED

#define MAX_LINE_SIZE 150

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/excluirLinha.c"
#include "../utils/listFilByCodeExcluir.c"
#include "../utils/listFuncByCodeExcluir.c"

int verificarCodigoFunc(char *cod_func)
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

  int num_linha = verificarCodigoFunc(codigo);

  if (num_linha >= 0)
  {
    num_linha++;
    excluirLinha(num_linha, "funcionarios/arqfunc.txt");
    printf("FUNCIONARIO EXCLUIDO!!\n\n");
  }
}

//-------------------------------------------------------------------------------------------------//

int verificarCodigoFil(char *cod_fil)
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

  int num_linha = verificarCodigoFil(codigo);

  if (num_linha >= 0)
  {
    num_linha++;
    excluirLinha(num_linha, "filiais/arqfiliais.txt");
    printf("FILIAL EXCLUIDA!!\n\n");
  }
}

#endif