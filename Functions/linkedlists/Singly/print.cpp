#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

/* Function to print complete list */
void PrintList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data;
        temp = temp->next;
    }
}


// OR 
// Can be done recursively as well 
   
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

