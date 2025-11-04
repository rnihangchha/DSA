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

void* insertHead(int d, Node** head){
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

void insertAtPos(int d, Node** head, int position){
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
    else {
        Node* tptr = *head;
        for(int i=0; tptr != NULL && i < position-1 ; i++ ){
            tptr = tptr->next;
        }
        /*If all *next pointer -> next node finished and pointer now assigned to NULL Pointer*/
        if(tptr == NULL) {
            printf("Out of range\n");exit(0);
        }
        newNode->next = tptr->next;
        tptr->next = newNode;
    }
    
}

/* DELETE PORTION */
void deleteHeadElement(Node **head){
    if(*head ==NULL){printf("Empty");}
    Node* dptr = *head;
    if(dptr->next == NULL){
        free(dptr);
        dptr =NULL;
        *head=NULL;
        return;
    }
    *head = dptr->next;
    free(dptr);
    dptr = NULL;
}


void deleteTail(Node **head){
    if(*head ==NULL){printf("Empty");}
    Node* dptr = *head;
    if(dptr->next == NULL){
        free(dptr);
        dptr =NULL;
        *head=NULL;
        return;
    }
    /*need record of the two last node*/
    do{
       dptr = dptr->next;
    }while( dptr->next->next != NULL);
    free(dptr->next);
    dptr->next =NULL;
}

void deleteAtPos(Node **head,int position){
    Node* dptr = *head;
    if(position==0){
        deleteHeadElement(head);
        return;
    }
    else if( position == -1){
        deleteTail(head);
        return;
    }    
    for(int i=0; dptr != NULL && i<(position-1);i++){
        dptr = dptr->next; /* 1->2= 2, 3, 4  */
    }
    if(dptr==NULL || dptr->next==NULL){printf("Out of range");exit(0);}
    Node* next =  dptr->next->next; /*(position+1) = 4 address*/
    free(dptr->next);
    dptr->next = next;
    
}


void print(Node* head){
    Node* tptr = head;
    /* Proper approach*/
    // tptr->next can => next node address so, later tptr = tptr->next;
    while(tptr != NULL){
        printf("%d ",tptr->data);
        tptr = tptr->next;
    }
    printf("\n");
}

int main(int argc, char ***argv[]){
    Node *head = NULL;
    
    insertHead(90,&head);
    printf("%d\n",head->data); 
    insertTail(99,&head);
    insertTail(888, &head);
    insertHead(7777,&head);
    
    print(head);
    insertAtPos(69,&head,0);
    insertAtPos(71,&head,2);
    print(head);
    deleteTail(&head);
    deleteTail(&head);
    print(head);
    deleteAtPos(&head,2);
    print(head);
    return 0;
}