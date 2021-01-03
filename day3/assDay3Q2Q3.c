//Write a function “insert_any()” for inserting a node at any given position of the linked list. Assume position starts at 0.

#include<stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void display(node *head);
node * del_beg(node *head);
node * del_end(node *head);

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
    head = del_beg(head);
    display(head);
    head = del_end(head);
    display(head);
    
    
}

node * create(int x)
{
    node *new = (node *)malloc(sizeof(node));
    new -> data = x;
    new -> next = NULL;
    return new;
}


node * del_beg(node *head)
{
    node *temp = head;
        if(head == NULL)  
        {  
            printf("\nList is empty");  
            return head;
        }  
        else   
        {  
        
            head = temp->next;  
            free(temp);  
            printf("\n Node deleted from the begining ...\n");  
            return head;
        }  
}



node * del_end(node *head)
{
    node *temp = head,*temp1;

    if(!head)
    {
        printf("\n List is empty !!! ");
        //head = new;
        return head;
    }
    else if(!head -> next)  
    {  
        temp = NULL;  
        free(temp);  
        printf("\nOnly node of the list deleted ...\n");
        return head;
    } 
    else{
        while(temp -> next)
        {
            temp1=temp;
            temp = temp -> next;
        }
    
        temp1 -> next = NULL;
        free(temp);
            printf("\n Node deleted from the end ...\n");  
        return head;
    }
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


