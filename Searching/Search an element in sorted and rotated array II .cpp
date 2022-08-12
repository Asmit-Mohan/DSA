/* Time :- O(Logn) Space :- O(1) */

class Solution
{
public:
    bool search(vector<int>& nums, int target)
    {
        int low=0;
        int high=nums.size()-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target)
            {
                return true;
            }
            
            if(nums[low]==nums[mid]&&nums[high]==nums[mid])  /* This Line is checking for duplicacy */
            {
                low++;
                high--;
            }
            else if(nums[mid]>=nums[low])
            {
                if(nums[mid]>=target && target>=nums[low])
                {
                    high=mid-1;
                }
                else 
                {
                    low=mid+1;
                }
            }
            else 
            {
                if(nums[high]>=target && target>=nums[mid])
                {
                    low=mid+1;
                }
                else 
                {
                    high=mid-1;
                }
            }
        }
        return false;
    }
};
