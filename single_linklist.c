#include <stdio.h>
#include <stdlib.h>
/*
{Feature include}
create node
insert at head
at the 
delete head
delete last
delete at position
*/

/*
Head-> [data|next]-> [data|next]->NULL
*/
typedef struct  Node{
    int data;
    struct Node* next;
} Node;

Node* createNode(int d){
    Node *ptr = (Node*)malloc(sizeof(Node));
    ptr->data=d;
    ptr->next=NULL;
    return ptr;
}

Node* insertHead(int d, Node** head){
    Node* newNode = createNode(d);
    if(*head == NULL){
        *head = newNode;
        return *head;
    }
    newNode->next = *head;
    *head = newNode;
}

Node* insertTail(int d, Node** head){
    Node* newNode = createNode(d);
    if(*head == NULL){
        *head = newNode;
        return *head;
    }
    /* (NOTE: -> and * => dereference)*/
    Node* tptr = *head;
    while(tptr->next != NULL){
        tptr = tptr->next;
    }
    tptr->next = newNode;
    
}

Node* insertAtPos(int d, Node** head, int position){
    Node* newNode = createNode(d);
    if(*head == NULL){
        *head = createNode(d);
    }
    if(position == 0){
        insertHead(d,head);
    }
    else if(position==-1){
        insertTail(d,head);
    }
    Node* tptr = *head;
    for(int i=0; tptr->next != NULL && i < (position -1); i++ ){
        tptr = tptr->next;
    }
    newNode->next = tptr->next;
    tptr->next = newNode;
    
}

void print(Node* head){
    Node* tptr = head;
    /* Proper approach*/
    // tptr->next can => next node address so, later tptr = tptr->next;
    while(tptr != NULL){
        printf("%d=>",tptr->data);
        tptr = tptr->next;
    }
}

int main(int argc, char ***argv[]){
    Node node = {666,NULL};
    Node *head = &node;
    
    insertHead(90,&head);
    printf("%d\n",head->data); 
    insertTail(99,&head);
    insertTail(888, &head);
    insertHead(7777,&head);
    print(head);

    insertTail(66,&head);
    insertAtPos(77,&head,2);
    insertAtPos(88,&head,4);
    insertAtPos(77,&head,0);
    insertAtPos(999,&head,5);
    insertAtPos(1111,&head,-1);
    print(head);
    
}