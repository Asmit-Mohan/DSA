class Solution
{
  public:
  void solve(int node,vector<int>&ans,vector<int>&vis,vector<int>adj[])
  {
      vis[node]=1;
      ans.push_back(node);
      for(auto x : adj[node])
      {
          if(vis[x]==0)
          {
              solve(x,ans,vis,adj);
          }
      }
  }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int>ans;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                solve(i,ans,vis,adj);
            }
        }
        return ans;
    }
};
