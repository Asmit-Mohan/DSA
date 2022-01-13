void solve(stack<int>&s,int temp)
{
    if(s.empty()||temp>=s.top())
    {
        s.push(temp);
        return;
    }
    int first=s.top();
    s.pop();
    solve(s,temp);
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
   solve(s,temp);
   return;
}
