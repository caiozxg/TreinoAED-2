//lista duplamente encadeada com nó cabeça



#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No *prox;
    struct No* ant;



}No;


typedef struct Cabeca{

    int valor;
    No *inicio;
    struct No *prox;

}Cabeca;



void inicializar(Cabeca *L){
    
    L->inicio = (No *)malloc(sizeof(No));
    if(L == NULL){
        printf("\nerro ao alocar\n");
    

    }else{
    L->inicio->valor = -9999999;
    L->inicio->prox = NULL;
    L->inicio->ant= NULL;
    }
}

void Inserir(Cabeca *L,int valor){
    if (L == NULL){
        inicializar(L);
    }
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
        if (novo == NULL){
            printf("\nerro ao alocar\n");

        }
    if (L->inicio->prox == NULL){
        L->inicio->prox = novo;
        novo->prox = NULL; 
        novo->ant = L->inicio;
    }else{
        No *aux = L->inicio;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
        novo->prox = NULL;

    }
    



}

No* busca(Cabeca *L,int valor){
    No *aux = L->inicio;
    while (aux != NULL && aux->valor != valor){
        
        aux = aux->prox;
        if (aux == NULL){
            printf("nao possui este valor na lista");
            return aux;
        }
    }
    return aux;


}


void remover(Cabeca *L,int valor){
    No *aux = busca(L,valor);
    if (aux){
        No *antes = aux->ant;
        antes->prox = aux->prox;
        No *Proximo = aux->prox;
        Proximo->ant = aux->ant;
        free(aux);





    }
}


int main(){
    Cabeca *L = (Cabeca *)malloc(sizeof(Cabeca));
    inicializar(L);
    Inserir(L,9);
    Inserir(L,-2);
    Inserir(L,999);
    Inserir(L,392);
    Inserir(L,47);
    Inserir(L,98);
    Inserir(L,76);
    Inserir(L,23);
    Inserir(L,12);
    remover(L,47);
    No *percorre = L->inicio->prox;
    while (percorre){

        printf("%d",percorre->valor);
        
        if (percorre->prox){
            printf("->");
        }
        percorre = percorre->prox;
    }

    return 0;
}
