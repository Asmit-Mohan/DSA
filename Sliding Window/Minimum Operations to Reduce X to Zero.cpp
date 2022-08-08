/* Time :- O(N) Space :- O(1) */

class Solution
{
public:
    int minOperations(vector<int>& nums, int x)
    {
        int i=0;
        int j=0;
        int sum=0;
        
        for(int k=0;k<nums.size();k++)
        {
            sum=sum+nums[k];
        }
        
        if(sum==x)
        {
            return nums.size();
        }
        
        if(sum<x)
        {
            return -1;
        }
        
        sum=sum-x;
        
        int temp=0;
        int ans=INT_MIN;
        
        while(j<nums.size())
        {
            temp=temp+nums[j];
            if(temp==sum)
            {
                int window=j-i+1;
                ans=max(ans,window);
            }
            else if(temp>sum)
            {
                while(temp>sum)
                {
                    temp=temp-nums[i];
                    i++;
                }
                if(temp==sum)
                {
                    int window=j-i+1;
                    ans=max(ans,window);
                }
            }
            j++;
        }
        return ans==INT_MIN?-1:nums.size()-ans;
    }
};
