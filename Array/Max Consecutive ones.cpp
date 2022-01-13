class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
       if(nums.size()==1&&nums[0]==1)
       {
           return 1;
       }
       int count=0;
       int ans=INT_MIN;
       for(int i=0;i<nums.size();i++)
       {
          if(nums[i]==1)
          {
              count++;
              ans=max(ans,count);
          }
          else
          {
              ans=max(ans,count);
              count=0;
          }
       }
       return ans;
    }
};