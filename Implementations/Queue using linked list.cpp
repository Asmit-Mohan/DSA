#include <iostream>
using namespace std;

class Node
{
   public:
   int data;
   Node* next;

   Node(int value)
   {
       data=value;
       next=NULL;
   }
};

Node* front = NULL;
Node* rear = NULL;
Node* temp = NULL;

void push(int val)
{
   if (rear == NULL)
   {
      rear = new Node(val);
      front = rear;
   }
   else
   {
      temp = new Node(val);
      rear->next = temp;
      rear = temp;
   }
}
void pop()
{
   temp = front;
   if (front == NULL)
   {
      cout<<"Underflow"<<endl;
      return;
   }
   else if (temp->next != NULL)
   {
      temp = temp->next;
      cout<<"Element deleted from queue is : "<<front->data<<endl;
      free(front);
      front = temp;
   }
   else
   {
      cout<<"Element deleted from queue is : "<<front->data<<endl;
      free(front);
      front = NULL;
      rear = NULL;
   }
}

void display()
{
   temp = front;
   if ((front == NULL) && (rear == NULL))
   {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are: ";
   while (temp != NULL)
   {
      cout<<temp->data<<" ";
      temp = temp->next;
   }
   cout<<endl;
}

int main()
{
   int ch, val;
   cout<<"[1] Insert in queue"<<endl;
   cout<<"[2] Delete from queue"<<endl;
   cout<<"[3] Display queue"<<endl;
   cout<<"[4] Exit"<<endl;

   do
   {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch)
      {
         case 1:
         {
            cout<<"Enter value to be inserted:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2:
         {
            pop();
            break;
         }
         case 3:
         {
            display();
            break;
         }
         case 4:
         {
            cout<<"Exit"<<endl;
            break;
         }
         default:
         {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }
   while(ch!=4);
   return 0;
}
