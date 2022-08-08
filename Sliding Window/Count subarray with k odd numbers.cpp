/* Time :- O(N) Space :- O(1) */


class Solution
{
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        int i = 0;
        int j = 0;
        int count = 0;
        int ans = 0;
        int odd = 0;
        
        while(j<nums.size())
        {
            if(nums[j]%2==1)
            {
                odd++;
            }
            
            while(odd>k)
            {
                if(nums[i]%2)
                {
                    odd--;
                    count = 0;
                }
                i++;
            }
            
            while(odd == k && nums[i]%2 == 0)
            {
                i++;
                count++;
            }
            
            if(odd == k)
            {
                ans=ans+count+1;
            }
            
            j++;
        }
        return ans;
    }
};
