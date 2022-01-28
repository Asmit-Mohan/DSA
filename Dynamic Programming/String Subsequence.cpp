/*Approach 1*/

class Solution
{
    public:
    int dp[505][505];
    int solve(string s1,string s2,int m,int n)
    {
        if(m==0&&n==0)
        {
            return dp[m][n]=1;
        }
        else if(m==0)
        {
            return dp[m][n]=0;
        }
        else if(n==0)
        {
            return dp[m][n]=1;
        }
        else if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        else if(s1[m-1]==s2[n-1])
        {
            return dp[m][n]=solve(s1,s2,m-1,n-1)+solve(s1,s2,m-1,n);
        }
        else
        {
            return dp[m][n]=solve(s1,s2,m-1,n);
        }
    }
    
    int countWays(string S1, string S2)
    {
        int m=S1.length();
        int n=S2.length();
        memset(dp,-1,sizeof(dp));
        solve(S1,S2,m,n);
        return dp[m][n];
    }
};

/*Approach 2*/

class Solution{
public:
    int countWays(string S1, string S2)
    {
    string a,b;
    a=S1;
    b=S2;
    int m = a.length();
    int n = b.length();
    int t[m + 1][n + 1];
    for (int j = 0; j <= n; ++j)
    {
        t[0][j] = 0;
    }
    for (int i = 0; i <= m; ++i)
    {   
        t[i][0] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                t[i][j] = t[i - 1][j - 1] +t[i - 1][j];
            }
                 
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[m][n];
    }
};
