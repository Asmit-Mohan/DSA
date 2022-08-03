/* Approach 1 Time :- O(M*N) Space :- O(M*N) + o(N) */

class Solution
{
public:
    
    int dp[1001][1001];
    int solve(string s1,string s2,int m,int n)
    {
        if(m==0||n==0)
        {
            return dp[m][n]=0;
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        if(s1[m-1]==s2[n-1])
        {
            return dp[m][n]=1+solve(s1,s2,m-1,n-1);
        }
        else
        {
            return dp[m][n]=max(solve(s1,s2,m-1,n),solve(s1,s2,m,n-1));
        }
        return dp[m][n];
    }
    
    int longestCommonSubsequence(string s1, string s2)
    {
         int m=s1.size();
         int n=s2.size();
         memset(dp,-1,sizeof(dp));
         return solve(s1,s2,m,n);
    }
};

/* Approach 2 Time :- O(M*N) Space :- O(M*N) + o(N) */

class Solution
{
    public:
    int lcs(int m, int n, string s1, string s2)
    {
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                 if(i==0)
                 {
                     dp[i][j]=0;
                 }
                 if(j==0)
                 {
                     dp[i][j]=0;           
                 }
            }        
        }
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }        
        }
        return dp[m][n];
    }
};
