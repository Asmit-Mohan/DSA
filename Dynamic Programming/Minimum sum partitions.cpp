/* Time :- O(N*SUM) Space :- O(N*SUM) */

class Solution
{
  public:
	int minDifference(int arr[], int n)
	{ 
        int sum = 0; 
        sort(arr, arr+n);
        for(int i=0; i<n; i++)
        {
            sum = sum + arr[i];
        }
        bool dp[n+1][sum+1];
        memset(dp, false, sizeof(dp));
        for (int i=0; i<n+1; i++)
        {
            for (int j=0; j<sum+1; j++)
            {
                if(j==0)
                {
                    dp[i][j] = true;
                }
                else if(i==0)
                {
                    dp[i][j] = false;
                }
                else if(arr[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        int ans = INT_MAX;
        for (int i=0; i<=(sum/2); i++)
        {
            if (dp[n][i])
            {
                ans = min(ans, (sum-2*i));
            }
        }
        return ans;
    } 
};
