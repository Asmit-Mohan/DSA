/* Approach 1 Time Complexity :- O(V+E) Space Complexity :- O(V) + O(V) */

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

/* Approach 2 (BFS) (kahn's Algorithms) Time Complexity :- O(V+E) Space Complexity :- O(V) + O(V) */

class Solution
{
  public:
    bool isCyclic(int V, vector<int> adj[])
    {
	    queue<int>q;
	    vector<int>indegree(V,0);
	    int count=0;
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    for(int i=0;i<indegree.size();i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int temp=q.front();
	        q.pop();
	        count++;
		    
	        for(auto it : adj[temp])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	    return count==V?0:1;
    }
};

/* Logic:- Topological sort can only be done on DAG (Directed Acyclic graph) so if toposort exists then no cyclic else cyclic */
