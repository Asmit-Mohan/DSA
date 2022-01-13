class Solution
{
    int mn;
    stack<int> s;
    public:
       int getMin()
       {
           if(s.empty())
           {
               return -1;
           }
           return mn;
       }
       
       int pop()
       {
           if(s.empty())
           {
               return -1;
           }
           else if(s.top()>=mn)
           {
               int temp=s.top();
               s.pop();
               return temp;
           }
           else if(mn>s.top())
           {
               int res=mn;
               mn=(2*mn)-s.top();
               s.pop();
               return res;
           }
       }
       
       void push(int x)
       {
           if(s.empty())
           {
               mn=x;
               s.push(x);
           }
           else if(x>=mn)
           {
               s.push(x);
           }
           else if(x<mn)
           {
               int temp=(2*x)-mn;
               mn=x;
               s.push(temp);
           }
       }
};
