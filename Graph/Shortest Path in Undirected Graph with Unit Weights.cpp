class Solution
{
    public:
    vector <int> shortestPath(int V, vector<int> adj[], int src)
    {
        vector<int>dis(V);
        for(int i=0;i<V;i++)
        {
            dis[i]=INT_MAX;
        }
        
        queue<int>q;
        q.push(src);
        dis[src]=0;
        
        while(!q.empty())
        {
        	int node=q.front();
        	q.pop();
        	for(auto it : adj[node])
        	{
        	    if(dis[it]>dis[node]+1)
        	    {
        		 dis[it]=dis[node]+1;
        		 q.push(it);
        	    }
        	}
        }
        return dis;
    }
};
