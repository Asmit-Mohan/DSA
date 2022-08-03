/* Approach 1 Time :- O(N*amount) Space :- O(N*amount) + O(N) */

class Solution
{
public:
    int dp[15][10005];
    int solve(vector<int>& coins,int n, int amount)
    {
        if(amount == 0)
        {
            return 0;
        }
        if(n == 0)
        {
            return INT_MAX-1;
        }
        if(dp[n][amount] != -1)
        {
            return dp[n][amount];
        }
        if(coins[n-1] <= amount)
        {
            return dp[n][amount]=min(1+solve(coins,n,amount-coins[n-1]),solve(coins,n-1,amount));
        }
        else
        {
            return dp[n][amount]=solve(coins,n-1,amount);
        }    
    }
    
    int coinChange(vector<int>& coins, int amount)
    {    
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(coins, n, amount);
        return ans==INT_MAX-1?-1:ans;
    }
};

/* Approach 2 Time :- O(N*amount) Space :- O(N*amount) */

class Solution
{
public:
  int minCoins(int coins[], int M, int V) 
  {
    long long t[M+1][V+1];
    for( int i = 0 ; i < M+1; i++ )
    {
        t[i][0]=0;
    }
    for( int j = 0 ; j < V+1 ; j++ )
    {
        t[0][j]=INT_MAX;
    }
    for( int i = 1 ; i <= M ; i++)
    {
          for( int j = 1 ; j <= V ; j++)
          {
              if( coins[i-1]<= j )
              {
                  t[i][j]=min(1+t[i][j-coins[i-1]], t[i-1][j] );
              }
              else
              {
                  t[i][j]=t[i-1][j];
              }
          }
    }
    if( t[M][V] == INT_MAX)
    {
        return -1 ;
    }
    return t[M][V];
  }
};
