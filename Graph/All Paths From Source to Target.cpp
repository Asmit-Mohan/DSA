class Solution
{
public:
    vector<vector<int>>ans;
    void solve(int src,int des,vector<int>&path,vector<vector<int>>&graph)
    {
        path.push_back(src); 
        if(src==des)
        {
            ans.push_back(path);
            return;
        }
        for(auto it : graph[src])
        {
            solve(it,des,path,graph);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        int n=graph.size();
        vector<int>path;
        solve(0,n-1,path,graph);
        return ans;
    }
};
