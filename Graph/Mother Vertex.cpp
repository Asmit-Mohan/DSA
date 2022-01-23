class Solution 
{
    public:
    void dfs(int node, vector<int> &vis, vector<int> adj[])  
    {
        vis[node] = 1; 
        for(auto it : adj[node])
        {
            if(vis[it]==0)
            {
                dfs(it, vis, adj);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	   vector<int> vis(V,0); 
	   int last_dfs;
       for(int i=0;i<V;i++)
       {
         if(vis[i]==0)
         {
             dfs(i,vis,adj); 
             last_dfs=i;
         }
      }
      for(int i=0;i<V;i++)
      {
          vis[i]=0;
      }
      dfs(last_dfs,vis,adj);
      for(int i=0;i<V;i++)
      {
          if(vis[i]==0)
          {
              return -1;
          }
      }
      return last_dfs;
	}
};
