#include <iostream>
#include "linkedList.cpp"
using namespace std;
class StackByArrays  //implementing stacks by arrays
{
    public:
    int arr[10000]; //array of size 10000
    int curr_size; //current size
    StackByArrays()
    {
        curr_size=-1;  //empty stack
    }
    void push(int x)
    {
        if(curr_size+1>=10000) //if stack is full
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            curr_size++;
            arr[curr_size]=x; //pushing element on top
        }
    }
    int pop()
    {
        if(curr_size<0) //if stack is empty
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            int x=arr[curr_size];
            delete &arr[curr_size]; //deleting top element
            curr_size--;
            return x;
        }
    }
    int top()
    {
        if(curr_size<0)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            return arr[curr_size]; //returning top element without deleting
        }
    }
    bool isEmpty()
    {
        if(curr_size==-1)
        {
            return true;
        }
        return false;
    }
};

class StackByLinkedList //implementing stacks by linked lists
{
    LinkedList l;
public:
    StackByLinkedList()
    {

    }
    void push(int x)
    {
        l.insertAtHead(x); //inserting at top of stack
    }
    int pop()
    {
        if(!isEmpty())
        {
        int x=l.getHead()->value;
        l.deleteFromStart(); //removing from top of stack
        return x;
        }
        else
        {
            cout<<"Stack is empty"<<endl;
        }
    }
    int top()
    {
        if(!isEmpty()) //if not empty
        {
        return l.getHead()->value; //returning value without deleting
        }
        else
        {
            cout<<"Stack is empty"<<endl;
        }
    }
    bool isEmpty()
    {
        if(!l.getHead())
        {
            return true;
        }
        return false;
    }
};
