#include "function.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert(Node** head, char* color, int dest){ // insert <color> <dest>
    Node *temp = (*head);
    Node *newNode = (Node*)malloc(sizeof(Node));

    for(int i = 0; i < dest; i++){
        if(temp->next == NULL){break;}
        temp = temp->next;
    }

    strncpy(newNode->color, color, sizeof((*head)->color));
    newNode->next = temp->next;
    temp->next = newNode;
}

void erase1(Node** head, int dest){ // erase1 <dest>
    Node *temp = (*head);
    Node *deleted = (*head)->next;

    if(deleted == NULL){return;}

    for(int i = 1; i < dest; i++){
        if(deleted->next == NULL){break;}
        temp = temp->next;
        deleted = deleted->next;
    }

    temp->next = deleted->next;
    free(deleted);
}

void erase2(Node** head, char* color){ // erase2 <color>
    Node *temp = (*head);
    Node *deleted = (*head)->next;

    while(deleted != NULL){
        if(strcmp(deleted->color, color) == 0){
            temp->next = deleted->next;
            free(deleted);
            deleted = temp->next;
        }else{
            temp = temp->next;
            deleted = deleted->next;
        }
    }
}

void reverse(Node** head, int dest1, int dest2){ // reverse <dest1> <dest2>
    Node *dest1Node = (*head)->next;
    Node *dest2Node = (*head)->next;

    if(dest1 == dest2 || dest1Node == NULL){return;}
    // Make dest2 larger than dest1
    if(dest1 > dest2){
        int t = dest2;
        dest2 = dest1;
        dest1 = t;
    }

    int i = 0, j = 0;

    for(i = 1; i < dest1; i++){
        if(dest1Node->next == NULL){break;}
        dest1Node = dest1Node->next;
    }
    
    for(j = 1; j < dest2; j++){
        if(dest2Node->next == NULL){break;}
        dest2Node = dest2Node->next;
    }
    int buffSize = j - i + 1;
    Node *buff = (Node *)malloc(sizeof(Node) * buffSize);
    Node *tempNode = dest1Node;
    for(int k = i, c = 0; k <= j; k++, c++){
        buff[c] = *tempNode;
        tempNode = tempNode->next;
    }
    tempNode = dest1Node;
    for(int k = i, c = buffSize - 1; k <= j; k++, c--){
        strncpy(tempNode->color, buff[c].color, 10);
        tempNode = tempNode->next;
    }
    free(buff);
}