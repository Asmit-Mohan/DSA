/* Recursive Approach */

void reverse(queue < int > & q)
{
    if (q.empty())
    {
    	return;
    }
    
    int data = q.front();
    q.pop();
    reverse(q);
    q.push(data);
}

/* Time :- O(N) Space :- O(N) [ Auxiliary Stack Space ] */

void reverse(queue < int > & q)
{
   if(q.size()==1)
   {
      return;
   }
   int temp=q.front();
   q.pop();	
   reverse(q);
   q.push(temp);
}

/* Time :- O(N) Space :- O(N) Iterative Method */

void reverse(queue < int > & q)
{
    int n = q.size();
    vector < int > nums(n);
    for (int i = n - 1; i >= 0; --i)
    {
	nums[i] = q.front();
        q.pop();
    }
    for (int i = 0; i < n; i++)
    {
       q.push(nums[i]);
    }
}
