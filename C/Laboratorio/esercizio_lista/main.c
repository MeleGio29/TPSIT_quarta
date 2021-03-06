#include <stdio.h>
#include <stdlib.h>
#define DIM 5

typedef struct nodo{ //struttura
    struct nodo *next;
    int valore;
}Nodo;

void caricaElemento(int v[]){ //funzione presa in input
    int k = 0;
    int valore;

    for(k = 0; k < DIM; k++){
        printf("Inserisci l'elemento: ");
        scanf("%d", v + k);
    }
}

void stampaVettore(int v[]){ //funzione stampa vettore
    int k;

    for(k = 0; k < DIM; k++){
        printf("%d ", *(v + k));
    }
}

Nodo* createNodo(int val, Nodo *nodo){ //funziona creazione lista
    Nodo* succ = (Nodo*)malloc(sizeof(Nodo));

    if(nodo != NULL){
        nodo->next = succ;
    }
        succ->valore = val;
        succ->next = NULL;
        return succ;
    }

int main()
{
    int* v;

    v = (int*)malloc(DIM * sizeof(int)); //allocazione dinamica v

    caricaElemento(v);

    printf("VETTORE: \n");
    stampaVettore(v);

    Nodo* head = NULL;
    Nodo* cur = NULL;

    for(int i = 0;i < DIM; i++){
        cur = createNodo(v[i], cur);
        if(head == NULL){
            head = cur;
        }
    }

    printf("\n");
    printf("LISTA: \n");
    cur = head;

    while(cur != NULL){ //stampa lista
        printf("%d ", cur->valore);
        cur = cur->next;
    }

    free(v); //disallocazione v

    printf("\n");
    system("PAUSE");
    return 0;
}
