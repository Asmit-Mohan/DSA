/* Tabulation Method --> Time :- O(N^2) and Space :- O(N^2) */

class Solution
{   
public:
    bool isSubsetSum(int n, int arr[], int w)
    {
       int dp[n+1][w+1];
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
           for(int j=1;j<w+1;j++)
           {
               if(arr[i-1]<=j)
               {
                   dp[i][j]=max(dp[i-1][j-arr[i-1]],dp[i-1][j]);
               }
               else
               {
                   dp[i][j]=dp[i-1][j];
               }
           }
       }
       return dp[n][w];
    }
};

/* Memorisation Time :- O(N^2) and Space :- O(N^2) + O(N) Auxialiry Stack */

class Solution
{   
public:
   int solve(vector<int>arr, int sum, int n, vector<vector<int>>&dp)
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
          dp[n][sum] = solve(arr, sum-arr[n-1],n-1,dp) || solve(arr,sum,n-1,dp);
        }
        else
        {
          dp[n][sum] = solve(arr,sum,n-1,dp);
        }
        return dp[n][sum];
   }
   bool isSubsetSum(vector<int>arr, int sum)
   {
       vector<vector<int>>dp(arr.size()+1, vector<int>(sum+1,-1));
       return solve(arr,sum,arr.size(),dp);
   }
};
