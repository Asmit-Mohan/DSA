/* Time :- O(N) for getMin else O(1) for all other function && Space :- O(1) */

void push(stack<int>& s, int a)
{
	s.push(a);
}

bool isFull(stack<int>& s,int n)
{
	if(s.size()==n)
	{
	    return 1;
	}
	else
	{
	    return 0;
	}
}

bool isEmpty(stack<int>& s)
{
	if(s.empty())
	{
	    return 1;
	}
	else
	{
	    return 0;
	}
}

int pop(stack<int>& s)
{
	return s.top();
	s.pop();
}
int getMin(stack<int>& s)
{
    int mn=s.top();
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        int temp=s.top();
        mn=min(mn,temp);
        s.pop();
    }
    return mn;
}
