/* Approach 1 Time :- O[k*(2^T)] Space :- O(k*x) where T is target and k is average length of array whose sum is target */

class Solution
{
    public: 
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&temp)
    {
        if(ind == arr.size())
        {
            if(target == 0)
            {
                ans.push_back(temp); 
            }
            return; 
        } 
        if(arr[ind] <= target)
        {
            temp.push_back(arr[ind]); 
            solve(ind, target - arr[ind], arr, ans, temp); 
            temp.pop_back(); 
        }
        solve(ind+1, target, arr, ans, temp); 
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans; 
        vector<int> temp; 
        solve(0, target, candidates, ans, temp); 
        return ans; 
    }
};

/* Approach 2 */

class Solution
{
public:
    void solve(vector<int>nums, int pos,int target,vector<int>temp, vector<vector<int>>&result)
    {
        if(target<0)
        {
            return;
        }
        if (target==0)
        {
            result.push_back(temp);
            return;
        }

        for (int i = pos; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            solve(nums, i,target-nums[i],temp,result);  /*here i not i+1 because here given any number can be taken unlimited number of times*/
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int k)
    {
        vector<int> temp;
        vector<vector<int>>ans;
        solve(nums,0,k,temp, ans);
        return ans;
    }
};
