/* Naive Approach */

class Solution
{
public:
    bool isSmall(int idx,int n,int num,vector<int>arr)
    {
        for(int i=idx;i<n;i++)
        {
            if(arr[i]<num)
            {
                return 1;
            }
        }
        return 0;
    }
    
    bool isGreat(int idx,int n,int num,vector<int>arr)
    {
        for(int i=idx;i<n;i++)
        {
            if(arr[i]>num)
            {
                return 1;
            }
        }
        return 0;
    }
    
    
    bool increasingTriplet(vector<int>& arr)
    {
       int n=arr.size();
        
       if(n<3)
        {
            return 0;
        }
        
        if(n==3)
        {
            if(arr[0]<arr[1]&&arr[1]<arr[2])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
        for(int i=1;i<n-1;i++)
        {
            bool val1=isSmall(0,i,arr[i],arr);
            bool val2=isGreat(i+1,n,arr[i],arr);
            
            if(val1&&val2)
            {
               return 1;
            }
        }
        return 0;
    }
};

/* Efficient Approach */

class Solution
{
public:
    bool increasingTriplet(vector<int>& nums)
    {     
        int c1 = INT_MAX;
        int c2 = INT_MAX;    
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= c1)
            {
                c1 = nums[i];
            }
            else if (nums[i] <= c2)
            {
                c2 = nums[i];
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
};
