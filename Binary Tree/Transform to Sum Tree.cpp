/* Time :- O(N) Space :- O(H) */

class Solution
{
  public:
    int solve(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        int temp=root->data+left+right;
        root->data=left+right;
        return temp;
    }
    
    void toSumTree(Node *node)
    {
        solve(node);
    }
};
