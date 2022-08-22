/* Time :- O(N) Space :- O(H) */

class Solution
{
    public:
    bool hasPathSum(Node *root, int S)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->left==NULL&&root->right==NULL&&(S-root->data==0))
        {
            return true;
        }
        return hasPathSum(root->left,S-root->data)||hasPathSum(root->right,S-root->data);
    }
};
