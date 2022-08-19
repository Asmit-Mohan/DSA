/* Time :- O(N!*N) Space :- O(N) [Temp Vector] + O(N) [Visited array] + O(N) [ASS] */

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
                    /*That means if it equal to previous one and previous one is used then current one is duplicate of it so skip it*/
                    
                    if(i>0&&nums[i]==nums[i-1]&&flag[i-1]==true) 
                    {
                        continue;
                    }
                    if(flag[i] == false)
                    {
                        flag[i] = true;
                        temp.push_back(nums[i]);
                        solve(ans, nums, temp, flag);
                        flag[i] = false;
                        temp.pop_back();
                    }
                }
        }
        vector<vector<int>> permuteUnique(vector<int>& nums)
        {
                vector<vector<int>> ans;
                vector<int> temp;
                vector<bool> flag(nums.size(), false);
                sort(nums.begin(),nums.end());
                solve(ans, nums, temp, flag);
                return ans; 
        }
};
