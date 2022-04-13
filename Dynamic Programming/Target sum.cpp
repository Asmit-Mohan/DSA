/* Approach 1 */

class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        if(nums.size()==1&&nums[0]==abs(S))
        {
            return 1;
        }
        
        if(nums.size()==1&&nums[0]!=S)
        {
            return 0;
        }
        
        int count = 0;
        int sum=0;
        int n = nums.size();
        
        for (int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            if(nums[i]==0)
            {
                count++;
            }
        }
        
        if(S>sum)
        {
            return 0;
        }
        
        if((S+sum)%2!=0)
        {
            return 0;
        }
        
        int s= (S+sum)/2;
        int t[n+1][s+1];
        
        for(int i=0;i<n+1;i++)
        {
            t[i][0]=1;
        }
        
        for(int i=1;i<s+1;i++)
        {
            t[0][i]=0;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<s+1;j++)
            {
                 if(nums[i-1]==0)
                 {
                    t[i][j] = t[i-1][j];
                 }
                 else if(j < nums[i-1])
                 {
                    t[i][j] = t[i-1][j];
                 }
                 else
                 {
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
                 }
            }
        }
        
        return pow(2,count)*t[n][s];
     }
};

/* Approach 2 */
class Solution
{
public:
    int solve(vector<int> &arr, int n, int sum, vector<vector<int>> &dp)
    {
        int zeros = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                zeros++;
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (j<arr[i - 1] || arr[i - 1] == 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else if (arr[i - 1] <= j)
                {
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]);
                }
            }
        }
        return long(pow(2, zeros) * dp[n][sum]);
    }
    
    int findTargetSumWays(vector<int> &nums, int diff)
    {
        int sum = 0;
        int n = nums.size();
        for (auto it : nums)  /*Faster Loop*/
        {
            sum = sum + it;
        }
        int temp = (sum + diff) / 2;
        if (diff > sum || (sum + long(diff)) % 2 != 0 || temp < 0)
        {
            return 0;
        }
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        for (int j = 0; j < temp + 1; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 1;
        }
        return solve(nums, n, temp, dp);
    }
};
