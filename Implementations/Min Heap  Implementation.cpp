#include<bits/stdc++.h>
using namespace std;

class minheap
{
    public:
    vector<int>v;
    void heapify()
    {
      int idx=0;
      while(idx<v.size()/2)
      {
           int i=idx;
           int left=2*idx+1;
           int right=2*idx+2;

           if(left<v.size()&&v[left]<v[idx])
           {
              idx=left;
           }
           if(right<v.size()&&v[right]<v[idx])
           {
              idx=right;
           }
           if(idx!=i)
           {
              swap(v[idx],v[i]);
           }
           else
           {
               break;
           }
       }
    }
    void pop()
    {
        swap(v[0],v[v.size()-1]);
        v.pop_back();
        heapify();
    }

    int get_min()
    {
        if(v.size()==0)
        {
            return -1;
        }
        return v[0];
    }

    int get_size()
    {
        return v.size();
    }

    void push(int val)
    {
        v.push_back(val);
        int idx=v.size()-1;
        while(idx/2>=0&&v[idx]<v[idx/2])
        {
            swap(v[idx],v[idx/2]);
            idx=(idx/2);
        }
    }
};

int main()
{
   minheap mn;
   int ch, val;
   cout<<"[1] Push in min heap"<<endl;
   cout<<"[2] Pop from min heap"<<endl;
   cout<<"[3] Get minimum"<<endl;
   cout<<"[4] Get Size"<<endl;
   cout<<"[5] Exit"<<endl;

   do
   {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch)
      {
         case 1:
         {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            mn.push(val);
            break;
         }
         case 2:
         {
            mn.pop();
            break;
         }
         case 3:
         {
            cout<<mn.get_min()<<endl;
            break;
         }
         case 4:
         {
            cout<<mn.get_size()<<endl;;
            break;
         }
         case 5:
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
   while(ch!=6);
   return 0;
}
