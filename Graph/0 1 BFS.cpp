/* Time :- O(V+E) Space :- O(V+E) + O(V) + O(V) */

#include<bits/stdc++.h>
using namespace std;

void solve(int src,int v,vector<pair<int,int>>adj[])
{
	int dist[v];
	for (int i=0; i<v; i++)
	{
	    dist[i] = INT_MAX;
	}

	deque<int>q;
	dist[src] = 0;
	q.push_back(src);

	while (!q.empty())
	{
		int parent = q.front();
		q.pop_front();
		
		for (auto it : adj[parent])
		{
			int child=it.first;
			int weight=it.second;
			
			if (dist[child]> dist[parent] + weight)
			{
			    dist[child] = dist[parent] + weight;
			    if (weight == 0)
			    {
				q.push_front(child);
			    }
			    else
			    {
				q.push_back(child);
			    }
			}
		}
	}

	for (int i=0; i<v; i++)
	{
		cout << dist[i] << " ";
	}
}


int main()
{
	int n,edge;
	cin>>n>>edge;
	vector <pair<int,int>> adj[n];
		
	for(int i=0;i<edge;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		adj[u].push_back({v,wt});
	}
	
	int src;
	cin>>src;
	solve(src,n,adj);
	return 0;
}


/*

Sample Test Case :- 
Input:-
9 13
0 1 0
0 7 1
1 7 1
1 2 1
2 3 0
2 5 0
2 8 1
3 4 1
3 5 1
4 5 1
5 6 1
6 7 1
7 8 1
0
Output:-
0 0 1 1 2 1 2 1 2 

*/
