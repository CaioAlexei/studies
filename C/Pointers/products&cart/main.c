#include <stdio.h>
#include <stdlib.h>


#include "Produtos.h"
#include "Carrinho.h"
#include "menu.h"
#include "validacao.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void destruir_loja(PP_Produto prod, Carrinho car){	
	car = destruir_carrinho(car);
	prod = destruir_produtos(prod);
	free(car);
	free(prod);
	printf("---- MEMORIA LIBERADA E APICACAO DESTRUIDA ----");
	exit(0);
	
}



int main(int argc, char *argv[]) {
	PP_Produto prod;
	
	Carrinho car  = iniciar_carrinho();
	prod = iniciar_vetor();
	
	
	
	int chave_principal=1;
	while(chave_principal==1){
		int opcao =0;
		imprimir_menu_principal();
		opcao = valida_inteiro_loop();
		
		if(opcao==1){
			int opcao_produtos=0;
			while(opcao_produtos!=9){
				imprimir_menu_produtos();
				opcao_produtos = valida_inteiro_loop();
				
				if(opcao_produtos==1){
					prod = inserir_prod(prod);					
				}
				else if(opcao_produtos==2){
					prod = alterar_produto(prod);
				}
				else if(opcao_produtos==3){
					prod = excluir_prod(prod);
				}
				else if(opcao_produtos==4){
					consultar_produto(prod);
				}
				else if(opcao_produtos==5){
					imprimir_dados(prod);
				}
				
			}
			
		}
		else if(opcao ==2){
			int opcao_compras=0;
			while(opcao_compras!=9){
				imprimir_menu_compras();	
				opcao_compras = valida_inteiro_loop();
				
				if(opcao_compras==1){
					car = inserir_item(car,prod);					
				}
				else if(opcao_compras==2){
					imprimir_itens(car);
				}
				else if(opcao_compras==3){
					car = excluir_item(car,prod);
				}
				else if(opcao_compras==4){
					car = alterar_item(car,prod);
				}
				
				else if(opcao_compras==5){
					car = esvaziar_carrinho(car,prod);
				}
				else if(opcao_compras==6){
					finalizar_pedido(car);
				}
				else{
					opcao_compras=9;
				}
					
			}
				
		}
		else if(opcao ==3){
			destruir_loja(prod,car);
		}
		
	
	}

	
	return 0;
}
