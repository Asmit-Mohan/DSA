/* Time :- O(N) Space :- O(1) */

class Solution
{
    public:
    int maxPathSum(Node* root)
    {
        if(root==NULL)
        {
            return INT_MIN;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            return root->data;
        }
        
        int leftsum = maxPathSum(root->left);
        int rightsum = maxPathSum(root->right);
        
        return root->data+max(leftsum,rightsum);
    }
};
