/* Time complexity :- O(N^2) and Space complexity :- O(N^2) */

class Solution
{
    public:
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        int dp[n+1][w+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<w+1;j++)
            {
                dp[i][j]=0;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<w+1;j++)
            {
                if(wt[i-1]<=j)
                {
                    dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }
};

/* Time complexity :- O(N^2) and Space complexity :- O(N^2) + Auxiliary Stack of O(N) */

class Solution
{
    public:
    
    int solve(int w, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        if(n==0 or w==0)
        {
            return dp[n][w] = 0;
        }
        
        if(dp[n][w] != -1)
        {
            return dp[n][w];
        }
        
        if(wt[n-1] > w)
        {
            return dp[n][w] = solve(w, wt, val, n-1, dp);
        }
        
        return dp[n][w] = max(val[n-1] + solve(w-wt[n-1] , wt, val, n-1, dp),solve(w, wt, val, n-1, dp));
    }
    
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
        return solve(w, wt, val, n, dp);
    }
};
