/* Time :- O[k*(2^n)] Space :- O(k*x) */

class Solution
{
public:
    void solve(vector<int>nums, int pos, int k, int target, vector<int>& temp, vector<vector<int>>& ans)
    {
        if (temp.size() == k && target == 0)
        {
            ans.push_back(temp);
            return;
        }       
        for (int i = pos; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            solve(nums, i+1, k, target-nums[i], temp, ans);
            temp.pop_back();
        }
    }    
    vector<vector<int>> combinationSum3(int k, int target)
    {
        vector<int>nums;
        vector<vector<int>>ans;
        long long sum=0;
        for (int i = 1; i <= 9; i++)
        {
            nums.push_back(i);
            sum=sum+i;
        }
        if(target>sum)
        {
            return ans;  /*In case max sum is less than given target*/
        }
        vector<int>temp;
        solve(nums, 0, k, target, temp, ans);
        return ans;
    }
};
