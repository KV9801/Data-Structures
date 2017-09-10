#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

/* Function to modify data of node */
void Modify(node **head, int d, int position)
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
