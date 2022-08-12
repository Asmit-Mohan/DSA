/* Approach 1 Using Hashmap Time :- O(N) Space :- O(N) */

/* Approach 2 Using Voting Algorithms Time :- O(N) Space :- O(1) */

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
          int count=0;
          int res;
          for(int i=0;i<nums.size();i++)
          {
              if(count==0)
              {
                  res=nums[i];
              }
              if(nums[i]==res)
              {
                  count++;
              }
              else
              {
                  count--;
              }
          }
        return res;
    }
};
