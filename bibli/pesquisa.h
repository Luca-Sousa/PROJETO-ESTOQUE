#ifndef PESQUISA_H_INCLUDED
#define PESQUISA_H_INCLUDED
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pesquisarFuncionario()
{
  FILE *arq;
  char linha[100], *busca, pesquisa[60];
  char cod_func[8], nome[60], cpf[12], tel[20], email[30], fil[20], rua[50], num[10],
      bairro[50], cid[50], est[50], comp[100];
  int idade, op;

  printf("----------------------------------------\n");
  printf("| [1]LISTAR TODOS [2] DIGITAR PESQUISA |\n");
  printf("----------------------------------------\n\n");
  printf("O QUE DESEJA FAZER: \n");
  scanf("%d", &op);
  switch (op)
  {
  case 1:
    strcpy(pesquisa, ":");
    break;
  case 2:
    printf("DIGITE A PALAVRA CHAVE PARA PESQUISA:\n");
    scanf(" %[^\n]s", pesquisa);
    break;

  default:
    break;
  }
  arq = fopen("funcionarios/arqfunc.txt", "r");
  if (arq == NULL)
  {
    printf("Erro ao abrir o arquivo!\n");
  }
  while (fgets(linha, 100, arq) != NULL)
  {

    if (strstr(linha, pesquisa) != NULL)
    {
      busca = strtok(linha, ":");
      if (busca != NULL)
      {
        strcpy(cod_func, busca);
        busca = strtok(NULL, ":");
      }
      if (busca != NULL)
      {
        strcpy(nome, busca);
        busca = strtok(NULL, ":");
      }

      if (busca != NULL)
      {
        strcpy(cpf, busca);
        busca = strtok(NULL, ":");
      }

      if (busca != NULL)
      {
        idade = atoi(busca);
        busca = strtok(NULL, ":");
      }
      if (busca != NULL)
      {
        strcpy(tel, busca);
        busca = strtok(NULL, ":");
      }

      if (busca != NULL)
      {
        strcpy(email, busca);
        busca = strtok(NULL, ":");
      }

      if (busca != NULL)
      {
        strcpy(fil, busca);
        busca = strtok(NULL, ":");
      }
      if (busca != NULL)
      {
        strcpy(rua, busca);
        busca = strtok(NULL, ":");
      }
      if (busca != NULL)
      {
        strcpy(num, busca);
        busca = strtok(NULL, ":");
      }

      if (busca != NULL)
      {
        strcpy(bairro, busca);
        busca = strtok(NULL, ":");
      }

      if (busca != NULL)
      {
        strcpy(cid, busca);
        busca = strtok(NULL, ":");
      }
      if (busca != NULL)
      {
        strcpy(est, busca);
        busca = strtok(NULL, ":");
      }
      if (busca != NULL)
      {
        strcpy(comp, busca);
      }

      printf("-----------------------------------------------------------------"
             "-----------------------------------------\n");
      printf("| CODIGO: %s  \n", cod_func);
      printf("| NOME: %s  \n", nome);
      printf("| CPF: %s  \n", cpf);
      printf("| IDADE: %d \n", idade);
      printf("| CONTATO: %s  \n", tel);
      printf("| EMAIL: %s  \n", email);
      printf("| FILIAL: %s  \n", fil);
      printf("| RUA: %s  \n", rua);
      printf("| NUMERO: %s  \n", num);
      printf("| BAIRRO: %s  \n", bairro);
      printf("| CIDADE: %s  \n", cid);
      printf("| ESTADO: %s  \n", est);
      printf("| COMPLEMENTO: %s  \n", comp);
      printf("-------------------------------------------------------------"
             "---------------------------------------------");
      printf("\n\n");
    }
  }

  char p;
  printf("CONTINUAR PESQUISANDO? S OU N");
  scanf("%s", &p);
  if ((p == 'S') || (p == 's'))
  {
    pesquisarFuncionario();
  }
  fclose(arq);
}

