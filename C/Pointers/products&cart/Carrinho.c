#include "Carrinho.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
int maxItensCarrinho =10;
int itensCarrinho = 0;

int max_carrinho(){
	return maxItensCarrinho;
}

void inicializar_carrinho(Carrinho car){
  int i;
  for(i=0;i<maxItensCarrinho;i++){
    car[i] = NULL;             
  }                     
}

Carrinho iniciar_carrinho(){
	
	
	Carrinho car;
	
	car = (Carrinho) malloc(sizeof(P_Item)*maxItensCarrinho);
	
	if(!car) exit(1);
	
	inicializar_vetor(car);
		
	return car;
}


Carrinho realocar_vetor_car( Carrinho car){
	int auxNumI = maxItensCarrinho;
	maxItensCarrinho +=10;
	car = realloc(car, maxItensCarrinho * sizeof(P_Item));
	
	int i;
	for(i=auxNumI;i<maxItensCarrinho;i++){
	   car[i] = NULL;             
	}
	return car;   
}



Carrinho verificar_cheio_car(Carrinho car){
	if(itensCarrinho == maxItensCarrinho){
		car = realocar_vetor_car(car);
		printf("\nAumentado o tamanho do vetor");
	}
	
	return car;
}
Item items(Carrinho car, PP_Produto prod){
	Item item;
	printf("\n------ INSERIR ITEM NO CARRINHO ------\n");
	P_Produto prod_verificado;
	
	item.cod_Produto = valida_ex_no_carrinho(car,prod,maximo_produtos());
	
	prod_verificado = retornar_produto(prod,item.cod_Produto);
	
	item.preco_unitario = prod_verificado->preco;
	

	item.quantidade = valida_inteiro_car(prod_verificado);
	item.preco_total  = item.preco_unitario * item.quantidade;
	
	
	strcpy(item.descricao,prod_verificado->descricao);
	
	return item;
}
Carrinho inserir_item(Carrinho car, PP_Produto prod){
	int i;
	
	
	Item item;
	
	item = items(car,prod);
	
	
	car = verificar_cheio_car(car);
	for(i=0;i<maxItensCarrinho;i++){
		if(!car[i]){
			
			car[i] = (P_Item) malloc(sizeof(Item));
			
			car[i]->cod_Produto = item.cod_Produto;
			
			car[i]->preco_unitario= item.preco_unitario;
			
			car[i]->quantidade= item.quantidade;
			car[i]->preco_total= item.preco_total;
			
			strcpy(car[i]->descricao,item.descricao);
			if(car[i]->cod_Produto){
				itensCarrinho++;
			}
			break;
		}
	}
	printf("\n------ FIM INSERIR ITEM NO CARRINHO ------\n");
	return car;
}

Carrinho excluir_item(Carrinho car,PP_Produto prod){
	int cod = valida_codProduto_no_car(car,maxItensCarrinho);
	int i =0;
	P_Produto prod1 = retornar_produto(prod,cod);
	printf("\n------ LISTAGEM DE PRODUTOS -------\n");
	for(i=0;i<maxItensCarrinho;i++){
		if(car[i]->cod_Produto == cod){
			
			somar_estoque(prod1,car[i]->quantidade);
			free(car[i]);
			car[i]= NULL;
			itensCarrinho--;
			break;
			
			
		}
		
	}
	
	return car;
}

Carrinho alterar_item(Carrinho car,PP_Produto prod){
	
	int cod = valida_codProduto_no_car(car,maxItensCarrinho);
	
	
	printf("\n\n ________ ALTERANDO QUANTIDADE DO ITEMs _______\n\n");
	int i=0;
	for(i=0;i<maxItensCarrinho;i++){
		
		if(car[i] && car[i]->cod_Produto == cod){
			car[i]->quantidade = valida_inteiro_car_ex(cod,car[i]->quantidade,prod);
			car[i]->preco_total = car[i]->quantidade* car[i]->preco_unitario;
			
			break;
		}
		
	}
	
	printf("\n\n ________ FIM ALTERANDO PRODUTO _______\n\n");
	
	return car;
}

Carrinho esvaziar_carrinho(Carrinho car,PP_Produto prod){
	int i;
	for(i=0;i<maxItensCarrinho;i++){
		if(car[i]){
			P_Produto prod1 = retornar_produto(prod,car[i]->cod_Produto);
			
			somar_estoque(prod1,car[i]->quantidade);
			free(car[i]);
			car[i]= NULL;
			itensCarrinho--;
		}
		
		
	}
		
	return car;
	
}

Carrinho destruir_carrinho(Carrinho car){
	int i;
	for(i=0;i<maxItensCarrinho;i++){
		if(car[i]){
			
			free(car[i]);
			car[i]= NULL;
			itensCarrinho = 0;
		}
		
		
	}
		
	return car;
	
}


void imprimir_itens(Carrinho car){
	int i =0;
	printf("\n------ LISTAGEM DE PRODUTOS -------\n");
	for(i=0;i<maxItensCarrinho;i++){
		if(car[i]){
			printf("\n\n__________________________________________________\n\n");
			printf("\nProduto: %d",car[i]->cod_Produto);
			printf("\nDescricao: %s",car[i]->descricao);
			printf("\nPreco Unitario: %.2f",car[i]->preco_unitario);
			printf("\nQuantidade a ser comprada: %d",car[i]->quantidade);
			printf("\nTOTAL A SER PAGO: %.2f",car[i]->preco_total);
			printf("\n\n__________________________________________________\n\n");
			
		}
		
	}
	
	printf("\n------ FIM DA LISTAGEM DE PRODUTOS -------\n");	
	
}

void finalizar_pedido(Carrinho car){
	srand(time(NULL));
	int i;
	float total;
	int randomico = rand() % 100000 + 1;
	printf("\n------ PEDIDO FINALIZADO cod:  %d  -------\n",randomico);
	for(i=0;i<maxItensCarrinho;i++){
		if(car[i]){
			printf("\n---------------------\n");
			printf("\nPRODUTO CODIGO: %d",car[i]->cod_Produto);
			printf("\nPRODUTO NOME: %s",car[i]->descricao);
			printf("\nPRODUTO QUANTIDADE: %d",car[i]->quantidade);
			printf("\nPRODUTO VALOR: R$%.2f",car[i]->preco_unitario);
			printf("\nPRODUTO VALOR TOTAL: R$%.2f",car[i]->preco_total);
			printf("\n---------------------\n");
		}
		
		
		
		
	
		
		
	}
	for(i=0;i<maxItensCarrinho;i++){
		if(car[i]){
			total += car[i]->preco_total;			
			free(car[i]);
			car[i]= NULL;
		}
	}
	printf("\n------ TOTAL A SER PAGO R$%.2f -------\n",total);
	printf("\n------ FIM DA LISTAGEM DE PRODUTOS -------\n");	
	
}
