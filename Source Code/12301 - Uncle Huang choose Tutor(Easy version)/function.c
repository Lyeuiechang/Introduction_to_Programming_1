//#include "function.h"

//Version 1
/*
Node *createList(int n)
{
    Node *head, *current, *prev;
    head = malloc(sizeof(Node));
    head->number = n;
    head->next = NULL;
    current = head;
    prev = head;
    int i;
    for(i=1;i<n;i++)
    {
        current = current->next;
        current = malloc(sizeof(Node));
        current->number = i;
        current->next = NULL;
        prev->next = current;
        prev = current;
    }
    current->next = head;
    return head;
}
void freeList(Node* head)
{
    Node *current = head;
    while(current->next != head)
    {
        printf("%d ",current->number);
        current = current->next;
    }
    printf("%d ",current->number);
    printf("\n");
}
int solveJosephus(Node **head, int step)
{
    Node *current = *head;
    Node *chosed;
    int moded_step;
    int n = current->number;
    int number;
    while(current->next != current)
    {
        if(step > n)
        {
            moded_step = step % n - 1;
        }
        else
        {
            moded_step = step - 1;
        }
        while(moded_step>0)
        {
            current = current->next;
            moded_step--;
        }
        chosed = current->next;
        current->next = chosed->next;
        printf(" _%d_ ",chosed->number);
        free(chosed);
        n--;
    }
    number = current->number;
    free(current);
    return number;
}
*/

//Version 2
#include "function.h"

Node *createList(int n)
{
    Node *head = malloc(sizeof(Node));
    head->number = n;
    return head;
}

void freeList(Node* head)
{
    free(head);
}

int solveJosephus(Node **head, int step)
{
    int s = 0;
    int n = (*head)->number;
    int i;
    for (i = 2; i <= n; i++)
    {
        s = (s + step) % i;
    }
    return s+1;
}
