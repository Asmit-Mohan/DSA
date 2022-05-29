class Solution
{
public:
    int mod=pow(10,9) + 7;
    int solve(int n,int r,vector<vector<int>> &dp)
    {
    	if(dp[n][r]!=-1)
    	{
    	    return dp[n][r];
    	}
    	if(n==0)
    	{
    	    return dp[n][r]=0;
    	}
    	if(r==0)
    	{
    	    return dp[n][r]=1;
    	}
    	if(r==n)
    	{
    	    return dp[n][r]=1;
    	}
    	int a=solve(n-1,r-1,dp)%mod;
    	int b=solve(n-1,r,dp)%mod;
    	int ans=(a+b)%mod;
    	return dp[n][r]=ans;
    }
    int nCr(int n, int r)
    {
         vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
	     return solve(n,r,dp);
    }
};

/* Using the formula NCR = N-1 C R + N-1 C R-1 */ 
