/* Approach 1 */

class Solution
{
public:
    void dfs(int s, int n, vector<vector<int>>& isConnected, vector<bool>&visited)
    {
        visited[s] = true;
        vector<int>adj;
        for(int i=0; i<n; i++ )
        {
            int x =  isConnected[s][i];  
            if(x == 1)
            {
                 adj.push_back(i);
            }
        }
        
        for(auto x: adj)
        {
            if(!visited[x])
            {
                dfs(x, n, isConnected, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        
        int n = isConnected.size();
        vector<bool>visited(n, false);
        int count = 0;
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i, n, isConnected, visited);
            }
        }
        return count;
    }
};

/* Approach 2 */

#include<bits/stdc++.h>
using namespace std;

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
    
int main()
{
        int V, E;
        cin >> V >> E;
        vector<int> adj[V+1];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int ans=dfsOfGraph(V, adj);
        cout<<ans<<endl;
        
    return 0;
}
