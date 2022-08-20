class Solution
{
    public:
    bool solve(vector<int>&nums,vector<int>&visited,int idx,int sum,int target,int k)
    {
        if(k==0)
        {
            return true;
        }
        if(sum>target)
        {
            return false;
        }
        if(sum==target)
        {
            return solve(nums,visited,0,0,target,k-1);
        }
        
        for(int i=idx;i<nums.size();i++)
        {
            if(visited[i]==0)
            {
                if(sum+nums[i]<=target)
                {
                    visited[i]=1;
                    if(solve(nums,visited,i+1,sum+nums[i],target,k))
                    {
                        return true;
                    }
                    visited[i]=0;
                }
                if(sum ==0 || sum + nums[i]>target)
                {
                    return false;
                }
                while(i+1<nums.size() && nums[i]==nums[i+1])
                {
                    i++;
                }
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum=0;
        int n=nums.size();
        vector<int>visited;
        
        for(auto it : nums)
        {
            sum= sum + it;
        }
        if(nums.size()<k || sum%k)
        {
            return false;
        }
        
        visited.resize(n,0);
        int target=sum/k;
        sort(nums.begin(),nums.end());
        return solve(nums,visited,0,0,target,k);
    }
};
