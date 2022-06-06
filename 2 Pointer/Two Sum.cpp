class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
          vector<int>ans;
          if(nums.size()==2)
          {
               if(nums[0]+nums[1]==target)
               {
                   ans.push_back(0);
                   ans.push_back(1);
               }
               return ans;
          }
        
          vector<pair<int,int>>v;
          for(int i=0;i<nums.size();i++)
          {
              v.push_back({nums[i],i});
          }
        
          sort(v.begin(),v.end());
          int l=0;
          int r=nums.size()-1;
          
          while(l<r)
          {
              int sum=v[l].first+v[r].first;
              
              if(sum==target)
              {
                  ans.clear();
                  ans.push_back(v[l].second);
                  ans.push_back(v[r].second);
                  break;
              }
              else if(sum>target)
              {
                  r--;
              }
              else
              {
                  l++;
              }
          }
          return ans;
    }
};
