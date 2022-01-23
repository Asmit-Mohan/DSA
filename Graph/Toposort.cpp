/*Approach 1 (DFS)*/

class Solution
{
	public:
	void solve(int node,stack<int>&s,vector<int>&vis,vector<int>adj[])
    {
      vis[node]=1;
      for(auto x : adj[node])
      {
          if(vis[x]==0)
          {
              solve(x,s,vis,adj);
          }
      }
      s.push(node);
    }
    
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
        vector<int>vis(V,0);
        stack<int>s;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                solve(i,s,vis,adj);
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

/*Approach 2 (BFS)*/

