#include<iostream>
#define size 10

using namespace std;
int a[size], front=-1, rear=-1;

int ins(int x)
{
    if(front == -1 && rear ==-1)
        front = 0;
    if(rear < size)
    {
        a[++rear] = x;
    }
    else if(rear >= size)
    {
        cout<<"Queue full!";
        return 0;
    }
}

int del()
{
    if(front == -1 || front > rear)
        cout<<"Queue empty!";
    else
        return a[front++];
}


