#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next, *prev;
};

/* Function to insert data into a DLL at a specified position */
void InsertDLL(node **head,int d, int position)
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
        newNode->next=*head;
        newNode->prev=NULL;
        if(*head)
            (*head)->prev=newNode;
        *head=newNode;
        return;
    }
    else
    {
        while((p!=NULL) && (k<position))
        {
            k++;
            q=p;
            p=p->next;
        }
        if(k!=position)
            cout<<"Position does not exist!";
        newNode->next=p;
        newNode->prev=q;
        if(p)
            p->prev=newNode;
        q->next=newNode;
        return;
    }
}