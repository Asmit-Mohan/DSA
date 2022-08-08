/* Approach 1 --> Brute Force Efficient O(N) :- Time O(1) :- Space */

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int z=0;
        int o=0;
        int t=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                z++;
            }
            else if(nums[i]==1)
            {
                o++;
            }
            else
            {
                t++;
            }
        }
        nums.clear();
        while(z--)
        {
            nums.push_back(0);
        }
        while(o--)
        {
            nums.push_back(1);
        }
        while(t--)
        {
            nums.push_back(2);
        }  
    }
};


/* Approach :- 2 pointer O(N) :- Time O(1) :- Space */

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int i = 0;
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
           if(nums[l]==1)
           {
               l++;
               continue;
           }
           if(nums[l]==0)
           {
               swap(nums[i],nums[l]);
               l++;
               i++;
               continue;
           }
           if(nums[r]==2)
           {
               r--;
               continue;
           }
           swap(nums[l],nums[r]);
        }
    }
};
