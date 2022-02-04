class Solution
{
    public:
    int numTrees(int n) 
    {
        long long int dp[n+1]={0};
        long long int mod=pow(10,9)+7;
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<n+1;i++)
        {
            for(int j=0;j<i;j++)
            { 
                long long res=((dp[j]*dp[i-j-1])%mod);
                dp[i]=(dp[i]+res)%mod;
            }
        }
        return dp[n];
    }
};