void pesquisarFilial()
{
  FILE *arq;
  char linha[100], *busca;
  char nome[60], rua[50], num[5], bairro[50], cid[40], est[30], comp[100];
  char pesquisa[60];
  int op;
  printf("----------------------------------------\n");
  printf("| [1]LISTAR TODOS [2] DIGITAR PESQUISA |\n");
  printf("----------------------------------------\n\n");
  printf("O QUE DESEJA FAZER: \n");
  scanf("%d", &op);
  switch (op)
  {
  case 1:
    strcpy(pesquisa, ":");
    break;
  case 2:
    printf("DIGITE A PALAVRA CHAVE PARA PESQUISA:\n");
    scanf(" %[^\n]s", pesquisa);
    break;

  default:
    break;
  }
  arq = fopen("filiais/arqfiliais.txt", "r");

  if (arq == NULL)
  {
    printf("Erro ao abrir o arquivo!\n");
  }
  while (fgets(linha, 100, arq) != NULL)
  {

    if (strstr(linha, pesquisa) != NULL)
    {
      busca = strtok(linha, ":");
      if (busca != NULL)
      {
        strcpy(nome, busca);
        busca = strtok(NULL, ":");
      }

      if (busca != NULL)
      {
        strcpy(rua, busca);
        busca = strtok(NULL, ":");
      }

      if (busca != NULL)
      {
        strcpy(num, busca);
        busca = strtok(NULL, ":");
      }
      if (busca != NULL)
      {
        strcpy(bairro, busca);
        busca = strtok(NULL, ":");
      }

      if (busca != NULL)
      {
        strcpy(cid, busca);
        busca = strtok(NULL, ":");
      }

      if (busca != NULL)
      {
        strcpy(est, busca);
        busca = strtok(NULL, ":");
      }
      if (busca != NULL)
      {
        strcpy(comp, busca);
      }
      printf("-----------------------------------------------------------------"
             "-----------------------------------------\n");
      printf("| NOME: %s  \n", nome);
      printf("| RUA: %s  \n", rua);
      printf("| NUMERO: %s  \n", num);
      printf("| BAIRRO: %s  \n", bairro);
      printf("| CIDADE: %s  \n", cid);
      printf("| ESTADO: %s  \n", est);
      printf("| COMPLEMENTO: %s\n", comp);
      printf("-------------------------------------------------------------"
             "---------------------------------------------");
      printf("\n\n");
    }
  }

  fclose(arq);
}
void pesquisarProduto()
{
  FILE *arq;
  char *cod_prod[8], linha[100], *busca, pesquisa[60], nomearq[30];
  char nome[60], ref[20], cor[30], dep[15], forn[25], fil[20];
  int qtde, opesq, op;

  printf("------------------------------------------------------------\n");
  printf("|  [1]MOVEIS [2]ELETRODOMESTICOS [3]CALCADOS [4]CONFECCAO  | \n");
  printf("------------------------------------------------------------\n\n\n");
  printf("QUAL DEPARTAMENTO DESEJA PESQUISAR?\n>>");
  scanf("%d", &opesq);
  switch (opesq)
  {
  case 1:
    system("cls");
    printf("|--------------------------|\n");
    printf("|  DEPARTAMENTO DE MOVEIS  |\n");
    printf("|--------------------------|\n");
    strcpy(nomearq, "produtos/arqmoveis.txt");
    break;
  case 2:
    system("cls");
    printf("|------------------------------------|\n");
    printf("|  DEPARTAMENTO DE ELETRODOMESTICOS  |\n");
    printf("|------------------------------------|\n");
    strcpy(nomearq, "produtos/arqeletro.txt");
    break;
  case 3:
    system("cls");
    printf("|----------------------------|\n");
    printf("|  DEPARTAMENTO DE CALCADOS  |\n");
    printf("|----------------------------|\n");
    strcpy(nomearq, "produtos/arqcalcados.txt");
    break;
  case 4:
    system("cls");
    printf("|-----------------------------|\n");
    printf("|  DEPARTAMENTO DE CONFECCAO  |\n");
    printf("|-----------------------------|\n");
    strcpy(nomearq, "produtos/arqconfec.txt");
    break;
  default:
    break;
  }
  printf("----------------------------------------\n");
  printf("| [1]LISTAR TODOS [2] DIGITAR PESQUISA |\n");
  printf("----------------------------------------\n\n");
  printf("O QUE DESEJA FAZER: \n");
  scanf("%d", &op);
  switch (op)
  {
  case 1:
    strcpy(pesquisa, ":");
    break;
  case 2:
    printf("DIGITE A PALAVRA CHAVE PARA PESQUISA:\n");
    scanf(" %[^\n]s", pesquisa);
    break;

  default:
    break;
  }
  arq = fopen(nomearq, "r");
  if (arq == NULL)
  {
    printf("Erro ao abrir o arquivo!\n");
  }
  while (fgets(linha, 100, arq) != NULL)
  {

    if (strstr(linha, pesquisa) != NULL)
    {
      busca = strtok(linha, ":");
      if (busca != NULL)
      {
        strcpy(cod_prod, busca);
        busca = strtok(NULL, ":");
      }
      if (busca != NULL)
      {
        strcpy(nome, busca);
        busca = strtok(NULL, ":");
      }

      if (busca != NULL)
      {
        strcpy(ref, busca);
        busca = strtok(NULL, ":");
      }

      if (busca != NULL)
      {
        strcpy(cor, busca);
        busca = strtok(NULL, ":");
      }
      if (busca != NULL)
      {
        strcpy(dep, busca);
        busca = strtok(NULL, ":");
      }

      if (busca != NULL)
      {
        strcpy(forn, busca);
        busca = strtok(NULL, ":");
      }

      if (busca != NULL)
      {
        strcpy(fil, busca);
        busca = strtok(NULL, ":");
      }
      if (busca != NULL)
      {
        qtde = atoi(busca);
      }
      printf("-----------------------------------------------------------------"
             "-----------------------------------------\n\n");
      printf("| CODIGO: %s  \n", cod_prod);
      printf("| NOME: %s  \n", nome);
      printf("| REFERENCIA: %s  \n", ref);
      printf("| COR: %s  \n", cor);
      printf("| DEPARTAMENTO: %s  \n", dep);
      printf("| FORNECEDOR: %s  \n", forn);
      printf("| FILIAL: %s  \n", fil);
      printf("| ESTOQUE: %d \n", qtde);
      printf("-------------------------------------------------------------"
             "---------------------------------------------");
      printf("\n\n");
    }
  }

  fclose(arq);
}
#endif