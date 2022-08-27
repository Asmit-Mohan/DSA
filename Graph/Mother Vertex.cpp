/* Time :- O(V+E) Space :- O(V) + O(V) */

class Solution 
{
    public:
	void dfs(int node, vector<int> &vis, vector<int> adj[])  
	{
	    vis[node] = 1; 
	    for(auto it : adj[node])
	    {
		if(vis[it]==0)
		{
		    dfs(it, vis, adj);
		}
	    }
	}
	int findMotherVertex(int V, vector<int>adj[])
	{
	   int ans;
	   vector<int>vis(V,0);
	   
	   for(int i=0;i<V;i++)
	   {
	       if(vis[i]==0)
	       {
	           dfs(i,vis,adj);
	           ans=i;
	       }
	   }
	   
	   for(int i=0;i<V;i++)
	   {
	       vis[i]=0;
	   }
	   
	   dfs(ans,vis,adj);
	   for(int i=0;i<V;i++)
	   {
	       if(vis[i]==0)
	       {
	           return -1;
	       }
	   }
	   return ans;
	}
};
