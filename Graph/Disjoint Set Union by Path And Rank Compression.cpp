/*Brute Force :- Time  More Than O(N^2) Space O(N) */  -->  By LUV

#include<bits/stdc++.h>
using namespace std;
int N=INT_MAX;
int parent[N];

void make(int n)
{
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
	}
}

int findParent(int n)
{
	if(n==parent[n])
	{
		return n;
	}
	return findParent(parent[n]);
}

void findUnion(int a,int b)
{
	a=findParent(a);
	b=findParent(b);
	if(a!=b)
	{
		parent[b]=a;
	}
}

int main()
{
	int n,t;
	cin>>n;
	make(n);
	while(t--)
	{
		int u,v;
		cin>>u>>v;
		findUnion(u,v);
	}
	int connectedComponent=0;
	for(int i=0;i<n;i++)
	{
		if(findParent(i)==i)
		{
			connectedComponent++;
		}
	}
	cout<<connectedComponent<<endl;
	return 0;
}

/* Approach 2 Efficient Time O(alpha(n)) ~~ constant mathematically proved */   -->  By LUV

#include<bits/stdc++.h>
using namespace std;
int N=INT_MAX;
int parent[N];
int size[N];

void make(int n)
{
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
	}
}

int findParent(int n)
{
	if(n==parent[n])
	{
		return n;
	}
	return parent[n] = findParent(parent[n]);
}

void findUnion(int a,int b)
{
	a=findParent(a);
	b=findParent(b);
	if(a!=b)
	{
		if(size(a)<size(b))
		{
			swap(a,b);
		}
		parent[b]=a;
		size[a]=size[a]+size[b];
	}
}

int main()
{
	int n,t;
	cin>>n;
	make(n);
	while(t--)
	{
		int u,v;
		cin>>u>>v;
		findUnion(u,v);
	}
	int countConnectedComponent=0;
	for(int i=0;i<n;i++)
	{
		if(findParent(i)==i)
		{
			countConnectedComponent++;
		}
	}
	cout<<countConnectedComponent<<endl;
	
	int a,b;
	cin>>a>>b;
	
	if(findParent(a)!=findParent(b))
	{
		cout<<"From Different Component"<<endl;
	}
	else
	{
		cout<<"From Same Component"<<endl;
	}
	
	return 0;
}

/*Approach 3 Striver*/

#include<bits/stdc++.h>
using namespace std;
int N=INT_MAX;
int parent[N];
int rank[N];  /* Rank is basically storing height of tree */

void make(int n)
{
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
}

int findParent(int n)
{
	if(n==parent[n])
	{
		return n;
	}
	return parent[n] = findParent(parent[n]);
}

void findUnion(int a,int b)
{
	a=findParent(a);
	b=findParent(b);
	if(rank[a]<rank[b])
	{
		parent[a]=b;
	}
	else if(rank[a]<rank[b])
	{
		parent[b]=a;
	} 
	else
	{
		parent[b]=a;
		rank[a]++;
	}
}

int main()
{
	int n,t;
	cin>>n;
	make(n);
	while(t--)
	{
		int u,v;
		cin>>u>>v;
		findUnion(u,v);
	}
	
	int a,b;
	cin>>a>>b;
	
	if(findParent(a)!=findParent(b))
	{
		cout<<"From Different Component"<<endl;
	}
	else
	{
		cout<<"From Same Component"<<endl;
	}
	return 0;
}
