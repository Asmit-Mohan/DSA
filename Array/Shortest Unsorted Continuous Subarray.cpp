class Solution
{
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int n=nums.size();
        int mn=INT_MAX;
        int mx=INT_MIN;
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                mn=min(mn,nums[i+1]);
            }
        }
        for(int j=n-1;j>0;j--)
        {
            if(nums[j]<nums[j-1])
            {
                mx=max(mx,nums[j-1]);
            }
           
        }
        int l,r;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>mn)
            {
                l=i;
                break;
            }
        }
        for(int j=n-1;j>=0;j--)
        {
            if(mx>nums[j])
            {
                r=j;
                break;
            }
        }
        return r-l>0?r-l+1:0;
    }
};
