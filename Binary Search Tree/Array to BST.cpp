class Solution
{
public:
    void solve(vector<int>nums,int l,int r,vector<int>&v)
    {
        if(l<=r)
        {
            int mid=l+(r-l)/2;
            v.push_back(nums[mid]);
            solve(nums,l,mid-1,v);
            solve(nums,mid+1,r,v);
        }
        else
        {
            return;
        }
    }
    vector<int> sortedArrayToBST(vector<int>& nums)
    {
        vector<int>v;
        solve(nums,0,nums.size()-1,v);
        return v;
    }
};
