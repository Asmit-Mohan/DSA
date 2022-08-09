/* Time :- O(N*N) Space :- O(N) */

class Solution
{
public:
    int triangleNumber(vector<int>& nums)
    {
        int ans=0;
        
        if(nums.size()<3)
        {
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        if(nums.size()==3)
        {
            if(nums[0]+nums[1]>nums[2])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
        int n=nums.size();
        
        for(int i=2;i<n;i++)
        {
            int l=0;
            int r=i-1;
            while(l<r)
            {
                if(nums[l]+nums[r]>nums[i])
                {
                    ans=ans+(r-l);
                    r--;
                }
                else
                {
                    l++;   
                }
            }
        }
        return ans;
    }
};
