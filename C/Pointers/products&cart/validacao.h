#ifndef VALIDACAO_H
#define VALIDACAO_H

#include "Produtos.h"
#include "Carrinho.h"

int existe_codProduto(int cod,PP_Produto prod,int max);

int valida_codProduto(PP_Produto prod,int max);

int valida_qtdEstoque();

float valida_precos();

int valida_inteiro();

int valida_chave();



int existe_codProduto_car(int cod,PP_Produto prod,int max);

int existe_codProduto_no_car(int cod,Carrinho car,int max);


int valida_ex_produto(PP_Produto prod,int max);

int valida_ex_no_carrinho(Carrinho car,PP_Produto prod,int max);

int valida_inteiro_car(P_Produto prod);

int valida_codProduto_no_car(Carrinho car,int max);

int valida_inteiro_car_ex(int cod,int ex,PP_Produto prod);


#endif
