/* Time :- O(N*N) Space :- O(N) [Time :- O(N) for sort function and O(N) for insert function]*/

void insert(stack<int>&s,int temp)
{
    if(s.empty()||temp>=s.top())
    {
        s.push(temp);
        return;
    }
    int first=s.top();
    s.pop();
    insert(s,temp);
    s.push(first);
}

void SortedStack :: sort()
{
   if(s.size()==1)
   {
       return;
   }
   int temp=s.top();
   s.pop();
   sort();
   insert(s,temp);
   return;
}
