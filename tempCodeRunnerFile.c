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