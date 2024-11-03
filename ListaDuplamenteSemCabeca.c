// InsertionSort duplamente encadeado com no cabeca 



#include <stdlib.h>
#include <stdio.h>

typedef struct No{
    int valor;
    struct No *prox;
    struct No *ant;


}No;




void inicializa(No *L,int valor){


L = (No*)malloc(sizeof(No));
L = valor;
L->prox = NULL;
L->ant = NULL;

}
void insertionsort(No *L){
    No *i = L->prox;
    No *j;
    No *prov=NULL;
    No *prov1;
    while (i != NULL){
        int valor = i->valor;
        j = i->ant;
        No *proximo = i->prox;
        
            while (j != L->prox && valor <= j->valor){
                // trocar no prox pelo no atual
                prov = j;
                prov1 = j->prox;
                if (prov->ant != NULL){
                    j->ant->prox = prov1;
                }
                prov1->ant = prov->ant;
                prov->prox = prov1->prox;
                
                if (prov->prox != NULL){
                    prov->prox->ant = prov;
                }    
                
                prov1->prox = prov;
                prov->ant = prov1;
                


                

            j = j->ant->ant;
            }
        


        i = i->prox;
    }





}



void inserir(No *L,int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;


    if (L->prox == NULL){
        L->prox = novo;
        L->prox->ant = L;

    }else{
        No *i = L;
        while (i->prox != NULL){
            i=i->prox;
        }
        novo->ant = i;
        i->prox = novo;
    }




}

int main(){
    No *L = inicializa(L,10);
    inserir(L,16);
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
    inserir(L,1);
    inserir(L,8);
    inserir(L,7);
    inserir(L,4);
    
    
    No *i = L->prox;
    printf("antes de ordenar:\n");
     while (i != NULL){
        printf("%d->",i->valor);
        i = i->prox;
    }
    insertionsort(L);
    i = L->prox;
    
    printf("\ndepois de ordenar: \n");
    while (i != NULL){
        printf("%d->",i->valor);
        i = i->prox;
    }
    return 0;
}

        
