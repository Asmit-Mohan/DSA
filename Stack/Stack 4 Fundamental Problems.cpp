/* Time :- O(N) Space :- O(N) */

Qno1:- (NGR) | Nearest Greater to right :- 
	
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack <long long >s;
    vector<long long >v;
    for(int i=n-1;i>=0;i--)
    {
	if(s.empty())   //Only for the last element
	{
	     v.push_back(-1);
	}
	else if(s.size()>0&&s.top()>arr[i])
	{
             v.push_back(s.top());
	}
	else if(s.size()>0 && s.top()<=arr[i])
	{
	    while(s.size()>0 && s.top()<=arr[i])
	    {
	        s.pop();
	    }
	    if(s.size()==0)
	    {
		v.push_back(-1);
	    }
	    else
	    {
		v.push_back(s.top());
	    }
	}
	s.push(arr[i]);
     }
     reverse(v.begin(),v.end());
     return v;
}

/* Time :- O(N) Space :- O(N) */

Qno2:- (NGL) Nearest Greater to left:-
	
#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector <int> arr;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    int temp;
	    cin>>temp;
	    arr.push_back(temp);
	}
	stack <int> s;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		if(s.empty())
		{
		    v.push_back(-1);
		}
		else
		{
		    while(!s.empty() && s.top()<=arr[i])
		    {
			s.pop();
		    }
		    if(s.empty())
		    {
			v.push_back(-1);
		    }
		    else
		    {
			v.push_back(s.top());
		    }
		}
		s.push(arr[i]);
	}
	for(int i=0;i<v.size();i++)
	{
	   cout<<v[i]<<" ";
           cout<<"\t";
	}
	return 0;
}

/* Time :- O(N) Space :- O(N) */

Qno3:-(NSL) NEAREST SMALLER TO LEFT:-

vector<int> leftSmaller(int n, int a[])
{
	stack <int>s;
	vector<int>v;
	for(int i=0;i<n;i++)
	{
	  if(s.empty())
	  {
	     v.push_back(-1);
	  }
	  else if(s.size()>0&&s.top()<a[i])
	  {
	     v.push_back(s.top());
	  }
	  else if(s.size()>0 && s.top()>=a[i])
	  {
	      while(s.size()>0 && s.top()>=a[i])
	      {
		 s.pop();
	      }
	      if(s.size()==0)
	      {
		   v.push_back(-1);
	      }
	      else
	      {
		   v.push_back(s.top());
	      }
          }
	  s.push(a[i]);
	}
	return v;
}

/* Time :- O(N) Space :- O(N) */

Qno4:-(NSR) Nearest Smaller to Right :-

#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector <int> a;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	stack <int>s;
	vector<int>v;
	for(int i=n-1;i>=0;i--)
	{
	if(s.empty())
	{
	    v.push_back(-1);
	}
	else if(s.size()>0&&s.top()<a[i])
	{
	    v.push_back(s.top());
	}
	else if(s.size()>0 && s.top()>=a[i])
	{
	while(s.size()>0 && s.top()>=a[i])
	{
	    s.pop();
	}
	if(s.size()==0)
	{
	    v.push_back(-1);
	}
	else
	{
	v.push_back(s.top());
	}
	}
	s.push(a[i]);
	}
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
		cout<<"\t";
	}
	return 0;
}
