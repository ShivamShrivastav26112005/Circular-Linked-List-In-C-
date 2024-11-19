// Circular Sll
// Circular Dll

// almost code is same in both CSll and CDll
// but also add some new codes in both type of circular sll and dll

//      ****************** Implementation of Circular Singly Linked List *********************


#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class CircularSinglyLinkedList
{
public:
    int size;
    Node *head;
    Node *tail;

    CircularSinglyLinkedList()
    {
        head = tail = NULL;
        size = 0;
    }

    void insertathead(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            head = tail = temp;
            tail->next = head;
            size++;
        }
        else
        {
            temp->next = head;
            tail->next = temp;
            head = temp;
            size++;
        }
    }

    void insertattail(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            head = tail = temp;
            tail->next = head;
            size++;
        }
        else
        {
            Node *temp = head;
            Node *t = new Node(val);
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = t;
            t->next = head;
            tail = t;
            size++;
        }
    }

    void insertatidx(int idx, int val)
    {
        if (idx < 0 || idx > size)
        {
            cout << " Invalid Index ";
            return;
        }
        else if (idx == 0)
        {
            insertathead(val);
        }
        else if (idx == size)
        {
            insertattail(val);
        }
        else
        {
            Node *temp = head;
            Node *t = new Node(val);
            for (int i = 1; i < idx; i++)
            {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    void deleteathead()
    {
        if (size == 0)
        {
            cout << "Circular Singly Linked List is empty! Underflow ";
            return;
        }
        else
        {
            head = head->next;
            size--;
        }
    }

    void deleteattail()
    {
        if (size == 0)
        {
            cout << " C S L L is empty !";
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = head;
            tail = temp;
            size--;
        }
    }

    void deleteatidx(int idx)
    {
        if (idx < 0 || idx > size)
        {
            cout << "Invalid index !";
            return;
        }
        else if (idx == 0)
        {
            deleteathead();
        }
        else if (idx == size)
        {
            deleteattail();
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < idx; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            size--;
        }
    }

    int getathead()
    {
        if (size == 0)
        {
            cout << " List is Null ";
            return -1;
        }
        else
        {
            cout << head->val;
        }
        cout<<endl;
    }

    int getattail()
    {
        if (size == 0)
        {
            cout << " List is Empty ";
            return -1;
        }
        else
        {
            cout << tail->val;
        }
        cout<<endl;
    }

    int getatidx(int idx)
    {
        if (idx < 0 || idx > size)
        {
            cout << "invalid Index";
            return -1;
        }
        else if (idx == 0)
        {
            return getathead();
        }
        else if (idx == size)
        {
            return getattail();
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i <= idx; i++)
            {
                temp = temp->next;
            }
            cout << temp->val;
        }
        cout<<endl;
    }

    void display()
    {
        Node *temp = head;
        while (true)
        {
            cout << temp->val << " ";
            temp = temp->next;
            if(temp==head) break;
        }
        cout << endl;
    }
};

int main()
{
    CircularSinglyLinkedList csll;

    csll.insertathead(10);
    csll.display();
    csll.insertathead(20);
    csll.insertathead(30);
    csll.insertathead(40);
    csll.insertathead(50);
    csll.display();

    // csll.insertattail(10);
    // csll.insertattail(20);
    // csll.insertattail(30);
    // csll.insertattail(40);
    // csll.display();
    // csll.insertattail(50);
    // csll.display();
    // cout<<endl;

    csll.insertatidx(2, 200);
    csll.insertatidx(3, 300);
    csll.display();
    csll.insertatidx(4, 400);
    csll.insertatidx(5, 500);
    csll.display();
    csll.insertatidx(1, 100);
    csll.display();
 

    // csll.deleteathead();
    // csll.display();
    // csll.deleteathead();
    // csll.display();
    // cout<<endl;


    // csll.deleteattail();
    // csll.display();
    // csll.deleteattail();
    // csll.display();

    // csll.deleteatidx(2);
    // csll.display();
    // csll.deleteatidx(4);
    // csll.display();
    // cout<<endl;

    // csll.getathead();

    // csll.getattail();

    // csll.getatidx(2);

    // csll.display();
    // cout << csll.size;



}

// done code