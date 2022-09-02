/* 
     Time :- O(N*H) Space :- O(N*H) --> Each Inorder will take O(H) Time and Space to delete a node and inorder runs for O(N) 
   
     Assuming worst case when we will delete all the node of BST.
*/

class Solution
{
public:
    
    int minValue(TreeNode* &root)
    {
        int minVal = root->val;
        while(root->left!=NULL)
        {
            minVal = root->left->val;
            root=root->left;
        }
        return minVal;
    }
   
    TreeNode* deleteNode(TreeNode* &root, int key)
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
    
    void inorder(TreeNode* &root,int low,int high)
    {
        if(root!=NULL)
        {
            if(root->left)
            {
                inorder(root->left,low,high);
            }
            if(root->right)
            {
                inorder(root->right,low,high);
            }
            if(root->val<low || root->val>high)
            {
                root = deleteNode(root,root->val);
            }
        }
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        inorder(root,low,high);
        return root;
    }
};
