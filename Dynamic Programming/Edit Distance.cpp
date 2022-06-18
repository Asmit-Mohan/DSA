/*Memeoristion*/
class Solution
{
public:
    int dp[501][501];
    int solve(string word1,string word2,int n,int m)
    {
        
        if(n == 0)
        {
        	return m ;
	}
        if(m == 0)
        {
        	return n;
        }
        if(m == 0 && n ==0 )
        {
        	return 0;
        }
        if(dp[n][m] != -1)
        {
        	return dp[n][m];
        }
        if(word1[n-1] == word2[m-1])
        {
        	return solve(word1,word2,n-1,m-1);
        }
        
       // insert a character ans recur from n to m-1
       // delete a character and recur from n-1 to m
       // replace a character and recur from n-1 to m-1
    
       int ans = 1 + min(solve(word1,word2,n,m-1) ,min(solve(word1,word2,n-1,m),solve(word1,word2,n-1,m-1)));
       return dp[n][m] = ans;
    }
    int minDistance(string word1, string word2)
    {
        int  n = word1.size();
        int  m = word2.size();
        memset(dp , -1,sizeof(dp));
        return solve(word1,word2,n,m);
    }
};


/*DP*/

class Solution
{
public:
    int minDistance(string s, string t)
    {
    int m=s.length();
    int n=t.length();
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i; 
            }
           
            else if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int temp1=min(dp[i][j-1],dp[i-1][j]);
                temp1=min(temp1,dp[i-1][j-1]);
                dp[i][j]=1+temp1;
            }
    }
    }
    return dp[m][n];
    }
};
