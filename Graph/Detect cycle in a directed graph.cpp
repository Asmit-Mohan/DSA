/*Approach 1 (DFS) */

class Solution
{
  public:
    bool solve(int node,vector<int>&dfsvis,vector<int>&vis,vector<int>adj[])
    {
      vis[node]=1;
      dfsvis[node]=1;
      for(auto it : adj[node])
      {
          if(vis[it]==0)
          {
              if(solve(it,dfsvis,vis,adj))
              {
                  return 1;
              }
          }
          else if(dfsvis[it]==1)
          {
              return 1;
          }
      }
      dfsvis[node]=0;
      return 0;
   }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int>vis(V,0);
        vector<int>dfsVis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(solve(i,vis,dfsVis,adj))
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};

/*Approach 2 (BFS) */

