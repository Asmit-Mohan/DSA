/*Approach 1 (DFS)*/

class Solution
{
  public:

   bool solve(int node,int parent,vector<int>&vis,vector<int>adj[])
   {
      vis[node]=1;
      for(auto it : adj[node])
      {
          if(vis[it]==0)
          {
              if(solve(it,node,vis,adj))
              {
                  return 1;
              }
          }
          else if(it!=parent)
          {
              return 1;
          }
      }
      return 0;
   }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(solve(i,-1,vis,adj))
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};

/*Approach 2 (BFS)*/

class Solution
{
  public:
    bool checkForCycle(int node, int V, vector<int> adj[], vector<int>& vis)
    {
        queue<pair<int,int>> q;
        vis[node] = 1;
        q.push({node,-1});
        while(!q.empty())
        {
            int child  = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adj[child])
            {
                if(vis[it] == 0)
                {
                    vis[it] = 1;
                    q.push({it,child});
                }
                else if(it!=parent)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    bool isCycle(int n, vector<int> adj[])
    {
	    vector<int> vis(n, 0); 
	    for(int i=0;i<n;i++)
	    {
	        if(vis[i]==0)
	        {
	            if(checkForCycle(i, n, adj, vis))
	            {
	                return true; 
	            }
	        }
	    }
	    return false;
    }
};
