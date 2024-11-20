                       // Implementation Of Circular Doubly Linked List 

#include<iostream>
using namespace std;
class Node // this is the node of cdll // user defined class 
{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int val)
    {
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class CircularDoublyLinkedList // user defined data structure 
{
    public:
    int size;
    Node* head;
    Node* tail;

    CircularDoublyLinkedList()
    {
        size=0;
        head=tail=NULL;
    }


void insertathead(int val)
{
    Node* temp = new Node(val);
    if(size==0)
    {
        head=tail=temp;
        head->next=tail;
        tail->next=head;
        size++;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        temp->prev=tail;
        tail->next=temp;
        head=temp;
        size++;
    }
}

void insertattail(int val)
{
    Node* temp=new Node(val);
    if(size==0)
    {
        head=tail=temp;
        tail->next=head;
        head->next=temp;
        size++;
    }
    else
    {
        tail->next=temp;
        head->prev=temp;
        temp->next=head;
        temp->prev=tail;
        tail=temp;
        size++;
    }
}


void insertatidx(int idx, int val)
{
    if(idx<0 || idx>size)
    {
        cout<<"Invalid index"<<endl;
        return ;
    }
    else if (idx==0) 
    {
        insertathead(val);
    }
    else if (idx==size)
    {
        insertattail(val);
    }
    else
    {
        Node* temp=head;
        Node* t = new Node(val);
        {
            for(int i=1; i<idx; i++)
            {
                temp=temp->next;
            }

        t->next=temp->next;
        t->prev=temp;
        temp->next=t; 
        t->next->prev=t;
        size++;
        }
    }
}

void deleteathead()
{
    if(size==0)
    {
        cout<<"Circular Doubly Linked List is empty ! Underflow "<<endl;
        return ;
    }
    else
    {
        head=head->next;
        head->prev=tail;
        tail->next=head;
        size--;
    }
}

void deleteattail()
{
    if(size==0)
    {
        cout<<"List is empty ! Underflow "<<endl;
        return ;
    }
    else
    {
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        size--;
    }
}

void deleteatidx(int idx)
{
    if(idx<0 || idx>size)
    {
        cout<<"Invalid Index !"<<endl;
        return ;
    }
    else if (idx==0)
    {
        deleteathead();
    }
    else if (idx==size)
    {
        deleteattail();
    }
    else
    {
        Node* temp=head;
        for(int i=1; i<idx; i++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        temp->next->prev=temp;
        size--;
    }
}

int getathead()
{
    if(size==0)
    {
        cout<<" List is empty ! Underflow "<<endl;
        return -1;
    }
    else
    {
        cout<<head->val;
    }
    cout<<endl;
}

int getattail()
{
    if(size==0)
    {
        cout<<"Circular Doubly Linked List is empty "<<endl;
        return -1;
    }
    else
    {
        cout<<tail->val;
    }
    cout<<endl;
}

int getatidx(int idx)
{
    if(idx<0 || idx>size)
    {
        cout<<"Invalid Index "<<endl;
        return -1;
    }
    else if(idx==0)
    {
        // return getathead();
        cout<<head->val;
    }
    else if (idx==size-1)
    {
        // return getattail();
        cout<<tail->val;
    }
    else
    {
        Node* temp=head;
        for(int i=0; i<idx; i++)
        {
            temp=temp->next;
        }
        cout<<temp->val;
    }
    cout<<endl;
}

void display()
{
    if(size==0)
    {
        cout<<"List is empty ! Does not display anything !";
        return;
    }
    else
    {
        Node* temp=head;
        while(true)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
            if(temp==head) break;
        }
        cout<<endl;
    }
}


};
int main()
{
    CircularDoublyLinkedList cdll; // class name - CircularDoublyLinkedList, Object name - cdll

    // access another function using object name 
    // we make a different-2 function and apply our CircularDoublyLinkedList and see how it works

    cdll.insertathead(10);
    cdll.insertathead(20);
    cdll.insertathead(30);
    cdll.insertathead(40);
    cdll.insertathead(50);
    cdll.display();

    cdll.insertattail(100);
    cdll.insertattail(200);
    cdll.insertattail(300);
    cdll.insertattail(400);
    cdll.insertattail(500);
    cdll.insertattail(600);
    cdll.display();



    // cdll.insertatidx(2,-2);
    // cdll.insertatidx(3,-3);
    // cdll.insertatidx(4,-4);
    // cdll.insertatidx(6,-6);
    // cdll.insertatidx(5,-5);
    // cdll.insertatidx(10,-10);
    // cdll.display();

    // cdll.deleteathead();
    // cdll.display();
    // cdll.deleteathead();
    // cdll.display();
    // cdll.deleteathead();
    // cdll.display();
    // cout<<endl;


    // cdll.deleteattail();
    // cdll.display();
    // cdll.deleteattail();
    // cdll.display();
    // cdll.deleteattail();
    // cdll.display();



    // cdll.deleteatidx(2);
    // cdll.display();
    // cdll.deleteatidx(7);
    // cdll.display();
    // cdll.deleteatidx(-1);
    // cdll.display();
    // cdll.deleteatidx(4);
    // cdll.display();





    cdll.getathead();

    cdll.getattail();



    // cdll.getatidx(3); // 20
    // cdll.getatidx(5); // 100
    // cdll.getatidx(9); // 500
    // cdll.getatidx(10); // 600
    // cdll.getatidx(11); // 50 -> it means, this is a circular doubly linked list, becoz in cdll tail is connected to the head and vice - versa.
    // // so, if we want to value of 11 idx(last idx) it gives me the value of 1st idx of ll becoz this is cdll it is a crcular 
    // // it show that tail is coneected to the head and vice versa after 11th idx it gives invalid index. this Code is ture. 
    // cdll.getatidx(12); // Invalid Index
    // cdll.getatidx(13); // Invalid Index



// Output -> for getatidx function 
// 50 40 30 20 10 
// 50 40 30 20 10 100 200 300 400 500 600
// 20
// 100
// 500
// 600
// 50
// Invalid Index
// Invalid Index



    
    cout<<cdll.size<<endl;
    cdll.display();
    
}

 //                Implementation of circular doubly linked list is Done successfully .
 //                  WELL DONE ! SHIVAM , DATE - 14-02-2024 , WED , SARASWATI PUJA.