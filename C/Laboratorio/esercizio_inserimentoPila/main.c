#include <stdio.h>
#include <stdlib.h>
#define DIM 5
#define MAXSIZE 50

int stack[50];
int top = -1;

int isempty() { //funzione controllo pila

   if(top == -1)
      return 1;
   else
      return 0;
}

int isfull() { //funzione controllo pila

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

char peek(){ //funzione controllo pila
   return stack[top];
}

char pop(char data) { //funzione presa elemento

   if(!isempty()) {
      data = stack[top];
      top = top - 1;
      return data;
   } else {
      printf("Impossibile prelevare dato, Stack vuoto.\n");
   }
}

void push(char data) { //funzione inserimento elemento

   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
   } else {
      printf("Impossibile inserire dati, Stack Pieno.\n");
   }
}

void invertiPila(int vet[]){ //funzione inverti pila
    int k;
    for(k = DIM; k >= 0; k--){
        push(vet[k]);
    }
}

void main() {
    int vet[DIM];
    int k = 0, elemento;

    //input del vettore
    for(k=0 ; k< DIM; k++){
        printf("inserisci l'elemento %d :",k);
        scanf("%d", &elemento);

        vet[k] = elemento;
    }

    invertiPila(vet);

    //output del vettore
    while(top>=0){
        elemento = pop(stack[top]);
        printf(" %d ",elemento);
    }

    printf("\n");
    system("PAUSE");
    return;
}
