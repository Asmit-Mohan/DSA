/* 

Time Complexity : O(N+E) where N = Nodes , E = travelling through adjacent nodes

Space Complexity : O(N+E) + O(N) + O(N) for Space for adjacency list, visited array, Auxiliary Space respectively

*/

#include<bits/stdc++.h>
using namespace std;

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
    
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
   

        vector<int> ans = dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
