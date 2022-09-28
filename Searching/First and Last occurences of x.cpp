/* Time :- O(logn) Space :- O(1) */

class Solution
{
public:
    int firstOccurance(vector<int>& arr, int n, int key)
    {
        int low=0;
        int high=n-1;
        int ans=-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==key)
            {
                ans = mid;
                high = mid-1;
            }
            else if(key>arr[mid])
            {
                low = mid+1;
            }
            else if(key<arr[mid])
            {
                high = mid-1;
            }
        }
        return ans;
    }
    
    int lastOccurance(vector<int>& arr, int n, int key)
    {
        int low=0;
        int high=n-1;
        int ans=-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==key)
            {
                ans = mid;
                low = mid+1;
            }
            else if(key>arr[mid])
            {
                low = mid+1;
            }
            else if(key<arr[mid])
            {
                high = mid-1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();
        int first = firstOccurance(nums,n,target);
        int last =  lastOccurance(nums,n,target);    
        return {first, last};
    }
};
