/* Approach 1 Time :- O(V*E) Space :- O(V) */

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


/* Approach 2 Time :- O [Vlogv + Elogv] Space :- O(V) */

#define pair pair<int,int>

class Solution
{
    public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int source)
    {
        priority_queue<pair,vector<pair>,greater<pair>> pq;
        
    	vector<int> dist(V,INT_MAX);
    	dist[source] = 0;
    	pq.push(make_pair(0,source));	
    	
    	while( !pq.empty() )
    	{
    		int weight = pq.top().first;
    		int parent = pq.top().second;
    		pq.pop();
    		
    		for(auto it : adj[parent])
    		{
    		    int next = it[0];
    		    int nextDist = it[1];
    			
    		    if( dist[next] > dist[parent] + nextDist)
    		    {
              		dist[next] = dist[parent] + nextDist;
              		pq.push(make_pair(dist[next], next));
    		    }
    		}
    	}
    	return dist;
    }
};
