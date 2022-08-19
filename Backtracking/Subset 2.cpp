/* Approach 1 :- Recursion */

class Solution
{
public:
    void subsets1(vector<int>&nums,set<vector<int>> &s , int i , vector<int>ans )
    {
        if(i==nums.size())
        {
            s.insert(ans);
            return;
        }
        subsets1(nums , s , i+1 , ans);
        ans.push_back(nums[i]);
        subsets1(nums , s , i+1 , ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        set<vector<int>>s;
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        subsets1(nums , s , 0 , ans);
        
        vector<vector<int>> v;
        for(auto x :s)
        {
            v.push_back(x);
        }
        return v; 
    }
};

/* Approach 2 :- Backtracking */

class Solution
{
public:
    void solve(vector<int>&nums,int n,int pos,vector<int>&cur, vector<vector<int>>&result)
    {
        if (cur.size() == n)   //leaf node
        {
            result.push_back(cur);
            return;
        }
        for (int i = pos; i < nums.size(); i++)
        {
            if(i != pos && nums[i] == nums[i-1])  // when duplicate and not 1st of dup. list --> Optimisation step
            {
                continue;
            }
            cur.push_back(nums[i]);
            solve(nums, n, i+1, cur, result); 
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>>result;
        vector<int> cur;
        sort(nums.begin(), nums.end());        
        for (int i = 0; i <= nums.size(); i++)
        {
            solve(nums, i, 0, cur, result);
        }
        return result;
    }
};
