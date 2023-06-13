
#include <stdlib.h>
#include <stdio.h>
#include "Produtos.h"
#include "validacao.h"

//Contadores
int maxProdutos =10;
int proCadastrados = 0;

int maximo_produtos(){
	return maxProdutos;
}

int produtos_cadastrados(){
	return proCadastrados;
}
void inicializar_vetor(PP_Produto PP_prod){
  int i;
  for(i=0;i<maxProdutos;i++){
    PP_prod[i] = NULL;             
  }                     
}

PP_Produto iniciar_vetor(){
	
	
	PP_Produto PP_prod;
	
	PP_prod = (PP_Produto) malloc(sizeof(P_Produto)*maxProdutos);
	
	if(!PP_prod) exit(1);
	
	inicializar_vetor(PP_prod);
		
	return PP_prod;
}


PP_Produto realocar_vetor( PP_Produto prod){
	int auxNumP = maxProdutos;
	maxProdutos +=10;
	prod = realloc(prod, maxProdutos * sizeof(P_Produto));
	
	int i;
	for(i=auxNumP;i<maxProdutos;i++){
	   prod[i] = NULL;             
	}
	return prod;   
}

PP_Produto verificar_cheio(PP_Produto prod){
	if(proCadastrados == maxProdutos){
		prod = realocar_vetor(prod);
		printf("\nAumentado o tamanho do vetor");
	}
	
	return prod;
}

PP_Produto inserir_prod(PP_Produto prod){
	int i;
	
	Produto produto;
	
	
	
	prod = verificar_cheio(prod);
	for(i=0;i<maxProdutos;i++){
		if(!prod[i]){
			
			prod[i] = (P_Produto) malloc(sizeof(Produto));
			printf("\n------ INSERIR ITEM NO ESTOQUE ------\n");
			prod[i]->codProduto = valida_codProduto(prod,maxProdutos);
			
			printf("\nDigite a descricao do produto: \n");
			scanf("%99s",prod[i]->descricao);
			
			prod[i]->qtd_estoque = valida_qtdEstoque();
			
			prod[i]->preco = valida_precos();
			
			if(prod[i]->codProduto){
				proCadastrados++;
			}
			break;
		}
	}
	printf("\n------ FIM INSERIR ITEM NO ESTOQUE ------\n");
	return prod;
}

PP_Produto excluir_prod(PP_Produto prod){
	printf("\n\n ________ EXCLUINDO PRODUTO _______\n\n");
	int i;
	int cod = valida_ex_produto(prod,maxProdutos);
	
	for(i=0;i<maxProdutos;i++){
		if(prod[i]->codProduto == cod){
			free(prod[i]);
			prod[i]=NULL;			
			proCadastrados--;
			break;
		}
	}
	printf("\n\n ________ FIM EXCLUINDO PRODUTO _______\n\n");
	return prod;
}


PP_Produto alterar_produto(PP_Produto prod){
	int cod = valida_ex_produto(prod,maxProdutos);
	
	
	printf("\n\n ________ ALTERANDO PRODUTO _______\n\n");
	int i=0;
	for(i=0;i<maxProdutos;i++){
		
		if(prod[i] && prod[i]->codProduto == cod){
			prod[i]->codProduto = valida_codProduto(prod,maxProdutos);
			printf("\nDigite a descricao do produto: \n");
			scanf("%99s",prod[i]->descricao);
			
			prod[i]->qtd_estoque = valida_qtdEstoque();
			
			prod[i]->preco = valida_precos();
			
			break;
		}
		
	}
	
	printf("\n\n ________ FIM ALTERANDO PRODUTO _______\n\n");
	
	return prod;
}

PP_Produto consultar_produto(PP_Produto prod){
	int cod;
	printf("\nInsira o codigo do produto a ser consultar: \n");
	scanf("%d",&cod);
	
	
	int i;
	for(i=0;i<maxProdutos;i++){
		if(prod[i] && prod[i]->codProduto == cod){
			printf("\n__________________________________________________\n\n");
			printf("\nProduto: %d",prod[i]->codProduto);
			printf("\nNome: %s",prod[i]->descricao);
			printf("\nPreco: R$%.2f",prod[i]->preco);
			printf("\nQuantidade em estoque: %d",prod[i]->qtd_estoque);
			printf("\n\n__________________________________________________");			
			break;
		}
		
	}
}

void imprimir_dados(PP_Produto prod){
	int i =0;
	printf("\n------ LISTAGEM DE PRODUTOS -------\n");
	for(i=0;i<maxProdutos;i++){
		if(prod[i]){
			printf("\n\n__________________________________________________\n\n");
			printf("\nProduto: %d",prod[i]->codProduto);
			printf("\nDescricao: %s",prod[i]->descricao);
			printf("\nPreco: R$%.2f",prod[i]->preco);
			printf("\nQuantidade em estoque: %d",prod[i]->qtd_estoque);
			printf("\n\n__________________________________________________\n\n");
			
		}
		
	}
	
	printf("\n------ FIM DA LISTAGEM DE PRODUTOS -------\n");	
	
}

P_Produto retornar_produto(PP_Produto prod,int cod){
			
	int i;
	
	for(i=0;i<maxProdutos;i++){
		if(prod[i] && prod[i]->codProduto == cod){
			
			return prod[i];
		}
		
	}
}

int subtrair_estoque(P_Produto prod, int quant,int ex){
	
	if((prod->qtd_estoque-quant+ex) < 0){
		printf("\nA quantidade requisitada é maior que a quantidade em estoque.");
		return 0;
	}
	else{
		printf("\nA quantidade requisitada existe em estoque.");
		prod->qtd_estoque -= quant-ex;
		return 1;
	}
	
	
}

void somar_estoque(P_Produto prod, int quant){
	
	prod->qtd_estoque += quant;	
	
}

PP_Produto destruir_produtos(PP_Produto prod){
	int i;
	for(i=0;i<maxProdutos;i++){
		if(prod[i]){
			
			free(prod[i]);
			prod[i]= NULL;
			maxProdutos = 0;
		}
		
		
	}
		
	return prod;
	
}
