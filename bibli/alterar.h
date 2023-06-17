#ifndef ALTERAR_H_INCLUDED
#define ALTERAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/alterarLinha.c"
#include "../utils/listFilByCodeAlterar.c"
#include "../utils/listFuncByCodeAlterar.c"
#include "../utils/listProdByCodeAlterar.c"

#define MAX_LINE_SIZE 150

/* ------------------------ FILIAL ------------------------------- */

int verificarCodigoFilialAlterar(char *cod_fil)
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
      listFilByCodeAlterar(linha, 1);
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

void opcoesAlterarFil()
{
  int op;
  char new[50];

  printf("---------------------------------------------------------\n");
  printf("| [1]NOME     [2]RUA      [3]NUMERO    [4]BAIRRO       |\n");
  printf("| [5]CIDADE   [6]ESTADO   [7]COMPLEMENTO               |\n");
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
    printf("DIGITE A NOVA RUA: ");
    scanf(" %[^\n]s", new);
    strcpy(rua, new);
    break;
  case 3:
    printf("DIGITE O NOVO NUMERO: ");
    scanf(" %[^\n]s", new);
    strcpy(numero, new);
    break;
  case 4:
    printf("DIGITE O NOVO BAIRRO: ");
    scanf(" %[^\n]s", new);
    strcpy(bairro, new);
    break;
  case 5:
    printf("DIGITE A NOVA CIDADE: ");
    scanf(" %[^\n]s", new);
    strcpy(cidade, new);
    break;
  case 6:
    printf("DIGITE O NOVO ESTADO: ");
    scanf(" %[^\n]s", new);
    strcpy(estado, new);
    break;
  case 7:
    printf("DIGITE O NOVO COMPLEMENTO: ");
    scanf(" %[^\n]s", new);
    strcpy(complemento, new);
    break;
  default:
    printf("OPCAO INVALIDA: POR FAVOR DIGITE UMA OPCAO VALIDA\n\n");
    opcoesAlterarFil();
    break;
  }
}

void alterarFilial()
{
  char cod_fil[9];

  printf("DIGITE O CODIGO DA FILIAL: ");
  scanf(" %[^\n]s", cod_fil);

  int num_linha = verificarCodigoFilialAlterar(cod_fil);
  if (num_linha >= 0)
  {
    printf("numero da linha:  %d\n", num_linha);
  }

  char novaLinha[MAX_LINE_SIZE];
  novaLinha[0] = '\0';

  if (num_linha >= 0)
  {

    opcoesAlterarFil();

    strcat(novaLinha, codigo);
    strcat(novaLinha, ":");
    strcat(novaLinha, nome);
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
        "filiais/arqfiliais.txt",
        num_linha + 1,
        novaLinha);
  }
  else
  {
    alterarFilial();
  }
}

/* ------------------------ FUNCIONARIO ------------------------------- */

int verificarCodigoFuncionarioAlterar(char *cod_func)
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
      listFuncByCodeAlterar(linha, 1);
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

