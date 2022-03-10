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
