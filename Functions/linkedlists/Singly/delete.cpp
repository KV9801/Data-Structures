#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

/* Function to delete node at a specified postion */
void DeleteNode(node **head,int position)
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
        *head=(*head)->next;
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
        if(p==NULL)
            cout<<"Position does not exist";
        else
        {
            q->next=p->next;
            free(p);
        }
    }
}

/* Function to delete all the nodes */
void DeleteAll(node **head)
{
    node *auxNode,*iter;
    iter=*head;
    while(iter)
    {
        auxNode=iter->next;
        free(iter);
        iter=auxNode;
    }
    *head=NULL;
}