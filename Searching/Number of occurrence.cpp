/* Approach 1 --> Using Hashmap to count the frequency --> Time :- O(N) Space :- O(N) */

/* Approach 2 --> Using Binary Search Time :- O(logn) Space :- O(1) */

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
    
    vector<int> numOfOccurrences(vector<int>& nums, int target)
    {
        int n = nums.size();
        int first = firstOccurance(nums,n,target);
        int last =  lastOccurance(nums,n,target);    
        return last-first-1;
    }
};
