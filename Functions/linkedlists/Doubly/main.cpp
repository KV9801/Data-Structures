#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    node *next, *prev;
};

/* Function to create a node and insert data */
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

/* Function to print entire list */
void PrintList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data;
        temp = temp->next;
    }
}

int main()
{
    node *x=NULL;
    int e;
    cout << "Enter the number of elements: ";
    cin >> e;
    cout << "Enter elements with a space: ";
    while (e--)
    {
        int temp;
        cin >> temp;
        Insert(&x,temp);
    }
    cout << "List content: " << endl;
    PrintList(x);
    int a,pos,del,ch; char ch1;
    start:
    cout<<"\n\nDo you want to:\n1. Insert another element\n2. Delete an existing element\n";
    cin>>ch;
    switch(ch)
    {
    case 1:
            cout<<"\nEnter element you want to insert: ";
            cin>>a;
            cout<<"Enter position: ";
            cin>>pos;
            InsertDLL(&x,a,pos);
            cout << "New list content: " << endl;
            PrintList(x);
            break;
    case 2:
            cout<<"\nEnter position of element you want to delete: ";
            cin>>del;
            DeleteDLL(&x,del);
            cout << "New list content: " << endl;
            PrintList(x);
            break;
    default:
            cout<<"Choose the correct option!";
            goto start;
    }
    cout<<"\n\nDo you want to insert or delete another element (y/n)?\n";
    cin>>ch1;
    if(ch1=='y')
      goto start;
    else
      return 0;
}


