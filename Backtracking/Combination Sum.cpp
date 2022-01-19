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
