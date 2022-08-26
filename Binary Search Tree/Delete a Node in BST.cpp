/* Time :- O(H) Space :- O(H) */

class Solution
{
public:
    int minValue(TreeNode* root)
    {
        int minVal = root->val;
        while(root->left!=NULL)
        {
            minVal = root->left->val;
            root=root->left;
        }
        return minVal;
    }
   
    TreeNode* deleteNode(TreeNode* root, int key)
    {
         if(root==NULL)
         {
             return root;
         }
         if(root->val>key)
         {
             root->left = deleteNode(root->left,key);
         }
         else if(root->val<key)
         {
             root->right = deleteNode(root->right,key);
         }
         else
         {
            if(root->left==NULL)
            {
                return root->right;
            } 
            else if(root->right==NULL)
            {
                return root->left;
            }
            root->val  = minValue(root->right);
            root->right = deleteNode(root->right,root->val);
         }
        return root;
     }
};
