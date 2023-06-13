#ifndef CARRINHO_H
#define CARRINHO_H

#include"Produtos.h"



typedef struct item{
	
	int cod_Produto;
	int quantidade;
	float preco_unitario;
	float preco_total;
	char descricao[100];
	
}Item,*P_Item,**Carrinho;


void inicializar_carrinho(Carrinho car);

Carrinho iniciar_carrinho();

Carrinho realocar_vetor_car( Carrinho car);

Carrinho verificar_cheio_car(Carrinho car);

Item items(Carrinho car, PP_Produto prod);



Carrinho inserir_item(Carrinho car, PP_Produto prod);

Carrinho excluir_item(Carrinho car,PP_Produto prod);

Carrinho alterar_item(Carrinho car,PP_Produto prod);

Carrinho esvaziar_carrinho(Carrinho car,PP_Produto prod);

Carrinho destruir_carrinho(Carrinho car);

void imprimir_itens(Carrinho car);

void finalizar_pedido(Carrinho car);
#endif
