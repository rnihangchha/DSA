#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
} Node;

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode<=0){printf("Malloc failed");}
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

void insertHead(Node **head, int value){
    Node* newHead = createNode(value);
    if(*head != NULL){
        (*head)->prev=newHead; 
    }
    newHead->next=*head;
    newHead->data=value;
    *head=newHead;
}

void insertAtEnd(Node** head, int value){
    Node* newNode = createNode(value);
    if(*head == NULL){
        *head=newNode;
        return;
    }
    Node* tptr = *head;
    while(tptr->next != NULL){
        tptr=tptr->next;
    }
    newNode->prev=tptr;
    tptr->next=newNode;
    
}

void insertAtPosition(Node **head,int value, int position){
    Node* newNode = createNode(value);
    if(position == 0){
        insertHead(head,value);
        return;
    }
    else if(position == -1){
        insertAtEnd(head,value);
        return;
    }
    Node *tptr = *head;
    for(int i=0;tptr != NULL & i<(position-1);i++){
        tptr = tptr->next;
    }
    if(tptr == NULL){
        printf("Postion: %d, Out of range", position);
    }
    newNode->data=value;

    newNode->prev=tptr;
    newNode->next=tptr->next;
    tptr->next=newNode;
    tptr->next->prev=newNode;
}

void print_n(Node* head){
    Node* tptr = head;
    while(tptr !=NULL){
        printf("%d =>",tptr->data);
        tptr=tptr->next;
    }
    printf("0\n");
}

void print_p(Node* head){
    if(head==NULL){
        printf("List is EMPTY");
    }
    Node *tptr = head;int nodeCount=1;
    printf("0=>");
    while(tptr->next !=NULL){
        nodeCount++;
        tptr=tptr->next;
    }
    for(int i=0;i<nodeCount;i++){
        printf("%d =>",tptr->data);
        tptr=tptr->prev;
    }
    printf("\n");
}


int main(int argc, char** argv[]){
    Node* head = NULL;
    insertHead(&head,22);
    insertHead(&head,12);
    insertHead(&head,67);
    insertHead(&head,80);
   
    insertAtEnd(&head,100);
    insertAtEnd(&head,120);
    print_n(head);
    print_p(head);
    insertAtPosition(&head,77,4);
    insertAtPosition(&head,777,-1);
    print_n(head);

    return 0;
}