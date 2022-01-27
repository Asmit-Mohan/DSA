/*Naive Approach*/

void solve(Node* root,vector<int>&v)
{
    if(root!=NULL)
    {
        solve(root->left,v);
        v.push_back(root->key);
        solve(root->right,v);
    }
}
int findMaxForN(Node* root, int target)
{
    vector<int>v;
    solve(root,v);
    sort(v.begin(),v.end());
    auto it = lower_bound(v.begin(),v.end(),target);
        if((*it)== target)
        {
            return *(it);
        }
        else
        {
            return *(it - 1);
        }
}

/*Efficient Approach*/
void solve(Node* root,int &ans,int target)
{
    if(root==NULL)
    {
        return;
    }
    if(target>=root->key)
    {
        ans=max(ans,root->key);
    }
    if(root->key>target)
    {
        solve(root->left,ans,target);
    }
    if(root->key<target)
    {
        solve(root->right,ans,target);
    }
}
int findMaxForN(Node* root, int target)
{
    int ans=INT_MIN;
    solve(root,ans,target);
    return ans;
}
