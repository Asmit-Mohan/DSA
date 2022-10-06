class Solution
{
public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val < low)
        {
            root->left=NULL;
            return trimBST(root->right,low,high);
        }
        if(root->val > high)
        {
            root->right=NULL;
            return trimBST(root->left,low,high);
        }
        else
        {
            root->left = trimBST(root->left,low,high);
            root->right = trimBST(root->right,low,high);
        }
        return root;
    }
};
