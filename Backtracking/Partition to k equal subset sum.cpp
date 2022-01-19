class Solution
{
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
        }
        if(k>sum)
        {
            return false;
        }
        if (sum % k != 0)
        {
            return false;
        }
        vector<bool> visited(nums.size(), false);
        return helper(nums, k, sum / k, 0, 0, visited);
    }
    
    bool helper(vector<int>& nums, int k, int target, int start, int curSum, vector<bool>& visited)     {
        
        if (k == 1)
        {
            return true;
        }
        if (curSum > target)
        {
            return false;
        }
        
        if (curSum == target)
        {
            return helper(nums, k - 1, target, 0, 0, visited);  
        }
        
        for (int i = start; i < nums.size(); i++)
        {
            if (curSum + nums[i] > target)
            {
                continue;
            }
            if (visited[i])
            {
                continue;
            }
            visited[i] = true;
            if (helper(nums, k, target, i + 1, curSum + nums[i], visited))
            {
                return true;
            }
            visited[i] = false;
        }
        return false;
    }
};
