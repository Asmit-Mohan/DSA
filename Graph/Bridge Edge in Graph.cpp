class Solution
{
public:

void dfs(int src, vector<int>&vis, vector<int> adj[])
{
    vis[src]=1;
    for(auto x : adj[src])
    {
        if(vis[x]==0)
        {
           dfs(x,vis,adj);
        }
    }
}

    int isBridge(int V, vector<int> graph[], int c, int d) 
    {
        vector<int> adj[V];
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            for( auto x : graph[i])
            {
                if((x==c and i==d) || (x==d and i==c))
                {
                    continue;
                }
                adj[i].push_back(x);
                adj[x].push_back(i);
            }
        }
        
        dfs(c,vis,adj);
        
        if(vis[d]==1)  /*It Means c and d lies in same component then it's not a bridge*/
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};
