/* Time :- O[k*(2^n)] Space :- O(k*x) where k is average length of array whose sum is target */

class Solution
{
    public: 
    void solve(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }        
        for(int i = ind;i<arr.size();i++)
        {
            if(i>ind && arr[i]==arr[i-1])
            {
                continue; 
            }
            if(arr[i]>target)
            {
                break; 
            }
            temp.push_back(arr[i]);
            solve(i+1, target - arr[i], arr, ans, temp); 
            temp.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans; 
        vector<int>temp; 
        solve(0, target, candidates, ans, temp); 
        return ans; 
    }
};
