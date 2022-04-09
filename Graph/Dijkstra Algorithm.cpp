/* Approach 1 */

class Solution
{
    public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        vector<int>dis(V);
        queue<int>q;
        q.push(src);
        
        for(int i=0;i<V;i++)
        {
            dis[i]=INT_MAX;
        }
        
        dis[src]=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it : adj[node])
            {
                int child=it[0];
                int weight=it[1];
                if(dis[child]>dis[node]+weight)
                {
                    q.push(child);
                    dis[child]=dis[node]+weight;
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
