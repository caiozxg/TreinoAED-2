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

void bubble(Cabeca *L){

    No *i = L->inicio;
    No *j = NULL;
    No *anterior = NULL;
    No *temp = NULL;
    No *temp1 = NULL;
    while (i != NULL){
        if (L->inicio->prox->valor > L->inicio->prox->prox->valor){
            temp = L->inicio->prox;
            temp->prox = L->inicio->prox->prox->prox;
            L->inicio->prox = L->inicio->prox->prox;
            L->inicio->prox->prox = temp;
            
        }
        j = L->inicio;
        
        while (j->prox != NULL){
            if (j->valor > j->prox->valor){
                temp1 = anterior->prox->prox->prox;
                temp = anterior->prox;
                anterior->prox = temp->prox;
                anterior->prox->prox = temp;
                temp->prox = temp1;


            }
        anterior = j;
        j = j->prox;
        }
        


        i = i->prox;
    }

}

void inserir(Cabeca *L,int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (L->inicio->prox == NULL){
        L->inicio->prox = novo;
    }else{
        No *aux = L->inicio;
        while (aux->prox != NULL){
            aux=aux->prox;
        }
        aux->prox = novo;
    }




}

int main(){
    Cabeca *L = (Cabeca*)malloc(sizeof(Cabeca));
    inicializa(L);
    inserir(L,234);
    inserir(L,244);
    inserir(L,34);
    inserir(L,24);
    inserir(L,254);
    inserir(L,2546);
    inserir(L,94);
    inserir(L,3424);
    inserir(L,134);
    inserir(L,231);
    inserir(L,3321);
    inserir(L,9382);
    No *aux = L->inicio->prox;
    printf("antes de ordenar:\n");
     while (aux != NULL){
        printf("%d->",aux->valor);
        aux = aux->prox;
    }
    aux = L->inicio->prox;
    bubble(L);
    printf("\ndepois de ordenar: \n");
    while (aux != NULL){
        printf("%d->",aux->valor);
        aux = aux->prox;
    }
    return 0;
}

        
