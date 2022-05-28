/* Approach 1 Recursion + Memorisation */ 

class Solution
{
public:
    bool isAllStar(string s,int i)
    {
        for(int j=1;j<i+1;j++)
        {
            if(s[j-1] != '*')
            {
               return false;
            }
        }
        return true;
    }
    
    bool solve(int i, int j, string &s1, string &s2,vector<vector<int>> &dp)
    {
        if(i==0 && j==0)
        {
            return true;
        }
        if(i==0 && j>0)
        {
            return false;
        }
        if(j==0 && i>0)
        {
            return isAllStar(s1,i);   
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(s1[i-1] == s2[j-1] || s1[i-1]=='?')
        {
            return dp[i][j] = solve(i-1,j-1,s1,s2,dp);
        }
        if(s1[i-1] == '*')
        {
            return dp[i][j] = solve(i-1,j,s1,s2,dp) || solve(i,j-1,s1,s2,dp);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s2, string s1)
    {
        int n = s1.size();
        int m = s2.size();    
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        return solve(n,m,s1,s2,dp);
    }
};

/* Approach 2 Tabulation DP */

class Solution
{
public:
    bool isMatch(string s1, string s2)
    {
        
    int m = s1.size();
    int n = s2.size();
    vector<vector<bool>> dp(n+1, vector<bool> (m+1,0));
    dp[0][0] = 1;
        
    for(int j=1;j<m+1;j++)
    {
        dp[0][j] = false;
    }
    for(int i=1;i<n+1;i++)
    {
        int flag = true;
        for(int k=1;k<i+1;k++)
        {
            if(s2[k-1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(s2[i-1] == s1[j-1] || s2[i-1]=='?')
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(s2[i-1] == '*')
            {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];    
    }
};

/* Approach 3 Space Optimisation --> The Most Optimised Approach */

class Solution
{
public:
bool isMatch(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    vector<bool>prev(m+1,0);
    vector<bool>curr(m+1,0);
    prev[0] = 1;
        
    for(int j=1;j<m+1;j++)
    {
        prev[j] = false;
    }
        
    for(int i=1;i<n+1;i++)
    {
        int flag = true;
        for(int k=1;k<i+1;k++)
        {
            if(s2[k-1] != '*')
            {
                flag = false;
                break;
            }
        }
        curr[0] = flag;

        for(int j=1;j<m+1;j++)
        {
            if(s2[i-1] == s1[j-1] || s2[i-1]=='?')
            {
                curr[j] = prev[j-1];
            }
            else if(s2[i-1] == '*')
            {
                curr[j] = prev[j] || curr[j-1];
            }
            else
            {
                curr[j] = false;
            }
        }
        prev = curr;
    }
    return prev[m];
}
};
