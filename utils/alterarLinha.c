#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 150

int alterarLinha(char *nome_arquivo, int num_linha, char *nova_linha)
{
  FILE *arquivo;
  char **linhas = NULL;
  char linha[MAX_LINE_SIZE];
  int num_linhas, i;

  arquivo = fopen(nome_arquivo, "r");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return -1;
  }

  num_linhas = 0;
  while (fgets(linha, MAX_LINE_SIZE, arquivo) != NULL)
  {
    linhas = (char **)realloc(linhas, (num_linhas + 1) * sizeof(char *));
    linhas[num_linhas] = (char *)malloc((strlen(linha) + 1) * sizeof(char));
    strcpy(linhas[num_linhas], linha);
    num_linhas++;
  }

  fclose(arquivo);

  if (num_linha < 1 || num_linha > num_linhas)
  {
    printf("Número de linha inválido.\n");
    return -1;
  }

  strcpy(linhas[num_linha - 1], nova_linha);

  arquivo = fopen(nome_arquivo, "w");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return -1;
  }

  for (i = 0; i < num_linhas; i++)
  {
    fputs(linhas[i], arquivo);
    fprintf(arquivo, "\n");
  }
  fprintf(arquivo, "\n");

  fclose(arquivo);

  for (i = 0; i < num_linhas; i++)
  {
    free(linhas[i]);
  }
  free(linhas);

  return 0;
}
