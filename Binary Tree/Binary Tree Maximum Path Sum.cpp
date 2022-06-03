class Solution 
{    
public:
    int solve(TreeNode * root, int & maxi)
    {
          if(root==NULL)
          {
              return 0;
          }
          int leftSum  =  max(0,solve(root->left,maxi));
          int rightSum =  max(0,solve(root->right,maxi));
          int sum = leftSum+rightSum+root->val;
          maxi = max(maxi,sum);
          return max(leftSum,rightSum)+root->val;
    }
    int maxPathSum(TreeNode* root)
    {
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};
