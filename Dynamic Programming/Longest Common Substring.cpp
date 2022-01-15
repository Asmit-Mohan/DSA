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
