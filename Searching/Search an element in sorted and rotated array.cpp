/* Time :- O(logn) Space :- O(1) */

/* Approach 1 */

class Solution
{
public:
    int bSearch(vector<int>nums,int target,int low,int high)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return -1;
    }
    
    int findMin(vector<int>arr, int n)
    {
        int low=0;
        int high=n-1;
        int mid;
        
        while(low<high)
        {
            mid=low+(high-low)/2;
            if(arr[mid]>arr[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return low;
    }
    
    int search(vector<int>& nums, int target)
    {
        if(nums.size()==1)
        {
            return nums[0]==target?0:-1;
        }
        
        int min=findMin(nums,nums.size());
        if(nums[min]==target)
        {
            return min;
        }
        
        int idx1=bSearch(nums,target,0,min-1);
        int idx2=bSearch(nums,target,min+1,nums.size()-1);
        
        if(idx1==-1&&idx2==-1)
        {
            return -1;
        }
        return idx1==-1?idx2:idx1;
    }
};

/* Approach 2 */

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int low=0;
        int high=nums.size()-1;
        int mid;
        
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
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
        return -1;
    }
};
