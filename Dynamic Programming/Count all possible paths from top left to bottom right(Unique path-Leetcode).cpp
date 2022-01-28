class Solution
{
  public:
    long long int numberOfPaths(int m, int n)
    {
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        long long mod=pow(10,9)+7;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    dp[i][j]=(dp[i-1][j]%mod)+(dp[i][j-1]%mod);
                }
            }
        }
        return dp[m-1][n-1]%mod;
    }
};
