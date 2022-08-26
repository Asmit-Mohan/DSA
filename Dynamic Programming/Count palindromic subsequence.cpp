/* Problem Link :- https://www.codingninjas.com/codestudio/problems/count-palindromic-subsequences_1062696 */

/* Time :- O(N*N) Space :- O(N*N) */

   long long mod = 1000000007;
   int dp[1001][1001];
   
   long long int solve(int i,int j,string &s)
    {
        if(i>j)
        {
            return dp[i][j]=0;
        }
        if(i==j)
        {
            return dp[i][j]=1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            return dp[i][j] = solve(i+1,j,s)%mod + solve(i,j-1,s)%mod + 1;
        }
        else
        {
            return dp[i][j] = solve(i+1,j,s)%mod + solve(i,j-1,s)%mod - solve(i+1,j-1,s)%mod;
        }
    }

int countPalindromicSubseq(string &str)
{
	  int n =str.size();
    memset(dp,-1,sizeof(dp));
    return solve(0,n-1,str)%mod;
}
