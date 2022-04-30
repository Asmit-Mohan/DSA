/* For GeeksForGeeks */

int binary(vector<int> arr,int l,int r,int k)
{
    int mid=l+(r-l)/2;
    while(l<r)
    {
        if(arr[mid]==k)
        {
            return mid;
        }
        else if(arr[mid]>k)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return 0;
}
int solve(vector<int> a, int n)
{
    int l=0;
    int r=n-1;
    while(l<r)
    {
        int mid=l+((r-l)/2);
        if(a[mid]>a[r])
        {
           l=mid+1;  //It means r is near rotated sorted point
        }
        else
        {
           r=mid; //r is greater then all element next to r will be grater then move to mid
        }
    }
    return l;
}

int Search(vector<int> vec, int K)
{
     int idx=solve(vec,vec.size());
     if(K==vec[idx])
     {
         return idx;
     }
     
     if(K==vec[vec.size()-1])
     {
         return vec.size()-1;
     }
     
     int ans1=binary(vec,idx,vec.size()-1,K);
     int ans2=binary(vec,0,idx-1,K);
     
     if(ans1==0)
     {
         return ans2;
     }
     else if(ans2==0)
     {
         return ans1;
     }
     else
     {
         return -1;
     }
}

/* For Leetcode Approach 1 */

class Solution
{
public:
 int findMinEle(vector<int>& nums)
 {
        int n=nums.size();
        int start=0;
        int end=n-1;
        if(nums[start]<nums[end])
        {
            return 0;
        }
        while(start<=end)
        {
            int mid=start + (end-start)/2;
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next])
            {
                return mid;
            }
            else if(nums[mid]<nums[end])
            {
                end=mid-1;
            }
            else if(nums[mid]>nums[end])
            {
                start=mid+1;
            }
        }
        return 0;
    }
    
    int binarySearch(vector<int>& arr, int target,int i,int j)
    {
        int start=i;
        int end=j;
        while(start<=end)
        {
            int mid=start + (end-start)/2;
            if(arr[mid]==target)
            {
                return mid;
            }
            else if(arr[mid]>target)
            {
                end=mid-1;
            }
            else if(arr[mid]<target)
            {
                start=mid+1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target)
    {
        int n=nums.size();
        int minEle=findMinEle(nums);
        
        int a=binarySearch(nums,target,0,minEle-1);
        int b=binarySearch(nums,target,minEle,n-1);
        
        if(a==-1 && b==-1)
        {
            return -1;
        }
        else if(a==-1)
        {
            return b;
        }
        else
        {
            return a;
        }
    }
};

/* For Leetcode Approach 2 */

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
