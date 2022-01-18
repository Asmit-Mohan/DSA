class Solution
{
public:
void subsets1(vector<int>&nums,vector<vector<int>> &v , int i , vector<int>ans )
    {
      if(i==nums.size())
      {
        v.push_back(ans);
        return;
      }
      subsets1(nums , v , i+1 , ans);
      ans.push_back(nums[i]);
      subsets1(nums , v , i+1 , ans);
      }
      vector<vector<int>> subsets(vector<int>& nums)
      {
        vector<vector<int>> v;
        vector<int> ans;
        int n = nums.size();
        subsets1(nums , v , 0 , ans);
        return v;
    }
};
