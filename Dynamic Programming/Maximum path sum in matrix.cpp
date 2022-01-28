class Solution
{
public:
    int maximumPath(int n, vector<vector<int>> a)
    {
        int dp[n+1][n+1];
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<n+1;j++)
        {
            dp[0][j]=0;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                dp[i][j]=a[i-1][j-1]+ max ({dp[i-1][j],dp[i-1][j+1],dp[i-1][j-1]});
            }
        }
        int res=INT_MIN;
        for(int i=0;i<n+1;i++)
        {
            res=max(res,dp[n][i]);
        }
        return res;
    }
};
