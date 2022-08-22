/* Time :- O(N) Space :- O(N) */

bool findPath(TreeNode* root,int target,vector<int>&ans)
{
    if(root==NULL)
    {
        return 0;
    }
    ans.push_back(root->val);
    if(root->val==target)
    {
        return 1;
    }
   
    if(findPath(root->left,target,ans)||findPath(root->right,target,ans))
    {
        return 1;
    }
    ans.pop_back();
    return 0;
}

vector<int> Solution::solve(TreeNode* root, int target)
{
    vector<int>ans;
    if(root==NULL)
    {
        return ans;
    }
    findPath(root,target,ans);
    return ans;
}
