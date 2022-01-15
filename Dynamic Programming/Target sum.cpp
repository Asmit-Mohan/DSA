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
