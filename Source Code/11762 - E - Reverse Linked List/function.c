#include <stdio.h>
#include <stdlib.h>
#include "function.h"
Node* Create_List(Node* head, int data)
{
    if(head == NULL)
    {
        head = malloc(sizeof(Node));
        head->data = data;
        head->next = NULL;
    }
    else
    {
        Node *p = head;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = malloc(sizeof(Node));
        p->next->data = data;
        p->next->next = NULL;
        //Print_List(head);
    }
    return head;
}
Node* Reverse_List(Node* head)
{
    if(head->next == NULL)
    {
        return head;
    }
    else
    {
        Node *p = head->next;
        head->next = NULL;
        Node *q;
        while(p->next != NULL)
        {
            q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        p->next = head;
        head = p;
    }
    return head;
}
void Print_List(Node* head)
{
    //printf("%d", head->data);
    Node *p = head;
    while(p->next != NULL)
    {
        printf("%d->",p->data);
        p = p->next;
    }
    printf("%d\n",p->data);
}
void Free_List(Node* head)
{
    Node *p = head;
    Node *q;
    while(p->next != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(p);
}
