/* Approach 1 Time :- O(N*N) Space:- O(N*N) + O(N) */

class Solution
{
  public:
    long long int solve(int arr[],int n,int w,vector<vector<long long>>&dp)
    {
        if(n==0)
        {
            return dp[n][w]=0;
        }
        if(w==0)
        {
            return dp[n][w]=1;
        }
        if(dp[n][w]!=-1)
        {
            return dp[n][w];
        }
        if(arr[n-1]<=w)
        {
            return dp[n][w]=solve(arr,n,w-arr[n-1],dp)+solve(arr,n-1,w,dp);
        }
        return dp[n][w]=solve(arr,n-1,w,dp);
    }
    
    long long int count(int wt[], int n, int w)
    {
        vector<vector<long long >>dp(n+1,vector<long long>(w+1,-1));
        return solve(wt,n,w,dp);
    }
};

/* Approach 2 Time :- O(N*N) Space:- O(N*N) */
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
        long long int t[m+1][n+1];
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0)
                {
                    t[i][j]=0;
                }
                else if(j==0)
                {
                    t[i][j]=1;
                }
                else if(S[i-1]<=j)
                {
                    t[i][j]=t[i][j-S[i-1]]+t[i-1][j];
                }
                else
                {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[m][n];
    }
};
