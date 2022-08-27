/* Time :- O(N+E) Space :- O(N+E) + O(N) + O(N) */

class Solution
{
    public:
    void dfs(int node,stack<int>&s,vector<int>&vis,vector<int>adj[],int v)
    {
       vis[node]=1;
       for(auto it:adj[node])
       {
           if(vis[it]==0)
           {
               dfs(it,s,vis,adj,v);
           }
       }
       s.push(node);
    }
   
   void revdfs(int node,vector<int>&vis,vector<int>adj[],int v)
   {   
       vis[node]=1;
       for(auto it :adj[node])
       {
           if(!vis[it])
           {
               revdfs(it,vis,adj,v);
           }
       }
   }
  
   int kosaraju(int V, vector<int> adj[])
   {
       stack<int>s;
       vector<int>vis(V,0);
       
       for(int i=0;i<V;i++)  /* Step 1 Finding TopoSort For Finish Time In Decreasing Order */
       {
           if(vis[i]==0)
           {
               dfs(i,s,vis,adj,V);
           }
       }
       
       vector<int>transpose[V];
       for(int i=0;i<V;i++)    /* Step 2 Reversing Graph */
       {
           vis[i]=0;
           for(auto it:adj[i])
           {
               transpose[it].push_back(i);
           }
       }
       
       int ans=0;
       while(!s.empty())  /* Step 3 Calling DFS On Decreasing Finish Time */
       {
           int node=s.top();
           s.pop();
           if(vis[node]==0)
            {
                revdfs(node,vis,transpose,V);
                ans++;
            }
       }
       return ans;
  }
