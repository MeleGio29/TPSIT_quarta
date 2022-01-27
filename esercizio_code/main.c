#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_queue_node {
    int elemento;
    struct s_queue_node*next;
} Queue_node;

int is_empty(Queue_node*head);

void enqueue(Queue_node**head,Queue_node**tail,Queue_node*element);

Queue_node*dequeue(Queue_node**head,Queue_node**tail);

int is_empty(Queue_node*head) {
    if(head==NULL)
        return 1;
    else
        return 0;
}

void enqueue(Queue_node**head,Queue_node**tail,Queue_node*element) {
    if(is_empty(*head))
        *head=element;
    else
        (*tail)->next=element;

    *tail=element;
    element->next=NULL;
}

Queue_node*dequeue(Queue_node**head,Queue_node**tail) {
    Queue_node*ret=*head;

    if(is_empty(*head))
        return NULL;
    else
        *head=ret->next;

    if (*head==NULL)
        *tail=NULL;
    return ret;
}

int main() {
    Queue_node*head=NULL;
    Queue_node*tail=NULL;
    Queue_node*struct_return=NULL;
    Queue_node*element;
    bool condizione=true;
    int dato;

    while(condizione) {
        int scelta;

        printf("\n");
        printf("MENU'\n-Scegli '1' per inserire elementi nella coda\n-Scegli '2' per svuotare la coda\n-Scegli '3' per uscire dal programma\n\nInserire numero:");
        scanf("%d",&scelta);

        switch(scelta)

        {
        case 1:
            printf("Inserire elemento: ");
            scanf("%d",&dato);
            element=(Queue_node*)malloc(sizeof(Queue_node));
            element->elemento=dato;
            enqueue(&head,&tail,element);
            break;

        case 2:
            printf("Gli elementi inseriti fino ad ora sono:\t");
            while ((struct_return=dequeue(&head,&tail))!=NULL) {
                printf("%d ",struct_return->elemento);
                free(struct_return);
            }
            printf("\n");
            printf("\n");

            break;

        case 3:
            printf("exit");
            condizione=false;
            break;

        default:
            printf("[carattere inserito non valido]\n\n");
            break;
        }

    }

    printf("\n");
    system("PAUSE");
    return 0;
}
