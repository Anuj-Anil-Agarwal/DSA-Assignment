//Write a function “insert_any()” for inserting a node at any given position of the linked list. Assume position starts at 0.

#include<stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void display(node *head);
node *create(int x);
node * insert_end(node *head, int x);
node *insert_beg(node *head, int x);
node *insert_any(node *head,int pos,int x);

int main()
{
    node *head = NULL;
    head = insert_end(head, 10);
    head = insert_end(head, 20);
    head = insert_end(head, 30);
    display(head);
    head = insert_beg(head, 15);
    display(head);
    head = insert_any(head,2,25);
    display(head);
    
}

node * create(int x)
{
    node *new = (node *)malloc(sizeof(node));
    new -> data = x;
    new -> next = NULL;
    return new;
}

node * insert_end(node *head, int x)
{
    node *new = create(x);
    node *temp = head;

    if(!head)
    {
        head = new;
        return head;
    }
    while(temp -> next)
    {
        temp = temp -> next;
    }
    temp -> next = new;
    return head;
}

node * insert_any(node *head,int pos,int x)
{
    node *new = create(x);
    node *temp = head;
    int i;

    
    for(i=0;i<pos-1;i++)
    {
        temp = temp -> next;
        if(!temp)
        {
            printf("\n There are less than %d elements in list ",pos);
            return head;
        }
    }
    
    new->next = temp->next;
    temp->next=new;
    return head;
}


node *insert_beg(node *head, int x)
{
    node *new = create(x);
    new -> next = head;
    head = new;
    return head;
}

void display(node *head)
{
    if(!head)
    {
        printf("No node to display\n");
        return;
    }
    node *temp = head;
    while(temp)
    {
        printf("|%d| -> ", temp -> data);
        temp = temp -> next;
    }
    printf("N\n");
}


