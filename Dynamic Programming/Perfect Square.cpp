class Solution
{
public:
    int solve(int n)
    {
        if(n == 0)
        {
            return 0;
        }
        
        int mini = INT_MAX;
        for(int i = 1; i * i <= n; i++)
        {
            int perfectSquare = i * i;
            int ans = 1 + solve(n - perfectSquare);
            mini = min(mini,ans);
        }
        return mini;
    }
    int numSquares(int n)
    {     
        return solve(n);
    }
};

/* TC - O(N * sqrt(N)) and SC - O(N) */
class Solution
{
public:
    int solveMem(int n, vector<int>& dp)
    {
        if(n == 0)
        {
            return 0;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        int mini = INT_MAX;
        for(int i = 1; i * i <= n; i++)
        {
            int perfectSquare = i * i;
            int ans = 1 + solveMem(n - perfectSquare,dp);
            mini = min(mini,ans);
        }
        dp[n] = mini;
        return dp[n];
    }
    int numSquares(int n)
    {  
        vector<int> dp(n+1,-1);
        return solveMem(n,dp);   
    }
};

/* TC - O(N * sqrt(N)) and SC - O(N) */
class Solution
{
    public:
    int solveTab(int n)
    {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
      
        for(int i = 1; i <= n; i++)
        {
            int mini = INT_MAX;
            for(int j = 1; j * j <= i; j++)
            {
                int perfectSquare = j * j;
                int ans = 1 + dp[i - perfectSquare];
                mini = min(mini,ans);
            }
            dp[i] = mini;
        }
         return dp[n];
    }
    int numSquares(int n)
    {
        return solveTab(n);
    }
};
