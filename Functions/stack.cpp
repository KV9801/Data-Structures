#include<iostream>
#define size 10

using namespace std;
int a[size], top=-1;

void push(int x)
{
    if(top>size)
        cout<<"Stack overflow";
    else
        a[++top] = x;
}

int pop()
{
    if(top <= -1)
        cout<<"Stack underflow";
    else
        return a[top--];
}
