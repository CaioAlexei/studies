#include <stdlib.h>
#include <stdio.h>


#include "validacao.h"
#include "Carrinho.h"


int existe_codProduto(int cod,PP_Produto prod,int max){
	int i;
	
	for(i=0;i<max;i++){
		if(prod[i] && prod[i]->codProduto == cod){
			printf("Ja existe um código para esse produto");
			return 1;
		}
	}
	
	return 0;
}

int existe_codProduto_car(int cod,PP_Produto prod,int max){
	int i;
	
	for(i=0;i<max;i++){
		if(prod[i] && prod[i]->codProduto == cod){
			printf("O produto existe");
			return 1;
		}
	}
	
	return 0;
}

int existe_codProduto_no_car(int cod,Carrinho car,int max){
	int i;
	
	for(i=0;i<max;i++){
		if(car[i] && car[i]->cod_Produto == cod){
			printf("O item ja esta no carrinho");
			return 1;
		}
	}
	
	return 0;
}


int valida_codProduto(PP_Produto prod,int max){
	
	int inteiro;
	int entradaValida = 0;

    while (!entradaValida) {
        printf("\nDigite o valor do codigo do produto: ");
        if (scanf("%d", &inteiro) == 1) {
        	if(inteiro == 0){
        		printf("O codigo não pode ser 0, pois é uma chave primaria.");
			}
			else{
				if(!existe_codProduto(inteiro,prod,max)){
        			entradaValida = 1;
				}
				else{
					printf("\n!!!Ja existe um produto com esse codigo!!!");
				}				
			}
        	
            
        } else {
            printf("\nEntrada invalida. Certifique-se de digitar um numero inteiro.\n");
            // Limpar o buffer de entrada para evitar loops infinitos
            while (getchar() != '\n');
        }
    }
    
    return inteiro;   
}

int valida_qtdEstoque(){
	
	int inteiro;
	int entradaValida = 0;

    while (!entradaValida) {
        printf("Digite a quantidade em estoque: ");
        if (scanf("%d", &inteiro) == 1) {
            entradaValida = 1;
        } else {
            printf("Entrada invalida. Certifique-se de digitar um numero inteiro.\n");
            // Limpar o buffer de entrada para evitar loops infinitos
            while (getchar() != '\n');
        }
    }
    
    return inteiro;   
}

float valida_precos(){
	float flutuante;
	int entradaValida = 0;

    while (!entradaValida) {
        printf("Digite o valor do produto: ");
        if (scanf("%f", &flutuante) == 1) {
            entradaValida = 1;
        } else {
            printf("Entrada invalida. Certifique-se de digitar um numero inteiro.\n");
            // Limpar o buffer de entrada para evitar loops infinitos
            while (getchar() != '\n');
        }
    }
    
    return flutuante;   
}


// validador de inteiro
int valida_chave(){
	
	int inteiro;
	int entradaValida = 0;

    while (!entradaValida) {
        printf("\nDigite: \n0 - Nao \n1- Sim \n ");
        if (scanf("%d", &inteiro) == 1) {
        	if(inteiro == 1 || inteiro == 0){
        		entradaValida=1;
			}else{
				printf("\n Por favor digite 0 ou 1. \n ");
			}       	
            
        } else {
            printf("\nEntrada invalida. Certifique-se de digitar um numero inteiro.\n");
            // Limpar o buffer de entrada para evitar loops infinitos
            while (getchar() != '\n');
        }
    }
    
    return inteiro;   
}
// CARINHO


int valida_ex_produto(PP_Produto prod,int max){
	
	int inteiro;
	int entradaValida = 0;

    while (entradaValida!=1) {
        printf("\nDigite o valor do codigo do produto: ");
        
        if (scanf("%d", &inteiro) == 1) {
        	if(inteiro == 0){
        		printf("O codigo não pode ser 0, pois é uma chave primaria.");
			}
			else{
				if(existe_codProduto_car(inteiro,prod,max)==1){
        			entradaValida = 1;
        			return inteiro;
				}
				else{
					printf("\n!!!Não existe um produto com esse codigo!!!");
				}				
			}
        	
            
        } else {
            printf("\nEntrada invalida. Certifique-se de digitar um numero inteiro.\n");
            // Limpar o buffer de entrada para evitar loops infinitos
            while (getchar() != '\n');
        }
    }
    
       
}

