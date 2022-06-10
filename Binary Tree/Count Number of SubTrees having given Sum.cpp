int solve(Node* root, int X, int &ans)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int lSum=solve(root->left,X,ans);
    int rSum=solve(root->right,X,ans);
    
    if(lSum+rSum+root->data==X)
    {
        ans++;
    }
    
    return lSum+rSum+root->data;
}
    
    
int countSubtreesWithSumX(Node* root, int X)
{
	int ans=0;
	solve(root,X,ans);
	return ans;
}
