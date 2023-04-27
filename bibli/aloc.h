#ifndef ALOC_H_INCLUDED
#define ALOC_H_INCLUDED
#define QSTR 100

//alocacao struct filial
pfil alocaFilial(){
         pfil pf = NULL;
         pf = (pfil) malloc(sizeof(dfil));
           if(pf!=NULL){
            pf->nome_fil = (char*) malloc(QSTR * sizeof(char));
            pf->rua_fil = (char*) malloc(QSTR * sizeof(char));
            pf->num_fil = (char*) malloc(sizeof(char));
            pf->bairro_fil = (char*) malloc(QSTR * sizeof(char));
            pf->cid_fil = (char*) malloc(QSTR * sizeof(char));
            pf->est_fil = (char*) malloc(QSTR * sizeof(char));
            pf->comp_fil = (char*) malloc(QSTR * sizeof(char));
         }else{
           printf("Filial nao alocada!");
          }
         return pf;
}

//alocacao struct funcionario
pfunc alocaFuncionario(){
         pfunc pf = NULL;
         pf = (pfunc) malloc(sizeof(dfunc));
           if(pf!=NULL){
            pf->nome_func = (char*) malloc(QSTR * sizeof(char));
            pf->cpf_func = (char*) malloc(QSTR * sizeof(char));
            pf->rua_func = (char*) malloc(QSTR * sizeof(char));
            pf->num_func = (char*) malloc(sizeof(char));
            pf->bairro_func = (char*) malloc(QSTR * sizeof(char));
            pf->cid_func = (char*) malloc(QSTR * sizeof(char));
            pf->est_func = (char*) malloc(QSTR * sizeof(char));
            pf->comp_func = (char*) malloc(QSTR * sizeof(char));
            pf->email_func = (char*) malloc(QSTR * sizeof(char));
            pf->fil_func = (char*) malloc(QSTR * sizeof(char));
            pf->login_func = (char*) malloc(QSTR * sizeof(char));
            pf->senha_func = (char*) malloc(QSTR * sizeof(char));
         }else{
           printf("Funcionario nao alocado!");
          }
         return pf;
}

//alocacao struct produto
pprod alocaProduto(){
         pprod pd = NULL;
         pd = (pprod) malloc(sizeof(dprod));
           if(pd!=NULL){
            pd->nome_prod = (char*) malloc(QSTR * sizeof(char));
            pd->cor_prod = (char*) malloc(QSTR * sizeof(char));
            pd->dep_prod = (char*) malloc(QSTR * sizeof(char));
            pd->ref_prod = (char*) malloc(QSTR * sizeof(char));
            pd->forn_prod = (char*) malloc(QSTR * sizeof(char));
            pd->fil_prod = (char*) malloc(QSTR * sizeof(char));
         }else{
           printf("Produto nao alocado!");
          }
         return pd;
}
#endif
