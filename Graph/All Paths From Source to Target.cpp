class Solution
{
public:
    vector<vector<int>>ans;
    
    void dfs(int src,int des,vector<int>&result,vector<int>adj[])
    {
        result.push_back(src);
        
        if(src==des)
        {
            ans.push_back(result);
            return;
        }
        
        for(auto x : adj[src])
        {
           dfs(x,des,result,adj);
           result.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        int n=graph.size();
        vector<int>adj[n];
        vector<int>path;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                if(graph[i].size()>0)
                {
                    adj[i].push_back(graph[i][j]);
                }
            }
        }
        
        dfs(0,n-1,path,adj);
        return ans;
    }
};
