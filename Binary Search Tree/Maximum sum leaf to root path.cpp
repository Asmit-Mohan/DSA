class Solution
{
    public:
    int maxPathSum(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int left=maxPathSum(root->left);
        int right=maxPathSum(root->right);
        return root->data+max(left,right);
    }
};
