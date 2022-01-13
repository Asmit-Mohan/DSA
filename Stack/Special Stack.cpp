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
#include<bits/stdc++.h>
int getMin(stack<int>& s)
{
    int n=s.size();
    int arr[n];
    for(int i=0;i<n;i++)
    {
        int temp=s.top();
        arr[i]=temp;
        s.pop();
    }
    sort(arr,arr+n);
    return arr[0];
}
