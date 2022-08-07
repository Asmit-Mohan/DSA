class Solution
{
public:
    
void solve(int node,vector<int>&vis,vector<int>adj[])
{
      vis[node]=1;
      for(auto x : adj[node])
      {
          if(vis[x]==0)
          {
              solve(x,vis,adj);
          }
      }
}

int dfsOfGraph(int V, vector<int> adj[])
{
        vector<int>vis(V+1,0);
        int ans=0;
        
        for(int i=1;i<=V;i++)
        {
            if(vis[i]==0)
            {
                solve(i,vis,adj);
                ans++;
            }
        }
        return ans;
}
    
    int findCircleNum(vector<vector<int>>& arr)
    {
        int n=arr.size();
        
        vector<int>adj[n+1];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]==1&&i!=j)
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        return dfsOfGraph(n, adj);
    }
};
