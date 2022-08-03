/* Approach 1 Time :- O(4*W) Space :-  O(4*W) */

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

/* Approach 2 Time :- O(4*W) Space :-  O(4*W) + O(N) Recursive Stack */

class Solution
{
    public:
    int solve(int w, int wt[], int n, vector<vector<int>> &dp)
    {
        if(n==0)
        {
            return dp[n][w] = INT_MIN;
        }
        
        if(w==0)
        {
            return dp[n][w] = 0;
        }
        
        if(dp[n][w] != -1)
        {
            return dp[n][w];
        }
        
        if(wt[n-1] > w)
        {
            return dp[n][w] = solve(w, wt, n-1, dp);
        }
        
        return dp[n][w] = max(1 + solve(w-wt[n-1] , wt, n, dp),solve(w, wt, n-1, dp));
    }
    
    int maximizeTheCuts(int w, int x, int y, int z)
    {
        int n=3;
        int arr[4]={x,y,z};
        
        vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
        int ans = solve(w, arr, n, dp);
        return ans<=0?0:ans;
    }
};
