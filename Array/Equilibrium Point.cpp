/*Time Efficient But Not Space Efficient*/
class Solution
{
public:
    int pivotIndex(vector<int>& nums)
    {
       int n=nums.size();
       vector<int>prefix(n,0);
       vector<int>suffix(n,0);
       prefix[0]=nums[0]; 
       for(int i=1;i<nums.size();i++)
       {
           prefix[i]=prefix[i-1]+nums[i];
       }
       suffix[n-1]=nums[n-1];
       for(int i=n-2;i>=0;i--)
       {
           suffix[i]=suffix[i+1]+nums[i];
       }
       for(int i=0;i<nums.size();i++)
       {
           if(prefix[i]==suffix[i])
           {
               return i;
           }
       }
       return -1;
    }
};

/*Time and space effifcient*/
class Solution
{
public:
    int pivotIndex(vector<int>& nums)
    {
        int total = 0;
        int n = nums.size();
        int preSum = 0;
        for(int num : nums)
        {
            total = total+num;
        }
        for(int i=0; i<n; i++)
        {
            if(preSum == total - nums[i])
            {
                return i;
            }
            preSum = preSum+nums[i];
            total = total-nums[i];
        }
        return -1;
    }
};
