#ifndef LER_H_INCLUDED
#define LER_H_INCLUDED

// leitura dados das filiais
void lerFilial(pfil fcad)
{

      printf("NOME: ");
      scanf(" %[^\n]s", fcad->nome_fil);

      printf("RUA: ");
      scanf(" %[^\n]s", fcad->rua_fil);

      printf("NUMERO: ");
      scanf(" %[^\n]s", fcad->num_fil);

      printf("BAIRRO: ");
      scanf(" %[^\n]s", fcad->bairro_fil);

      printf("CIDADE: ");
      scanf(" %[^\n]s", fcad->cid_fil);

      printf("UC: ");
      scanf(" %[^\n]s", fcad->est_fil);

      printf("COMPLEMENTO: ");
      scanf(" %[^\n]s", fcad->comp_fil);

      fflush(stdin);
}

// leitura dados funcionarios
void lerFuncionario(pfunc fcad)
{

      printf("NOME: ");
      scanf(" %[^\n]s", fcad->nome_func);

      printf("IDADE: ");
      scanf("%d", &fcad->idade_func);

      printf("CPF: ");
      scanf(" %[^\n]s", fcad->cpf_func);

      printf("RUA: ");
      scanf(" %[^\n]s", fcad->rua_func);

      printf("NUMERO: ");
      scanf(" %[^\n]s", fcad->num_func);

      printf("BAIRRO: ");
      scanf(" %[^\n]s", fcad->bairro_func);

      printf("CIDADE: ");
      scanf(" %[^\n]s", fcad->cid_func);

      printf("UC: ");
      scanf(" %[^\n]s", fcad->est_func);

      printf("COMPLEMENTO: ");
      scanf(" %[^\n]s", fcad->comp_func);

      printf("CONTATO: ");
      scanf(" %[^\n]s", fcad->tel_func);

      printf("EMAIL: ");
      scanf(" %[^\n]s", fcad->email_func);

      printf("FILIAL: ");
      scanf(" %[^\n]s", fcad->fil_func);

      fflush(stdin);
}

// leitura dados do produto
void lerProduto(pprod fcad)
{

      printf("NOME: ");
      scanf(" %[^\n]s", fcad->nome_prod);

      printf("COR: ");
      scanf(" %[^\n]s", fcad->cor_prod);

      printf("REFERÊNCIA: ");
      scanf(" %[^\n]s", fcad->ref_prod);

      printf("FORNECEDOR: ");
      scanf(" %[^\n]s", fcad->forn_prod);

      printf("DEPARTAMENTO: ");
      scanf(" %[^\n]s", fcad->dep_prod);

      printf("FILIAL: ");
      scanf(" %[^\n]s", fcad->fil_prod);

      printf("QUANTIDADE: ");
      scanf(" %d", &fcad->qtde_prod);

      fflush(stdin);
}

#endif
