void solve(BinaryTreeNode<int> * root,int &ans,int X)
{
    if(root!=NULL)
    {
        solve(root->left,ans,X);
        if(root->data>=X)
        {
            ans=min(ans,root->data);
        }
        solve(root->right,ans,X);
    }
}

int findCeil(BinaryTreeNode<int> *node, int x)
{
    int ans=INT_MAX;
    solve(node,ans,x);
    return ans==INT_MAX?-1:ans;
}
