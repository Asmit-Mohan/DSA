#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *prev, *next;

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

class Deque
{
    Node* head;
    Node* tail;
    int Size;

public:
    Deque()
    {
        head = tail = NULL;
        Size = 0;
    }

    void insertFront(int data);
    void insertRear(int data);
    void deleteFront();
    void deleteRear();
    int getFront();
    int getRear();
    int size();
    bool isEmpty();
};

bool Deque::isEmpty()
{
    return (head == NULL);
}

int Deque::size()
{
    return Size;
}

void Deque::insertFront(int data)
{
    Node* newNode = new Node(data);
    if (newNode == NULL)
    {
        cout << "OverFlow\n";
    }
    else
    {
        if (head == NULL)
        {
            tail = head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        Size++;
    }
}

void Deque::insertRear(int data)
{
    Node* newNode = new Node(data);
    if (newNode == NULL)
    {
        cout << "OverFlow\n";
    }
    else
    {
        if (tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        Size++;
    }
}

void Deque::deleteFront()
{
    if (isEmpty())
    {
        cout << "UnderFlow\n";
    }
    else
    {
        Node* temp = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }
        free(temp);
        Size--;
    }
}

void Deque::deleteRear()
{
    if (isEmpty())
    {
        cout << "UnderFlow\n";
    }
    else
    {
        Node* temp = tail;
        tail = tail->prev;
        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        free(temp);
        Size--;
    }
}

int Deque::getFront()
{
    if (isEmpty())
    {
        return -1;
    }
    return head->data;
}

int Deque::getRear()
{
    if (isEmpty())
    {
        return -1;
    }
    return tail->data;
}


int main()
{
      int c,i;
      Deque dq;
      cout<<"\n [1].insert at beginning";
      cout<<"\n [2].insert at end";
      cout<<"\n [3].get front element";
      cout<<"\n [4].get rear element";
      cout<<"\n [5].deletion from front";
      cout<<"\n [6].deletion from rear";
      cout<<"\n [7].size of dequeue";
      cout<<"\n [8].exit";


      do
      {
      cout<<"\n enter your choice:";
      cin>>c;
      switch(c)
      {
         case 1:
            cout<<"enter the element to be inserted at beg:- ";
            cin>>i;
            dq.insertFront(i);
         break;

         case 2:
            cout<<"enter the element to be inserted at end :- ";
            cin>>i;
            dq.insertRear(i);
         break;

         case 3:
             cout<<dq.getFront();
             cout<<endl;
         break;

         case 4:
             cout<<dq.getRear();
             cout<<endl;
         break;

         case 5:
            dq.deleteFront();
         break;

         case 6:
            dq.deleteRear();
         break;

         case 7:
            cout<<dq.size()<<endl;
         break;

         case 8:
            exit(1);
         break;

         default:
            cout<<"invalid choice";
         break;
      }
   }
   while(c!=9);

    return 0;
}
