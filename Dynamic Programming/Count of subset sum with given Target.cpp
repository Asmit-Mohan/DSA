/* Tabulation Approach Time :- O(N^2) Space:- O(N^2) */

class Solution
{
       public:
       int perfectSum(int arr[], int n, int w)
       {
       int dp[n+1][w+1];
       int mod = pow(10,9)+7;
       
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<w+1;j++)
            {
                if(i==0)
                {
                   dp[i][j]=0;   
                }
                if(j==0)
                {
                    dp[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<w+1;j++)
            {
                if(arr[i-1]<=j)
                {
                   dp[i][j]=(dp[i-1][j-arr[i-1]]%mod)+(dp[i-1][j]%mod);   
                }
                else
                {
                    dp[i][j]=(dp[i-1][j]%mod);
                }
            }
        }
        return dp[n][w]%mod;
     }
};

/* Memorisation Approach Time :- O(N^2) Space:- O(N^2) + O(N) */

class Solution
{
	 public:
	 int mod = pow(10,9)+7;
	 int solve(int arr[], int sum, int n, vector<vector<int>>&dp)
        { 
               if(sum==0)
               {
                  return 1;
               }      
               if(n==0)
               {
                  return 0;
               }
               if(dp[n][sum]!=-1)
               {
                  return dp[n][sum];
               }
               if(arr[n-1]<=sum)
               {  
                 dp[n][sum] = (solve(arr, sum-arr[n-1],n-1,dp) + solve(arr,sum,n-1,dp))%mod;
               }
               else
               {
                 dp[n][sum] = solve(arr,sum,n-1,dp)%mod;
               }
               return dp[n][sum];
       }
   
	int perfectSum(int arr[], int n, int sum)
	{
              vector<vector<int>>dp(n+1, vector<int>(sum+1,-1));
              sort(arr,arr+n,greater<int>());
              return solve(arr,sum,n,dp);
	}
};