int valida_ex_no_carrinho(Carrinho car,PP_Produto prod,int max){
	
	int inteiro;
	int entradaValida = 0;

    while (entradaValida!=1) {
        printf("\nDigite o valor do codigo do produto: ");
        
        if (scanf("%d", &inteiro) == 1) {
        	if(inteiro == 0){
        		printf("O codigo não pode ser 0, pois é uma chave primaria.");
			}
			else{
				if(existe_codProduto_car(inteiro,prod,max)==1){
					
					if(existe_codProduto_no_car(inteiro,car,max_carrinho())==1){
						printf("\nProduto ja existe no carrinho!");
					}else{
						entradaValida = 1;
        				return inteiro;
					}
        			
				}
				else{
					printf("\n!!!Não existe um produto com esse codigo!!!");
				}				
			}
        	
            
        } else {
            printf("\nEntrada invalida. Certifique-se de digitar um numero inteiro.\n");
            // Limpar o buffer de entrada para evitar loops infinitos
            while (getchar() != '\n');
        }
    }
    
       
}

int valida_inteiro(){
	
	int inteiro;
	int entradaValida = 0;

    while (!entradaValida) {
        printf("\nDigite a quantidade a ser comprada: ");
        if (scanf("%d", &inteiro) == 1) {
        	if(inteiro == 0){
        		printf("\nA quantidade a ser comprada não pode ser 0.");
			}
			else{
				return inteiro;				
			}
        	
            
        } else {
            printf("\nEntrada invalida. Certifique-se de digitar um numero inteiro.\n");
            // Limpar o buffer de entrada para evitar loops infinitos
            while (getchar() != '\n');
        }
    }
    
    return inteiro;   
}

int valida_inteiro_loop(){
	
	int inteiro;
	int entradaValida = 0;

    while (!entradaValida) {
        
        if (scanf("%d", &inteiro) == 1) {
        	return inteiro;
        	
            
        } else {
            printf("\nEntrada invalida. Certifique-se de digitar um numero inteiro.\n");
            // Limpar o buffer de entrada para evitar loops infinitos
            while (getchar() != '\n');
        }
    }
    
    return inteiro;   
}

int valida_inteiro_car(P_Produto prod){
	
	int inteiro;
	int entradaValida = 0;
	
    while (!entradaValida) {
        printf("\nDigite a quantidade a ser comprada: ");
        if (scanf("%d", &inteiro) == 1) {
        	if(inteiro == 0){
        		printf("\nA quantidade a ser comprada não pode ser 0.");
			}
			else{
				if(subtrair_estoque(prod,inteiro,0)==1){
					entradaValida =1;
				}
												
			}
        	
            
        } else {
            printf("\nEntrada invalida. Certifique-se de digitar um numero inteiro.\n");
            // Limpar o buffer de entrada para evitar loops infinitos
            while (getchar() != '\n');
        }
    }
    
    return inteiro;   
}



// verifica se da

int valida_codProduto_no_car(Carrinho car,int max){
	
	int inteiro;
	int entradaValida = 0;
	
    while (!entradaValida) {
        printf("\nDigite o valor do codigo do produto: ");
        if (scanf("%d", &inteiro) == 1) {
        	if(inteiro == 0){
        		printf("O codigo não pode ser 0, pois é uma chave primaria.");
			}
			else{
				if(existe_codProduto_no_car(inteiro,car,max)==1){
        			entradaValida = 1;
				}
				else{
					printf("\n!!!Não existe esse prodtuo no carrinho!!!");
				}				
			}
        	
            
        } else {
            printf("\nEntrada invalida. Certifique-se de digitar um numero inteiro.\n");
            // Limpar o buffer de entrada para evitar loops infinitos
            while (getchar() != '\n');
        }
    }
    
    return inteiro;   
}


int valida_inteiro_car_ex(int cod,int ex,PP_Produto prod){
	
	int inteiro;
	int entradaValida = 0;
	P_Produto prod1 = retornar_produto(prod,cod);
    while (!entradaValida) {
        printf("\nDigite a quantidade a ser comprada: ");
        if (scanf("%d", &inteiro) == 1) {
        	if(inteiro == 0){
        		printf("\nA quantidade a ser comprada não pode ser 0.");
			}
			else{
				if(subtrair_estoque(prod1,inteiro,ex)==1){
					entradaValida =1;
				}
												
			}
        	
            
        } else {
            printf("\nEntrada invalida. Certifique-se de digitar um numero inteiro.\n");
            // Limpar o buffer de entrada para evitar loops infinitos
            while (getchar() != '\n');
        }
    }
    printf("%d",inteiro);
    return inteiro;   
}
