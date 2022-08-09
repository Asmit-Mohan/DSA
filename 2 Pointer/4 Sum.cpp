class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        
     vector<vector<int>>ans;
     int n = nums.size();
     sort(nums.begin() , nums.end());
     
     for(int i = 0 ; i <n;i++)
     {
         long long int temp1 = target - nums[i];
         
         for(int j = i+1 ; j<n;j++)
         {
             int l = j+1;
             int r = n-1;
             long long int temp2 = temp1 - nums[j];
             
             while(l<r)
             {
                 long long int sum = nums[l] + nums[r];
                 
                 if(sum == temp2)
                 {
                     ans.push_back({nums[i] , nums[j] , nums[l] , nums[r]});
                     
                 }
                 if(temp2 > sum)
                 {
                     
                     while(l+1 < n and nums[l] == nums[l+1])
                     {
                         l++;
                     }
                     l++;
                 }
                 else
                 {
                     while(r>1 and nums[r] == nums[r-1])
                     {
                         r--;
                     }
                     r--;
                 }
             }
             while(j+1 < n and nums[j] == nums[j+1])
             {
                 j++;
             }
         }
         while(i+1 < n and nums[i] == nums[i+1])
         {
             i++;
         }
      }
      return ans;
    }
};
