#include <stdlib.h>
#include <stdio.h>

typedef struct No{
    
    int valor;
    
    struct No *esq;
    struct No *dir;

}No;


No* inserir(No *raiz,int valor){

    No *novo = (No*)malloc(sizeof(No));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->valor = valor;
    

        if (raiz == NULL){
            return novo;

        }else {
           
            if (valor > raiz->valor ){
                raiz->dir = inserir(raiz->dir,valor);
            }
            if (valor < raiz->valor ){
                raiz->esq = inserir(raiz->esq,valor);
            }
        return raiz;


        }
    
}
No *busca(No *raiz,int valor){
    if (raiz == NULL || raiz->valor == valor){
        if (raiz == NULL){
            printf("valor nao encontrado");
        }
        else{
            printf("valor encontrado");
        }
        return raiz;
    }

    if (valor > raiz->valor){
        return busca(raiz->dir,valor);
    }

    if (valor < raiz->valor){
        return busca(raiz->esq,valor);
    }

}





    





void imprimir(No *raiz){

    if (raiz != NULL){
        imprimir(raiz->esq);
        printf("%d\n",raiz->valor);
        imprimir(raiz->dir);
    
    }



}
int main(){
No *raiz = NULL;

raiz = inserir(raiz,263);
raiz = inserir(raiz,293);
raiz = inserir(raiz,237);
raiz = inserir(raiz,233);
raiz = inserir(raiz,1234);
raiz = inserir(raiz,223);
raiz = inserir(raiz,4323);
raiz = inserir(raiz,123);
raiz = inserir(raiz,236);
raiz = inserir(raiz,253);
raiz = inserir(raiz,233);

imprimir(raiz);
busca(raiz,43283);
}
