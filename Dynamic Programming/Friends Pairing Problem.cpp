class Solution
{
    public:
    long long int solve(int n,vector<int>&dp)
    {
        if(n==1)
        {
            return 1;
        }
        if(n==2)
        {
            return 2;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n] = solve(n-1,dp) + (n-1)*solve(n-2,dp);  
    }
    
    int countFriendsPairings(int n) 
    { 
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};

/* Logic:-  If single then solve(n-1) else if pairing then nth people can be paired with remaining (n-1) people in (n-1)*solve(n-2) ways
  here solve(n-2) shows no. of ways remaining n-2 will pair */
