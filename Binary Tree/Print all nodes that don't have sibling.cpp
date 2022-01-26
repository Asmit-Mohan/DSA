void solve(Node* root,vector<int>&v)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left&&root->right==NULL)
    {
        v.push_back(root->left->data);
    }
    if(root->right&&root->left==NULL)
    {
        v.push_back(root->right->data);
    }
    if(root->left)
    {
        solve(root->left,v);
    }
    if(root->right)
    {
        solve(root->right,v);
    }
}
vector<int> noSibling(Node* root)
{
    vector<int>ans;
    solve(root,ans);
    if(ans.size()==0)
    {
        ans.push_back(-1);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
