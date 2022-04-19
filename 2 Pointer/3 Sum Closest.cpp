class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
         int n=nums.size();
         int ans=nums[0]+nums[1]+nums[2];
        
         if(nums.size()==3)
         {
             return nums[0]+nums[1]+nums[2];
         }
         sort(nums.begin(),nums.end());
         for(int i=0;i<n-1;i++)
         {
             int l=i+1;
             int r=n-1;
             while(l<r)
             {
                  int sum=nums[i]+nums[l]+nums[r];
                  if(abs(target-sum)<abs(target-ans))
                  {
                      ans=sum;
                  }
                  if(abs(target-sum)==abs(target-ans))
                  {
                      ans=max(ans,sum);
                  }
                  if(target>sum)
                  {
                       l++;
                  }
                  else
                  {
                      r--;
                  }
             }
         }
        return ans;
    }
};
