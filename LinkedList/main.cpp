#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct node{
    int id;
    struct node *next;
}Node;

Node *head = NULL; // Voltear lista enlazada

void push(int id){
    Node * nodenew = (Node *) malloc(sizeof(Node));
    nodenew->id = id;
    nodenew->next = head;
    head = nodenew;
}

void pop(){
    Node *next_node = NULL;
    next_node = head->next;
    free(head);
    head = next_node;
}

/****** Regresa el numero de elementos de la lista ***********************/
int printList(){
    Node *current = head;
    int counter = 0;
    while(current != NULL){
        printf("%d ",current->id);
        counter++;
        current = current->next;
    }
    return counter;
}


void SwapList(){
    Node *current = head;
    Node *temp = NULL;

    while(current != NULL){
        Node *newlist = (Node*) malloc(sizeof(Node));
        newlist->id = current->id;
        newlist->next = temp;
        temp = newlist;
        current = current->next;
    }
    head = temp; // La cabeza hora apunta al ultimo de newlist
}

int RemoveLast(){
    Node *current = head;
    if(current->next == NULL){
        free(head);
        return 0;
    }
    while(current->next->next != NULL){
        current = current->next;
    }
    current->next = NULL;
    free(current->next);
    return 0;
}

bool ElementIsInTheList(int val){
    Node *current = head;
    if(current->id == val){
        printf("Elemento encontrado\n");
        return true;
    }
    while(current->next != NULL){
        if((current->id == val) || (current->next->id ==val)) {
            printf("Elemento encontrado\n");
            return true;
        }
        current = current->next;
    }
    printf("Elemento no encontrado\n");
    return false;
}


int main() {
    push(1);
    push(2);
    //push(3);
    //pop();
    //SwapList();
    ElementIsInTheList(0);
    int number = printList();
    printf("La lista contiene: %d elementos",number);

    return 0;
}
