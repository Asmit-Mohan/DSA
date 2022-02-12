#include<bits/stdc++.h>
using namespace std;

struct node
{
	int u;
	int v;
	int wt;
	node(int first,int second,int weight)
	{
		u=first;
		v=second;
		wt=weight;
	}
};

int parent[1000];
int height[1000];

void make(int n)
{
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		height[i]=0;
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
    if(height[a]<height[b])
    {
      parent[a]=b;
    }
    else if(height[a]<height[b])
    {
      parent[b]=a;
    } 
    else
    {
      parent[b]=a;
      height[a]++;
    }
}
bool comp(node a,node b)
{
	return a.wt<b.wt;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<node>graph;
	
	while(m--)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		graph.push_back(node(u,v,wt));
	}
	sort(graph.begin(),graph.end(),comp);
	make(n);
	int cost=0;
	vector<pair<int,int>>mst;
    
    for(auto it : graph)
    {
    	if(findParent(it.u)!=findParent(it.v))
    	{
    	    cost=cost+it.wt;
    	    mst.push_back({it.u,it.v});
    	    findUnion(it.u,it.v);
    	}
    }
	cout<<cost<<endl;
	for(auto it : mst)
	{
		cout<<it.first<<"-"<<it.second<<endl;
	}
	return 0;
}
