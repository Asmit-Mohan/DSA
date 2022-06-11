class Solution
{
public:
    int minOperations(vector<int>& nums, int x)
    {
       int target=0;
       int i=0;
       int j=0;
       int sum=0;
        
       for(auto x : nums)
       {
           target+=x;
       }
        
        target=target-x;
        int ans=INT_MAX;
        
        while(j<nums.size())
        {
            sum=sum+nums[j];
            while(sum>target&&j>=i)
            {
                sum=sum-nums[i];
                i++;
            }
            if(sum==target)
            {
                int temp=nums.size()-(j-i+1);
                ans=min(ans,temp);
            }
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};
