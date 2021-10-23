//author: Ushna Ijaz
#include <iostream>
#include "linkedList.cpp"
using namespace std;

class QueueByArrays //implementing queues by Arrays
{
    int bottom; //flag for current size
    int arr[1000]; //declaring array of size 1000
    public:
    QueueByArrays()
    {
        bottom=0; //empty array
    }
    void enqueue(int x)
    {
        if(bottom>=1000) //if queue is full
        {
            cout<<"Queue is full"<<endl;
        }
        arr[bottom]=x; //pushing element
        bottom++;
    }
    int dequeue()
    {
        if(bottom==0) //if array is empty
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            int x=arr[0]; //popping element from front
            for(int i=0;i<bottom-1;i++)  //rearranging array
            {
                arr[i]=arr[i+1];
            }
            bottom=bottom-1; //resizing array
            return x;
        }
    }
    bool isFull()
    {
        if(bottom==1000) //if full
        {
            cout<<"Is Full"<<endl;
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if(bottom==0) //if empty
        {
            cout<<"Is Empty"<<endl;
            return true;
        }
        return false;
    }
    int peek() //returning front element without removing element
    {
        if(bottom==0)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            return arr[0];
        }
    }
};

class QueueByLinkedList //implementing queues by linked list
{
    public:
    LinkedList l;
    void enqueue(int x)
    {
        l.insertAtEnd(x); //inserting at end
    }
    int dequeue()
    {
        int x=l.getHead()->value;
        l.deleteFromStart();  //popping from front
        return x;
    }
    int peek()
    {
        return l.getHead()->value; //returning top element
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
