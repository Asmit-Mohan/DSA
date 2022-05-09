class Solution
{
public:
    void solve(int u,vector<vector<int>>&graph,vector<bool>vis,int count,int &ans,int curr_cost,int n)
    {
        vis[u]=true;
        count++;
        
        if(count==n)
        {   
            if(graph[u][0] && (curr_cost+graph[u][0])<ans)
            {
                ans=curr_cost + graph[u][0];
            }
            vis[u]=false;
            return;
        }
        
        for(int v=0;v<n;v++)
        {
            if(graph[u][v] && vis[v]==false)
            {
                solve(v, graph, vis, count, ans, curr_cost+graph[u][v] ,n);
            }
        }
        vis[u]=false;
    }
     
    int total_cost(vector<vector<int>>graph)
    {
        int n=graph.size();
        int ans=INT_MAX;
        vector<bool> vis(n,false);
        solve(0,graph,vis,0,ans,0,n);
        return ans==INT_MAX?0:ans;
    }
};
