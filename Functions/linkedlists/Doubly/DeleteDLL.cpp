#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    node *next, *prev;
};

/* Function to delete a node from a specified position */
void DeleteDLL(node **head,int position)
{
    int k=1;
    node *p,*q;
    if(*head==NULL)
    {
        cout<<"List empty";
        return;
    }
    p=*head;
    if(position==1)
    {
        (*head)=(*head)->next;
        if(*head!=NULL)
            (*head)->prev=NULL;
        free(p);
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
            cout<<"Position does not exist";
        else
        {
            q->next=p->next;
            if(p->next)
                p->next->prev=q;
            free(p);
            return;
        }
    }
}