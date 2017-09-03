#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

/* Function to create linked list */
void Insert(node **head, int d)
{
    node *temp, *temp1;
    temp=new node;
    temp->data=d;
    temp->next=NULL;
    if(*head==NULL)
        *head=temp;
    else
    {
        temp1=*head;
        while (temp1->next!=NULL)
            temp1=temp1->next;
        temp1->next=temp;
    }
}

