#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

/* Function to insert node with data field at a specified postion */
void InsertLinkedList(node **head,int d, int position)
{
    int k=1;
    node *p,*q,*newNode;
    newNode = new node;
    if(!newNode)
    {
        cout<<"Memory error";
        return;
    }
    newNode->data=d;
    p=*head;

    if(position==1)
    {
        newNode->next=p;
        *head=newNode;
    }
    else
    {
        while((p!=NULL) && (k<position))
        {
            k++;
            q=p;
            p=p->next;
        }
        q->next=newNode;
        newNode->next=p;
    }
}