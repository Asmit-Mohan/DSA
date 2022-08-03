/* Approach 1 Time :- O(N*W) Space :-  O(N*W) */

class Solution
{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int t[N+1][W+1];
        for(int i=0;i<N+1;i++)
        {
            for(int j=0;j<W+1;j++)
            {
                if(i==0||j==0)
                {
                    t[i][j]=0;
                }
            }
        }
        for(int i=1;i<N+1;i++)
        {
            for(int j=1;j<W+1;j++)
            {
                if(wt[i-1]<=j)
                {
                    t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
                }
                else
                {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[N][W];
    }
};

/* Approach 2 Time :- O(N*W) Space :-  O(N*W) + O(N)  */

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
        
        return dp[n][w] = max(val[n-1] + solve(w-wt[n-1] , wt, val, n, dp),solve(w, wt, val, n-1, dp));
    }
    
    int knapSack(int n, int w, int val[], int wt[])
    {
        vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
        return solve(w, wt, val, n, dp);
    }
};
