/* Approach 1 --> Recursion Time :- O(2^n) Space :- O(1) */

Long Long  numberOfPaths(int m, int n)
{
    if(m==1||n==1)
    {
        return 1;
    }
    return numberOfPaths(m-1,n)+numberOfPaths(m,n-1);
}

/* Efficient Approach 2 --> DP Time :- O(m*n) Space :- O(m*n) */

int dp[11][11]={0};

long long  numberOfPaths(int m, int n)
{
    if(m==1||n==1)
    {
        return dp[m][n] = 1;
    }
    else if(dp[m][n]!=0)
    {
        return dp[m][n];
    }
    else
    {
        return dp[m][n] = numberOfPaths(m,n-1) + numberOfPaths(m-1,n);
    }
}
