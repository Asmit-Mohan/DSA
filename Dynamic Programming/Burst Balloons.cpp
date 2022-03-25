class Solution
{
public:
    
    vector<vector<int>> dp;
    
    int solve(vector<int>& nums,int i,int j)
    {
        if(i>=j)
        {
            return 0;
        }
        
        if(dp[i][j] != 0)
        {
            return dp[i][j];
        }
        
        int res = INT_MIN;
        
        for(int k = i; k < j; k++)
        {
           int temp = solve(nums,i,k) + solve(nums,k+1,j) + (nums[i-1]*nums[k]*nums[j]);
           res = max(res,temp);
        }
        
        return dp[i][j] = res;
    }
    
    int maxCoins(vector<int>& nums)
    {
        nums.insert(nums.begin(),1);  
        /*In case of single digit we have to multiply with 1 from both end*/
        nums.push_back(1);
        
        int n = nums.size();
        dp.resize(n, vector<int>(n));
        
        return solve(nums,1,n-1);
    }
};