void opcoesAlterarfunc()
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
    opcoesAlterarfunc();
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

  int num_linha = verificarCodigoFuncionarioAlterar(cod_func);
  if (num_linha >= 0)
  {
    printf("numero da linha:  %d\n", num_linha);
  }

  char novaLinha[MAX_LINE_SIZE];
  novaLinha[0] = '\0';

  if (num_linha >= 0)
  {

    opcoesAlterarfunc();

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

/* ------------------------ PRODUTOS ------------------------------- */

int verificarCodigoProdMoveisAlterar(char *cod_Prod)
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
      listProdByCodeAlterar(linha, 1);
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

int verificarCodigoProdEletroAlterar(char *cod_Prod)
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
      listProdByCodeAlterar(linha, 1);
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

int verificarCodigoProdCalcadosAlterar(char *cod_Prod)
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
      listProdByCodeAlterar(linha, 1);
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

int verificarCodigoProdConfecAlterar(char *cod_Prod)
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
      listProdByCodeAlterar(linha, 1);
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

void opcoesAlterarProduto()
{
  int op;
  char new[50];

  printf("--------------------------------------------------------------------\n");
  printf("| [1]NOME           [2]COR      [3]REFERENCIA    [4]FORNECEDOR     |\n");
  printf("| [5]DEPARTAMENTO   [6]FILIAL   [7]QUANTIDADE                      |\n");
  printf("--------------------------------------------------------------------\n\n");
  printf("QUAL OPCAO DESEJA ALTERAR?");
  printf("\n>>");
  scanf("%d", &op);
  printf("\n\n");

  switch (op) {
    case 1:
      printf("DIGITE O NOVO NOME: ");
      scanf(" %[^\n]s", new);
      strcpy(nome, new);
      break;
    case 2:
      printf("DIGITE A NOVA COR: ");
      scanf(" %[^\n]s", new);
      strcpy(cor, new);
      break;
    case 3:
      printf("DIGITE A NOVA REFERENCIA: ");
      scanf(" %[^\n]s", new);
      strcpy(referencia, new);
      break;
    case 4:
      printf("DIGITE O NOVO FORNECEDOR: ");
      scanf(" %[^\n]s", new);
      strcpy(fornecedor, new);
      break;
    case 5:
      printf("DIGITE O NOVO DEPARTAMENTO: ");
      scanf(" %[^\n]s", new);
      strcpy(departamento, new);
      break;
    case 6:
      printf("DIGITE A NOVA FILIAL: ");
      scanf(" %[^\n]s", new);
      strcpy(filial, new);
      break;
    case 7:
      printf("DIGITE A NOVA  QUANTIDADE: ");
      scanf(" %[^\n]s", new);
      strcpy(quantidade, new);
      break;
    default:
      printf("OPCAO INVALIDA: POR FAVOR DIGITE UMA OPCAO VALIDA\n\n");
      opcoesAlterarProduto();
      break;
    }
}

void alterarProduto() {

  int op_prod;
  int num_linha;
  char cod_prod[9];
  char novaLinha[MAX_LINE_SIZE];

  printf("------------------------------------------------------------\n");
  printf("|  [1]MOVEIS [2]ELETRODOMESTICOS [3]CALCADOS [4]CONFECCAO  | \n");
  printf("------------------------------------------------------------\n\n\n");
  printf("QUAL DEPARTAMENTO DESEJA EXCLUIR?\n>>");
  scanf("%d", &op_prod);

  switch (op_prod) {

    case 1:
      system("cls");
      printf("|--------------------------|\n");
      printf("|  DEPARTAMENTO DE MOVEIS  |\n");
      printf("|--------------------------|\n");

      printf("----------------------------\n");
      printf("|      ALTERAR PRODUTO     |\n");
      printf("----------------------------\n\n");

      printf("DIGITE O CODIGO DO PRODUTO: ");
      scanf(" %[^\n]s", cod_prod);

      num_linha = verificarCodigoProdMoveisAlterar(cod_prod);

      novaLinha[0] = '\0';

      if (num_linha >= 0) {

        opcoesAlterarProduto();

        strcat(novaLinha, codigo);
        strcat(novaLinha, ":");
        strcat(novaLinha, nome);
        strcat(novaLinha, ":");
        strcat(novaLinha, cor);
        strcat(novaLinha, ":");
        strcat(novaLinha, referencia);
        strcat(novaLinha, ":");
        strcat(novaLinha, fornecedor);
        strcat(novaLinha, ":");
        strcat(novaLinha, departamento);
        strcat(novaLinha, ":");
        strcat(novaLinha, filial);
        strcat(novaLinha, ":");
        strcat(novaLinha, quantidade);
        strcat(novaLinha, "\n");

        alterarLinha(
            "produtos/arqmoveis.txt",
            num_linha + 1,
            novaLinha);
      }
      else {
        alterarProduto();
      }

      break;

    case 2:
      system("cls");
      printf("|------------------------------------|\n");
      printf("|  DEPARTAMENTO DE ELETRODOMESTICOS  |\n");
      printf("|------------------------------------|\n");

      printf("--------------------------------------\n");
      printf("|           ALTERAR PRODUTO          |\n");
      printf("--------------------------------------\n\n");

      printf("DIGITE O CODIGO DO PRODUTO: ");
      scanf(" %[^\n]s", cod_prod);

      num_linha = verificarCodigoProdEletroAlterar(cod_prod);

      novaLinha[0] = '\0';

      if (num_linha >= 0) {

        opcoesAlterarProduto();

        strcat(novaLinha, codigo);
        strcat(novaLinha, ":");
        strcat(novaLinha, nome);
        strcat(novaLinha, ":");
        strcat(novaLinha, cor);
        strcat(novaLinha, ":");
        strcat(novaLinha, referencia);
        strcat(novaLinha, ":");
        strcat(novaLinha, fornecedor);
        strcat(novaLinha, ":");
        strcat(novaLinha, departamento);
        strcat(novaLinha, ":");
        strcat(novaLinha, filial);
        strcat(novaLinha, ":");
        strcat(novaLinha, quantidade);
        strcat(novaLinha, "\n");

        alterarLinha(
            "produtos/arqeletro.txt",
            num_linha + 1,
            novaLinha);
      }
      else {
        alterarProduto();
      }

      break;
    
    case 3:
      system("cls");
      printf("|----------------------------|\n");
      printf("|  DEPARTAMENTO DE CALCADOS  |\n");
      printf("|----------------------------|\n");

      printf("------------------------------\n");
      printf("|       ALTERAR PRODUTO      |\n");
      printf("------------------------------\n\n");

      printf("DIGITE O CODIGO DO PRODUTO: ");
      scanf(" %[^\n]s", cod_prod);

      num_linha = verificarCodigoProdCalcadosAlterar(cod_prod);

      novaLinha[0] = '\0';

      if (num_linha >= 0) {

        opcoesAlterarProduto();

        strcat(novaLinha, codigo);
        strcat(novaLinha, ":");
        strcat(novaLinha, nome);
        strcat(novaLinha, ":");
        strcat(novaLinha, cor);
        strcat(novaLinha, ":");
        strcat(novaLinha, referencia);
        strcat(novaLinha, ":");
        strcat(novaLinha, fornecedor);
        strcat(novaLinha, ":");
        strcat(novaLinha, departamento);
        strcat(novaLinha, ":");
        strcat(novaLinha, filial);
        strcat(novaLinha, ":");
        strcat(novaLinha, quantidade);
        strcat(novaLinha, "\n");

        alterarLinha(
            "produtos/arqcalcados.txt",
            num_linha + 1,
            novaLinha);
      }
      else {
        alterarProduto();
      }

      break;
    
    case 4:
      system("cls");
      printf("|-----------------------------|\n");
      printf("|  DEPARTAMENTO DE CONFECCAO  |\n");
      printf("|-----------------------------|\n");

      printf("-------------------------------\n");
      printf("|       ALTERAR PRODUTO       |\n");
      printf("-------------------------------\n\n");

      printf("DIGITE O CODIGO DO PRODUTO: ");
      scanf(" %[^\n]s", cod_prod);

      num_linha = verificarCodigoProdConfecAlterar(cod_prod);

      novaLinha[0] = '\0';

      if (num_linha >= 0) {

        opcoesAlterarProduto();

        strcat(novaLinha, codigo);
        strcat(novaLinha, ":");
        strcat(novaLinha, nome);
        strcat(novaLinha, ":");
        strcat(novaLinha, cor);
        strcat(novaLinha, ":");
        strcat(novaLinha, referencia);
        strcat(novaLinha, ":");
        strcat(novaLinha, fornecedor);
        strcat(novaLinha, ":");
        strcat(novaLinha, departamento);
        strcat(novaLinha, ":");
        strcat(novaLinha, filial);
        strcat(novaLinha, ":");
        strcat(novaLinha, quantidade);
        strcat(novaLinha, "\n");

        alterarLinha(
            "produtos/arqconfec.txt",
            num_linha + 1,
            novaLinha);
      }
      else {
        alterarProduto();
      }

      break;

    default:
      break;
  }

}

#endif