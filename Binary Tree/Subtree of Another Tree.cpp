/* Time :- O(M*N) where M and N are number of nodes in Tree 1 and Tree 2 Space :- O(N) */

class Solution
{
public:
    bool isSame(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL&&root2==NULL)
        {
            return 1;
        }
        if(root1==NULL||root2==NULL)
        {
            return 0;
        }
        if(root1->val!=root2->val)
        {
            return 0;
        }
        return isSame(root1->left,root2->left)&&isSame(root1->right,root2->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subroot)
    {
         if(root==NULL)
         {
             return 0;
         }
         if(subroot==NULL)
         {
             return 1;
         }
         if(isSame(root,subroot))
         {
             return 1;
         }
        return isSubtree(root->left,subroot)||isSubtree(root->right,subroot);
    }
};
