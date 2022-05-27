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

class Solution
{
    public:
    TreeNode* solve(vector<int>& nums, int low, int high)
    {
        if(low>=high)
        {
            return NULL; 
        }
        
        int mid=(low+high)/2;
        
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=solve(nums,low,mid);
        root->right=solve(nums,mid+1,high);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return solve(nums,0,nums.size());
    }
};
