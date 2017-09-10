#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    node *next, *prev;
};

/* Function to create a node and insert data into DLL */
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

/* Function to modify data of a node */
void Modify(node **head,int d, int position)
{
    int k=1;
    node *p;
    p=*head;
    while((p!=NULL) && (k<=position-1))
    {
        k++;
        p=p->next;
    }
    p->data=d;
}

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
            if(p)
                p->prev=q;
            free(p);
            return;
        }
    }
}

/* Function to traverse list in forward direction */
void PrintListFor(node *head)
{
    if (head == NULL)
       return;
    cout<<" "<<head->data;
    PrintListFor(head->next);
}

/* Function to traverse list in reverse direction */
void PrintListRev(node *head)
{
    if (head == NULL)
       return;
    PrintListRev(head->next);
    cout<<" "<<head->data;
}

int main()
{
    node *z = NULL;
    int ch; char ch1;
    start:
    cout<<"Do you want to:\n1.Create a new node/list\n2.Modify info of node\n3.Delete a node\n4.Traverse the list in forward direction\n5.Traverse the list in reverse direction\n";
    cin>>ch;
    switch(ch)
    {
    case 1:
        {
            int no, dat;
            cout<<"Enter number of elements: ";
            cin>>no;
            cout<<"\nEnter the elements: ";
            for(int i=0; i<no; i++)
            {
                cin>>dat;
                Insert(&z,dat);
            }
            if(no==1)
                cout<<"Node has been created";
            else
                cout<<"List has been created";
            break;
        }
    case 2:
        {
            int pos, newdat;
            cout<<"Enter position of node whose data is to be modified: ";
            cin>>pos;
            cout<<"\nEnter new data to be inserted: ";
            cin>>newdat;
            Modify(&z,newdat,pos);
            cout<<"\nNode's data has been modified.";
            break;
        }
    case 3:
        {
            int del;
            cout<<"Enter position of node you want to delete: ";
            cin>>del;
            DeleteDLL(&z,del);
            cout<<"\nNode has been successfully deleted.";
            break;
        }
    case 4:
        {
            cout<<"List content in forward direction: \n";
            PrintListFor(z);
            break;
        }
    case 5:
        {
            cout<<"List content in reverse direction: \n";
            PrintListRev(z);
            break;
        }
    default:
        {
            cout<<"Enter the correct option!";
            goto start;
        }
    }
    cout<<"\n\nDo you want to perform any operation again? (y/n)\n";
    cin>>ch1;
    if(ch1=='y')
        goto start;
    else
        return 0;
}
