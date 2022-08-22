/* Time :- O(N) Space :- O(N) */

void solve(Node* root,int &count)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        count++;
    }
    if(root->left)
    {
        solve(root->left,count);
    }
    if(root->right)
    {
        solve(root->right,count);
    }
}

int countLeaves(Node* root)
{
    int count=0;
    solve(root,count);
    return count;
}
