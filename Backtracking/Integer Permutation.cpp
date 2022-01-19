class Solution
{
public:
void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp,vector<bool>&flag)
{
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(flag[i] == false)
            {
                temp.push_back(nums[i]);
                flag[i] = true;
                solve(ans, nums, temp, flag);
                flag[i] = false;
                temp.pop_back();
            }
        }
}
   vector<vector<int>> permute(vector<int>& nums)
   {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> flag(nums.size(), false);
        solve(ans, nums, temp, flag);
        return ans;
    }
};
