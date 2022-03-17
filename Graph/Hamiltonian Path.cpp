class Solution
{
    public:
    
    bool dfs(int num,int c,vector<int> arr[],int n,int m, vector<int>& visit)
    {
        if(c==n)
        {
            return true;
        }
        visit[num] = 1;
        for(auto x : arr[num])
        {
            if(!visit[x])
            {
                if(dfs(x,c+1,arr,n,m,visit))
                {
                    return true;
                }
            }
        }
        visit[num] = 0;
        return false;
    }
    
    bool check(int n,int m,vector<vector<int>> Edges)
    {
        vector<int> arr[n+1];
        vector<int> visit(n+1,0);
        
        for(auto x : Edges)
        {
            arr[x[0]].push_back(x[1]);
            arr[x[1]].push_back(x[0]);
        }
       
       for(int i=1;i<=n;i++)
       {
           if(dfs(i,1,arr,n,m,visit))
           {
               return true;
           }
       }
       return false;
    }
};
