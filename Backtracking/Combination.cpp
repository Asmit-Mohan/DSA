/* Time :- O(k*Ncr) Space :- O(N) */

class Solution
{
public:
    void solve(vector<int>&nums, int n, int pos, vector<int>&temp, vector<vector<int>>&result)
    {
        if (temp.size() == n)
        {
            result.push_back(temp);
            return;
        }

        for (int i = pos; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            solve(nums, n, i+1, temp, result); 
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k)
    {     
        vector<int> nums;
        vector<int> temp;
        vector<vector<int>>ans;
        
        for (int i = 1; i <=n; i++)
        {
            nums.push_back(i);
        }
        solve(nums, k, 0, temp, ans);
        return ans;
    }
};
