/* Time :- O(M*N) Space :- O(M*N) + O(N) For Recursive Stack */

class Solution
{
public:
    int dp[210][210];
    
    int solve(int i,int j,int row,int col,int prev,vector<vector<int>>& arr)
    {
        if(i<0||j<0||j>=col||i>=row||arr[i][j]<=prev)
        {
            return -1;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int a = 1 + solve(i+1,j,row,col,arr[i][j],arr);
        int b = 1 + solve(i,j+1,row,col,arr[i][j],arr);
        int c = 1 + solve(i-1,j,row,col,arr[i][j],arr);
        int d = 1 + solve(i,j-1,row,col,arr[i][j],arr);
        
        dp[i][j]=max({a,b,c,d});
        
        if(dp[i][j]==0)
        {
            dp[i][j]=1;
        }
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& arr)
    {
        int m=arr.size();
        int n=arr[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=1;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==-1)
                {
                    dp[i][j] = solve(i,j,m,n,-1,arr);               
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
