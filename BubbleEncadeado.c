#include <stdlib.h>
#include <stdio.h>


// bubble(L)
    
//     atual = L->.inicio->prox
    
//     enquanto atual->prox != Lambda
//         aux -> atual;
//         enquanto aux->prox != lambda
        
//             se aux->prox->valor > aux->prox->prox->valor entao
//                 temp = aux->prox;      
//                 aux->prox = temp->prox
//                 temp->prox = aux->prox->prox
//                 aux->prox->prox = temp
                
                

//             aux = aux->prox
//         atual = atual->prox





typedef struct No{
    int valor;
    struct No *prox;


}No;

typedef struct Cabeca{

    struct No *inicio;


}Cabeca;



void inicializa(Cabeca *L){


L->inicio = (No*)malloc(sizeof(No));
L->inicio->valor = -999999;
L->inicio->prox = NULL;

}



void inserir(Cabeca *L,int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (L->inicio->prox == NULL){
        L->inicio->prox = novo;
    }else{
        aux = L->inicio;
        while (aux->prox != NULL){
            
        }
        aux->prox = novo;
    }




}

int main(){
    Cabeca *L;
    inicializa(L);
    inserir(L,234);
    inserir(L,244);
    inserir(L,34);
    inserir(L,24);

    return 0;
}

        
