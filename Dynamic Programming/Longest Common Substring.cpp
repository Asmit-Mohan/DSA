/* Approach 1 Time :- O(M*N) Space :- O(M*N) + O(N) */

class Solution
{
public:
    int max_length=0;
    
    int solve(int n, int m, string text1, string text2, vector<vector<int>>& dp)
    {
        if(n==0 or m==0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(text1[n-1]==text2[m-1])
        {
            dp[n][m]=1+solve(n-1, m-1, text1, text2, dp);
        }
        else
        {  
           dp[n][m]=0;
        }
        
       solve(n-1, m, text1, text2, dp);
       solve(n, m-1, text1, text2, dp);
       ans=max(ans, dp[n][m]);
       return dp[n][m];
    }
    
    int longestCommonSubstring(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, text1, text2, dp);
    }
};

/* Approach 2 Time :- O(M*N) Space :- O(M*N) */

class Solution
{
    public:
    int longestCommonSubstr (string s1, string s2, int m, int n)
    {
        int dp[m+1][n+1];
        int res=INT_MIN;
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
                    res=max(res,dp[i][j]);
                }
                else
                {
                    dp[i][j]=0;
                }
            }        
        }
        return res==INT_MIN?0:res;
    }
};
