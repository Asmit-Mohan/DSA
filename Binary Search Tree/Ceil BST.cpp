/* Approach 1 Time :- O(N) Space :- O(N) */

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

/* Approach 2 Time :- O(H) Space :- O(1) */

 int findCeil(BinaryTreeNode<int> *root, int key)
 {
	int ceil = -1; 
    while (root)
    {
        if (root->data == key)
        {
            ceil = root->data;
            return ceil;
        }
        if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data; 
            root = root->left;
        }
    }
    return ceil; 
}
