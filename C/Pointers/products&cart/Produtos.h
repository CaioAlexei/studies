#ifndef PRODUTO_H
#define PRODUTO_H

// Estrutura do Produto

typedef struct produto{
	int codProduto;
	char descricao[100];
	int qtd_estoque;
	float preco;
	
}Produto,*P_Produto,**PP_Produto;


// Manutencao dos vetores 
int maximo_produtos();

int produtos_cadastrados();

void inicializar_vetor(PP_Produto PP_prod);

PP_Produto iniciar_vetor();

PP_Produto realocar_vetor( PP_Produto prod);

PP_Produto verificar_cheio(PP_Produto prod);


// Operacões CRUD

PP_Produto inserir_prod(PP_Produto prod);

PP_Produto excluir_prod(PP_Produto prod);

PP_Produto alterar_produto(PP_Produto prod);

PP_Produto consultar_produto(PP_Produto prod);

void imprimir_dados(PP_Produto prod);
//

P_Produto retornar_produto(PP_Produto prod,int cod);

int subtrair_estoque(P_Produto prod, int quant,int ex);

void somar_estoque(P_Produto prod, int quant);

PP_Produto destruir_produtos(PP_Produto prod);

#endif
