#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void excluirLinha(int num_linha, char *arquivo)
{
  FILE *arquivoOriginal;
  FILE *arquivoTemporario;
  char linha[150];
  int linhaAtual = 1;

  // Abrir o arquivo original em modo leitura
  arquivoOriginal = fopen(arquivo, "r");
  if (arquivoOriginal == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  // Abrir o arquivo temporário em modo escrita
  arquivoTemporario = fopen("temp.txt", "w");
  if (arquivoTemporario == NULL)
  {
    printf("Erro ao abrir o arquivo temporario.\n");
    fclose(arquivoOriginal);
    return;
  }

  // Ler linha por linha do arquivo original
  while (fgets(linha, sizeof(linha), arquivoOriginal))
  {
    // Verificar se é a linha que queremos excluir
    if (linhaAtual != num_linha)
    {
      // Copiar a linha para o arquivo temporário
      fputs(linha, arquivoTemporario);
    }
    linhaAtual++;
  }

  // Fechar os arquivos
  fclose(arquivoOriginal);
  fclose(arquivoTemporario);

  // Reabrir o arquivo original em modo escrita
  arquivoOriginal = fopen(arquivo, "w");
  if (arquivoOriginal == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  // Reabrir o arquivo temporário em modo leitura
  arquivoTemporario = fopen("temp.txt", "r");
  if (arquivoTemporario == NULL)
  {
    printf("Erro ao abrir o arquivo temporario.\n");
    fclose(arquivoOriginal);
    return;
  }

  // Copiar o conteúdo do arquivo temporário para o arquivo original
  while (fgets(linha, sizeof(linha), arquivoTemporario))
  {
    fputs(linha, arquivoOriginal);
  }

  // Fechar os arquivos novamente
  fclose(arquivoOriginal);
  fclose(arquivoTemporario);

  // Remover o arquivo temporário
  remove("temp.txt");

  printf("\nLinha excluida com sucesso.\n");
}