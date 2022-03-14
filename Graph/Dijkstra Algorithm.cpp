/* Approach 1 */

class Solution
{
        public:
        vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
        {
        vector<int>dis(V);
        for(int i=0;i<V;i++)
        {
        	  dis[i]=INT_MAX;
        }
        
        queue<pair<int,int>>q;
        q.push({src,0});
        dis[src]=0;
        
        while(!q.empty())
        {
        	pair<int,int> node=q.front();
        	q.pop();
        	for(auto it : adj[node.first])
        	{
        		if(dis[it[0]]>dis[node.first]+it[1])
        		{
        			dis[it[0]]=dis[node.first]+it[1];
        			q.push({it[0],it[1]});
        		}
        	}
        }
        return dis;
    }
};

/*Approach 2*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
        int source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1]; 
	int a,b,wt;
  
	for(int i = 0; i<m ; i++)
        {
	    cin >> a >> b >> wt;
	    g[a].push_back(make_pair(b,wt));
	    g[b].push_back(make_pair(a,wt));
	}
	cin >> source;
  
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	vector<int> distTo(n+1,INT_MAX);
	distTo[source] = 0;
	pq.push(make_pair(0,source));	
	
	while( !pq.empty() )
	{
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++)
		{
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist)
			{
          		    distTo[next] = distTo[prev] + nextDist;
          		    pq.push(make_pair(distTo[next], next));
			}
		}
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)
	{
	    cout << distTo[i] << " ";
	}
	cout << "\n";
	return 0;
}
