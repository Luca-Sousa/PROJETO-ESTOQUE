#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

//struct para dados das filiais
typedef struct dadosFilial{
    int cod_fil ;
    char *nome_fil, *rua_fil, *num_fil, *bairro_fil, *cid_fil, *est_fil, *comp_fil;
    }dfil, *pfil;

//struct para dados do funcionario
typedef struct dadosFuncionario{
    int cod_func, idade_func ;
    char *nome_func, *cpf_func, *rua_func, *num_func, *bairro_func,
         *cid_func, *est_func, *comp_func, tel_func[16], *email_func,
         *fil_func, *login_func, *senha_func;
    }dfunc, *pfunc;

//struct para dados dos produtos
typedef struct dadosProduto{
    int cod_prod, qtde_prod;
    char *nome_prod, *cor_prod, *ref_prod, *forn_prod, *fil_prod, *dep_prod;
    }dprod, *pprod;


#endif