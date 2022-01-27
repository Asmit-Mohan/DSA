void solve(TreeNode<int> * root,int &ans,int X)
{
    if(root!=NULL)
    {
        solve(root->left,ans,X);
        if(X>=root->val)
        {
            ans=max(ans,root->val);
        }
        solve(root->right,ans,X);
    }
}
int floorInBST(TreeNode<int> * root, int X)
{
   int ans=INT_MIN;
   solve(root,ans,X);
   return ans;
}
