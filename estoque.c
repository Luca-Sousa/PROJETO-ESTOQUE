#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibli/structs.h"
#include "bibli/aloc.h"
#include "bibli/ler.h"
#include "bibli/grava.h"
#include "bibli/pesquisa.h"
#include "bibli/alterar.h"

// chamada do prototipo da funcao menu
void menuInicio();

// funcao principal
int main(void)
{
    menuInicio();
    return 0;
}

// funcao de menu e tela de inicio
void menuInicio()
{
    int op, op1;
    pfil gravfil;
    pfunc gravfunc;
    pprod gravprod;
    char opcao;

    do
    {
        system("cls");
        printf("-------------------------------------------------------------------------------------\n");
        printf("|                                ESTOQUE SEM ESTOQUE                                |\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("| [1]TRANSFERIR [2]PESQUISAR [3]ALTERAR [4]CADASTRAR [5]EXCLUIR [9]FECHAR [0]LOGIN  |\n");
        printf("-------------------------------------------------------------------------------------\n\n");
        printf("O QUE DESEJA FAZER? : ");
        scanf("%d", &op);
        system("cls");

        switch (op)
        {
        case 1:
            break;
        case 2:
            printf("-------------------------------------------------------------------------\n");
            printf("|                           OPCOES DE PESQUISA                          |\n");
            printf("-------------------------------------------------------------------------\n");
            printf("| [1]PESQUISAR FILIAL   [2]PESQUISAR FUNCIONARIO  [3]PESQUISAR PRODUTO  |\n");
            printf("-------------------------------------------------------------------------\n\n");
            printf("QUAL OPCAO DESEJA PESQUISAR?");
            printf("\n>>");
            scanf("%d", &op1);
            system("cls");
            switch (op1)
            {
            case 1:
                pesquisarFilial();
                printf("DESEJA CONTINUAR?\nS OU N: ");
                scanf("%s", &opcao);
                printf("\n");
                if ((opcao == 's') || (opcao == 'S'))
                {
                    op = 0;
                }
                else
                {
                    op = -1;
                    printf("\n\nSISTEMA ENCERRADO!");
                }
                printf("\n");
                break;
            case 2:
                pesquisarFuncionario();
                printf("DESEJA CONTINUAR?\nS OU N: ");
                scanf("%s", &opcao);
                printf("\n");
                if ((opcao == 's') || (opcao == 'S'))
                {
                    op = 0;
                }
                else
                {
                    op = -1;
                    printf("\n\nSISTEMA ENCERRADO!");
                }
                printf("\n");
                break;
            case 3:
                pesquisarProduto();
                printf("DESEJA CONTINUAR?\nS OU N: ");
                scanf("%s", &opcao);
                printf("\n");
                if ((opcao == 's') || (opcao == 'S'))
                {
                    op = 0;
                }
                else
                {
                    op = -1;
                    printf("\n\nSISTEMA ENCERRADO!");
                }
                printf("\n");
            }
            break;
        case 3:
            printf("-------------------------------------------------------------------------\n");
            printf("|                           OPCOES DE ALTERACAO                          |\n");
            printf("-------------------------------------------------------------------------\n");
            printf("| [1]ALTERAR FILIAL   [2]ALTERAR FUNCIONARIO  [3]ALTERAR PRODUTO  |\n");
            printf("-------------------------------------------------------------------------\n\n");
            printf("QUAL OPCAO DESEJA ALTERAR?");
            printf("\n>>");
            scanf("%d", &op1);
            system("cls");

            switch (op1)
            {
            case 1:
                break;
            case 2:
                alterarFuncionario();
                printf("DESEJA CONTINUAR?\nS OU N: ");
                scanf("%s", &opcao);
                printf("\n");
                if ((opcao == 's') || (opcao == 'S'))
                {
                    op = 0;
                }
                else
                {
                    op = -1;
                    printf("\n\nSISTEMA ENCERRADO!");
                }
                printf("\n");
                break;
            case 3:
                break;
            }

            break;
        case 4:
            printf("-------------------------------------------\n");
            printf("|           OPCOES DE CADASTRO            |\n");
            printf("-------------------------------------------\n");
            printf("| [1]FILIAL   [2]FUNCIONARIO  [3]PRODUTO  |\n");
            printf("-------------------------------------------\n\n");
            printf("QUAL OPCAO DESEJA CADASTRAR?");
            printf("\n>>");
            scanf("%d", &op1);
            system("cls");
            switch (op1)
            {
            case 1:
                printf("-------------------------------------------\n");
                printf("|           CADASTRO DA FILIAL            |\n");
                printf("-------------------------------------------\n");
                printf("DIGITE OS DADOS!\n");
                gravfil = alocaFilial();
                lerFilial(gravfil);
                gravaFilial(gravfil);
                printf("DESEJA CONTINUAR?\nS OU N: ");
                scanf("%s", &opcao);
                printf("\n");
                if ((opcao == 's') || (opcao == 'S'))
                {
                    op = 0;
                }
                else
                {
                    op = -1;
                    printf("\n\nSISTEMA ENCERRADO!");
                }
                printf("\n");
                break;
            case 2:
                printf("-------------------------------------------\n");
                printf("|        CADASTRO DO FUNCIONARIO          |\n");
                printf("-------------------------------------------\n");
                printf("DIGITE OS DADOS!\n");
                gravfunc = alocaFuncionario();
                lerFuncionario(gravfunc);
                gravaFuncionario(gravfunc);
                printf("DESEJA CONTINUAR?\nS OU N: ");
                scanf("%s", &opcao);
                printf("\n");
                if ((opcao == 's') || (opcao == 'S'))
                {
                    op = 0;
                }
                else
                {
                    op = -1;
                    printf("\n\nSISTEMA ENCERRADO!");
                }
                printf("\n");
                break;
            case 3:
                printf("-------------------------------------------\n");
                printf("|           CADASTRO DO PRODUTO           |\n");
                printf("-------------------------------------------\n");
                printf("DIGITE OS DADOS!\n");
                gravprod = alocaProduto();
                lerProduto(gravprod);
                gravaProduto(gravprod);
                printf("DESEJA CONTINUAR?\nS OU N: ");
                scanf("%s", &opcao);
                printf("\n");
                if ((opcao == 's') || (opcao == 'S'))
                {
                    op = 0;
                }
                else
                {
                    op = -1;
                    printf("\n\nSISTEMA ENCERRADO!");
                }
                printf("\n");

                break;
            }
            break;
        case 5:
            printf("-------------------------------------------\n");
            printf("|           OPCOES PARA EXCLUIR           |\n");
            printf("-------------------------------------------\n");
            printf("| [1]FILIAL   [2]FUNCIONARIO  [3]PRODUTO  |\n");
            printf("-------------------------------------------\n\n");
            break;
        case 9:

            op = -1;
            printf("SISTEMA ENCERRADO!");
            break;
        case 0:

            break;
        default:
            printf("DESEJA TENTAR NOVAMENTE?\nS OU N: ");
            scanf("%s", &opcao);
            printf("\n");

            if ((opcao == 's') || (opcao == 'S'))
            {
                op = 0;
            }
            else
            {
                op = -1;
                printf("\n\nSISTEMA ENCERRADO!");
            }
            break;
        }
        printf("");
    } while (op != -1);
}
