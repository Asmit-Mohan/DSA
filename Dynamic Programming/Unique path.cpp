/* Time and Space Complexity of both the approaches is O(M*N) */


/* Approach 1 */

class Solution
{
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>&dp)
    {
        if(i>=m||j>=n)
        {
            return 0;
        }
        if(i==m-1||j==n-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        return dp[i][j] = solve(i,j+1,m,n,dp) + solve(i+1,j,m,n,dp);
    }
    
    int uniquePaths(int m, int n)
    {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);         
    }
};

/* Approach 2 */

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

/* Approach 3 [ Most Optimised Approach ] */

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        long ans=1;
        int N=m+n-2;
        int r=m-1;
        for(int i=1;i<=r;i++)
        {
            ans=ans*(N-r+i)/i;
        }
        return (int)ans;
    }
};
