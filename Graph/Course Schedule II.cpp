/* Approach 1 Kahn's Algorithms */

class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre)
    {    
        vector<vector<int>>adj(n);
        for(auto it:pre)
        {
            adj[it[1]].push_back(it[0]);
        }
        
        queue<int>q;
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        vector<int>res;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
      
        if(res.size()==n)
        {
            return res;
        }
        return {};
    }
};

/* Approach 2 Time :- [DFS] O(V+E) Space :- O(V+E) */

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
    
    void toposort(int node,stack<int>&s,vector<int>&vis,vector<int>adj[])
    {
      vis[node]=1;
      for(auto x : adj[node])
      {
          if(vis[x]==0)
          {
              toposort(x,s,vis,adj);
          }
      }
      s.push(node);
    }
    
    vector<int> findOrder(int V, vector<vector<int>>& graph)
    {
        vector<int>adj[V];
        vector<int>ans;
        
        for(int i=0;i<graph.size();i++)
        {
            adj[graph[i][1]].push_back(graph[i][0]);
        }
        
        if(isCyclic(V, adj))
        {
            return ans;
        }
       
        vector<int>vis(V,0);
        stack<int>s;
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                toposort(i,s,vis,adj);
            }
        }
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
