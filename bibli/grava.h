#ifndef GRAVA_H_INCLUDED
#define GRAVA_H_INCLUDED

// grava no arquivo dados da Filial
void gravaFilial(pfil fcad) {
  FILE *arq_gra;
  arq_gra = fopen("filiais/arqfiliais.txt", "a");
  if (arq_gra == NULL) {
    printf("ATENCAO! CADASTRO NAO CONCLUIDO!");
  } else {
    printf("\n\nCADASTRO CONCLUIDO!\n\n");
  }
  fprintf(arq_gra, "%s:%s:%s:%s:%s:%s:%s", fcad->nome_fil, fcad->rua_fil,
          fcad->num_fil, fcad->bairro_fil, fcad->cid_fil, fcad->est_fil,
          fcad->comp_fil);
  fprintf(arq_gra, "\n");
  fclose(arq_gra);
}

void gravaProduto(pprod fcad) {
  FILE *arq_gra;
  char *dep = fcad->dep_prod;

  if (strcmp(dep, "MOVEIS") == 0 || strcmp(dep, "moveis") == 0 ||
      strcmp(dep, "Moveis") == 0) {
    arq_gra = fopen("produtos/arqmoveis.txt", "a");
    if (arq_gra == NULL) {
      printf("ATENCAO! CADASTRO NAO CONCLUIDO!");
    } else {
      printf("\n\nCADASTRO CONCLUIDO!\n\n");
    }
    fprintf(arq_gra, "%s:%s:%s:%s:%s:%s:%d", fcad->nome_prod, fcad->ref_prod,
            fcad->cor_prod, fcad->dep_prod, fcad->forn_prod, fcad->fil_prod,
            fcad->qtde_prod);
    fprintf(arq_gra, "\n");
    fclose(arq_gra);

  } else if (strcmp(dep, "ELETRO") == 0 || strcmp(dep, "Eletro") == 0 ||
             strcmp(dep, "eletro") == 0 ||
             strcmp(dep, "ELETRODOMESTICOS") == 0 ||
             strcmp(dep, "Eletrodomesticos") == 0 ||
             strcmp(dep, "eletrodomesticos") == 0) {
    arq_gra = fopen("produtos/arqeletro.txt", "a");
    if (arq_gra == NULL) {
      printf("ATENCAO! CADASTRO NAO CONCLUIDO!");
    } else {
      printf("\n\nCADASTRO CONCLUIDO!\n\n");
    }
    fprintf(arq_gra, "%s:%s:%s:%s:%s:%s:%d", fcad->nome_prod, fcad->ref_prod,
            fcad->cor_prod, fcad->dep_prod, fcad->forn_prod, fcad->fil_prod,
            fcad->qtde_prod);
    fprintf(arq_gra, "\n");
    fclose(arq_gra);
  } else if (strcmp(dep, "CONFECCAO") == 0 || strcmp(dep, "Confeccao") == 0 ||
             strcmp(dep, "confeccao") == 0 || strcmp(dep, "MODA") == 0 ||
             strcmp(dep, "Moda") == 0 || strcmp(dep, "moda") == 0) {
    arq_gra = fopen("produtos/arqconfec.txt", "a");
    if (arq_gra == NULL) {
      printf("ATENCAO! CADASTRO NAO CONCLUIDO!");
    } else {
      printf("\n\nCADASTRO CONCLUIDO!\n\n");
    }
    fprintf(arq_gra, "%s:%s:%s:%s:%s:%s:%d", fcad->nome_prod, fcad->ref_prod,
            fcad->cor_prod, fcad->dep_prod, fcad->forn_prod, fcad->fil_prod,
            fcad->qtde_prod);
    fprintf(arq_gra, "\n");
    fclose(arq_gra);
  } else if (strcmp(dep, "CALCADOS") == 0 || strcmp(dep, "Calcados") == 0 ||
             strcmp(dep, "calcados") == 0) {
    arq_gra = fopen("produtos/arqcalcados.txt", "a");
    if (arq_gra == NULL) {
      printf("ATENCAO! CADASTRO NAO CONCLUIDO!");
    } else {
      printf("\n\nCADASTRO CONCLUIDO!\n\n");
    }
    fprintf(arq_gra, "%s:%s:%s:%s:%s%s:%d", fcad->nome_prod, fcad->ref_prod,
            fcad->cor_prod, fcad->dep_prod, fcad->forn_prod, fcad->fil_prod,
            fcad->qtde_prod);
    fprintf(arq_gra, "\n");
  }
}

// grava no arquivo dados da Funcionario
void gravaFuncionario(pfunc fcad) {
  FILE *arq_gra;
  arq_gra = fopen("funcionarios/arqfunc.txt", "a");
  if (arq_gra == NULL) {
    printf("ATENCAO! CADASTRO NAO CONCLUIDO!");
  } else {
    printf("\n\nCADASTRO CONCLUIDO!\n\n");
  }
  fprintf(arq_gra, "%s:%s:%d:%s:%s:%s:%s:%s:%s:%s:%s:%s", fcad->nome_func,
          fcad->cpf_func, fcad->idade_func, fcad->tel_func, fcad->email_func,
          fcad->fil_func, fcad->rua_func, fcad->num_func, fcad->bairro_func,
          fcad->cid_func, fcad->est_func, fcad->comp_func);
  fprintf(arq_gra, "\n");
  fclose(arq_gra);
}
#endif
