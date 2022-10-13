#include<iostream>
#define SIZE 5
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node()
    {
        next = NULL;
    }
};

Node *front=NULL;
Node *rear=NULL;
Node *n;
Node *temp;
Node *temp1;

class cqueue
{
    public:
    void insertion();
    void deletion();
    void display();
};

int main()
{
   cqueue cqobj;
   int ch;
   cout<<"[1] Insert element to queue"<<endl;
   cout<<"[2] Delete element from queue"<<endl;
   cout<<"[3] Display all the elements of queue"<<endl;
   cout<<"[4] Exit"<<endl;
   do
   {
     cout<<"\nEnter your choice : "<<endl;
     cin>>ch;
     switch(ch)
     {
        case 1:
          cqobj.insertion();
          break;

        case 2:
          cqobj.deletion();
          break;

        case 3:
          cqobj.display();
          break;

        case 4:
          break;

        default:
          cout<<"\n\nWrong Choice!!! Try Again.";
     }
  }
  while(ch!=4);
  return 0;
}

void cqueue::insertion()
{
      n=new Node[sizeof(Node)];
      cout<<"\nEnter the Element: ";
      cin>>n->data;

      if(front==NULL)
      {
          front=n;
      }
      else
      {
          rear->next=n;
      }
      rear=n;
      rear->next=front;
}

void cqueue::deletion()
{
  int x;
  temp=front;
  if(front==NULL)
  {
      cout<<"\nCircular Queue Empty!!!";
  }
  else
  {
     if(front==rear)
     {
       x=front->data;
       delete(temp);
       front=NULL;
       rear=NULL;
     }
     else
     {
        x=temp->data;
        front=front->next;
        rear->next=front;
        delete(temp);
     }
     cout<<"\nElement "<<x<<" is Deleted";
     display();
  }
}

void cqueue::display()
{
  temp=front;
  temp1=NULL;
  if(front==NULL)
  {
    cout<<"\n\nCircular Queue Empty!!!";
  }
  else
  {
    cout<<"\n\nCircular Queue Elements are:\n\n";
    while(temp!=temp1)
    {
       cout<<temp->data<<"  ";
       temp=temp->next;
       temp1=front;
    }
  }
}
