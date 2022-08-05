class Solution
{
public:
    
    int dp[1001];
    Solution()
    {
        memset(dp,-1,sizeof(dp));
        dp[0]=1;
    }
    
    int combinationSum4(vector<int>& nums, int target)
    {
        if(nums.empty())
        {
            return 0;
        }
        if(target<0)
        {
            return 0;
        }
        
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        if(target==0)
        {
            return 1;
        }
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            ans = ans + combinationSum4(nums,target-nums[i]);
        }
        return dp[target]=ans;   
    }
};
