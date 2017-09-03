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
