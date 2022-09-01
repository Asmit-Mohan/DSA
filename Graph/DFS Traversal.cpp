/* Time :- O(V+E) Space :- O(V) + O(V) */

class Solution
{
  public:
    
    void solve(int node,vector<int>&ans,vector<int>&visited,vector<int>adj[])
    {
        visited[node]=1;
        ans.push_back(node);
        
        for(auto x : adj[node])
        {
            if(visited[x]==0)
            {
                solve(x,ans,visited,adj);
            }
        }
    }
    
    vector<int> dfsOfGraph(int v, vector<int> adj[])
    {
        vector<int>ans;
        vector<int>visited(v,0);
        
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                solve(i,ans,visited,adj);
            }
        }
        return ans;
    }
};
