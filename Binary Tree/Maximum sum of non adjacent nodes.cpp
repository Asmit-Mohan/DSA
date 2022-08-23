/* Time :- O(N) Space :- O(N) */

class Solution  --> House Robber Approach
{
    public:
    unordered_map<Node*,int>dp;
    
    int getMaxSum(Node *root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        if(dp[root])
        {
            return dp[root];
        }
        
        int include = root->data;
        
        if(root->left)
        {
            include+=getMaxSum(root->left->left);
            include+=getMaxSum(root->left->right);
        }
        if(root->right)
        {
            include+=getMaxSum(root->right->left);
            include+=getMaxSum(root->right->right);
        }
        
        int exclude = getMaxSum(root->left) + getMaxSum(root->right);
        
        return dp[root] = max(include,exclude);
    }
};
