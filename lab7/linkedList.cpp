//author: Ushna Ijaz
#include <iostream>
using namespace std;

//class for single node
class Node{
    public:
        int value;
        Node* next;
        Node* prev;

    public:

        Node(){
            next=NULL;
            prev=NULL;
        };

        Node(int x){
            value=x;
            this->next=NULL;
            this->prev=NULL;
        };
};

//class for linked list implementation
class LinkedList{
    private:
        Node* head;

    public:
        LinkedList(){
            head=NULL;
        }

        bool isEmpty()  //checks is list is empty or not
        {
            if(head){
                return true;
            }else{
                return false;
            }
        }

        Node* insertNode(int index, int x) //inserting node at given index
        {
            Node* temp = head;
            int count=0;

            while(count!=x) //reaching at given index
            {
                if(temp==NULL){
                    return NULL;
                }
                temp=temp->next;
            }

            Node* insert = new Node(x); //creating new node
            insert->next=temp->next;
            insert->prev=temp;
            temp->next=insert;

        return head;
        }

        Node* insertAtHead(int x)  //inserting node at start
        {
            Node* temp = new Node(x);
            temp->prev = NULL;
            temp->next = head;

            if(!head) //if list is empty
            {
                head=temp;
            }
            else
            {
                head->prev=temp;
                head=temp;
            }
            return head;
        }

        Node* insertAtEnd(int x) //inserting node at end
        {
            if(!head) //if list is empty
            {
                insertAtHead(x);
            }
            else
            {
                Node* temp = head;
                while(temp->next != NULL) //reaching at end of list
                {
                    temp=temp->next;
                }
                Node* y = new Node(x); //creating new node
                temp->next= y;
                temp->next->prev=temp;
            }
            return head;
        }

        bool findNode(int x)  //checks if x is in list or not
        {
            Node* temp = head;
            while(temp!= NULL) //traversing whole list
                {
                if(temp->value == x)  //if found
                {
                    return true;
                }
                temp=temp->next;
            }
            return false;
        }

        bool deleteNode(int x)   //deleting node with value x
        {
            Node* temp = head;
            Node* parent = NULL;
            while(temp->next != NULL)
            {
                if(temp->value == x)  //if found
                {
                    parent->next=temp->next;
                    delete(temp);
                }
                parent=temp;
                temp=temp->next;
            }

            return true;
        }

        bool deleteFromStart() //deleting node from start
        {
            if(!head)  //if list is empty
            {
                return true;
            }
            else if(head->next==NULL) //if list has only one node
            {
                Node* t=head;
                head->prev=NULL;
                head=NULL;
                delete t;
                return true;
            }
            Node* parent = head;
            head=head->next;
            delete(parent);  //deleting start value
            head->prev=NULL;
            return true;
        }

        bool deleteFromEnd() //deleting value from end
        {
            Node* temp = head;

            while (temp->next->next!=NULL) //reaching value at end
            {
                temp=temp->next;
            }
            temp->next=NULL;
            return true;
        }

        void displayList(Node *list)  //function to display list
        {
            Node* temp = list;
             while (temp->next!=NULL) //traversing whole list
            {
                cout<<temp->value<<"->";
                temp=temp->next;
            }
            cout<<temp->value;
        }

        Node* reverseList()  //reverses given list
        {
            LinkedList l2; //creating new list
            Node *temp=head;
            while(temp!=NULL)
            {
                l2.insertAtHead(temp->value);  //inserting at head of new list, creates reversal of given list
                temp=temp->next;
            }
            head=l2.getHead(); //reassigning head of given list to head of new list
        }

        Node* getHead() //to get head
        {
            return head;
        }

        Node* removeDuplicates(Node *list) //removes duplicates in list
        {
            Node *temp=SortList(list); //sorts the list first
            Node *temp_head=temp;
            while(temp_head->next!=NULL) //traverses till second last element
            {
                if(temp->value==temp->next->value) //if current value is equal to next value
                {
                    Node *temp2=temp->next;
                    temp->next=temp->next->next;
                    delete temp2;  //delete next value, but save and assign next pointers accordingly
                }
                temp_head=temp_head->next;
            }
            return list;
        }

Node *SortList(Node *list)  //sorting given list by bubble sort algorithm
{
    Node *temp=NULL,*temp1 = NULL;
    if (!list) //if empty
    {
        return NULL;
    }

    bool replaced=true;  //a flag for terminating loop condition
    int temp3;
    while (replaced)
    {
        replaced = false;
        temp = list;
        while (temp->next != temp1)  //while current and next values are not same
        {
            if (temp->next->value < temp->value)
            {
                temp3 = temp->value;    //swapping current and next value
                temp->value = temp->next->value;
                temp->next->value = temp3;
                replaced = true;
            }
            temp = temp->next;
        }
        temp1 = temp;
    }
    return list;  //returning head of list1
}
Node* interestLists(Node *list1, Node *list2)  //intersecting given lists
{
    Node*temp1=list1;
    Node*temp2=list2;
    LinkedList l,l_intersect;  //initializing two lists
    while(temp1!=NULL)
    {
        l.insertAtEnd(temp1->value); //saving list1 in linkedlist l
        temp1=temp1->next;
    }
    temp1=l.getHead();
    while(temp2!=NULL)
    {
        if(l.findNode(temp2->value))  //check if temp2(element of list2) is in linkedlist l.
        {
            l_intersect.insertAtEnd(temp2->value);  //inserting common elements in list
        }
        temp2=temp2->next;
    }
    return l_intersect.getHead();
}
Node* mergeLists(Node *list1, Node *list2) //merges given lists
{
    Node*temp1=list1;
    Node*temp2=list2;
    LinkedList l;
    while(temp1!=NULL)  //inserts first list
    {
        l.insertAtEnd(temp1->value);
        temp1=temp1->next;
    }
    while(temp2!=NULL) //inserts second list
    {
        l.insertAtEnd(temp2->value);
        temp2=temp2->next;
    }
    return l.getHead();
}
};
