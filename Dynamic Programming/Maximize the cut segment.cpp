class Solution
{
    public:
    int maximizeTheCuts(int w, int x, int y, int z)
    {
        int n=3;
        int arr[n]={x,y,z};
        int dp[n+1][w+1];
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<w+1;j++)
        {
            dp[0][j]=INT_MIN;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<w+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j]=max(1+dp[i][j-arr[i-1]],dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][w]>0?dp[n][w]:0;
    }
};
