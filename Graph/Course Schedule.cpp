/* Approach 1 Time :- O(V+E) Space :- O(V+E) */

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
    
    bool canFinish(int v, vector<vector<int>>& edges)
    {
        vector<int>adj[v];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);    
        }
        return isCyclic(v, adj)==1?0:1;
    }
};


/* Approach 2 Kahn's Algorithm */

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {    
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        
        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue<int> q;
        for (int i=0; i< indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        int count=0;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            count++;
            
            for (auto i: adj[v])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        
        for (int i=0; i< indegree.size(); i++)
        {
            if (indegree[i] > 0) 
            {
                return false;
            }
        }
        return true;
    }
};
