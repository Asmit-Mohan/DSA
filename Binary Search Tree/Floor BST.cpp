/* Approach 1 Time :- O(N) Space :- O(1) */

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

/* Approach 2 Time :- O(H) Space :- O(1) */

int floorInBST(TreeNode<int> * root, int key)
{
    int floor = -1; 
    while (root)
    {
        if (root->val == key)
        {
            floor = root->val;
            return floor;
        }
 
        if (key > root->val)
        {
            floor = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
}
