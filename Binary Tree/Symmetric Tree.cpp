/*Approach 1 */

class Solution
{
    public:
    bool solve(struct Node* root1,struct Node* root2)
    {
        if(root1==NULL&&root2==NULL)
        {
            return true;
        }
        if(root1==NULL||root2==NULL)
        {
            return false;
        }
        if(root1->data!=root2->data)
        {
            return false;
        }
        return solve(root1->left,root2->right)&&solve(root1->right,root2->left);
    }
    bool isSymmetric(struct Node* root)
    {
	      return solve(root,root);
    }
};

/* Approach 2 */

class Solution
{
public:
    bool isSame(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL&&root2==NULL)
        {
            return true;
        }
        if(root1==NULL||root2==NULL)
        {
            return false;
        }
        if(root1->val!=root2->val)
        {
            return false;
        }
        return isSame(root1->left,root2->left)&&isSame(root1->right,root2->right);
    }
    
    void mirror(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        mirror(root->left);
        mirror(root->right);
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    
    bool isSymmetric(TreeNode* root)
    {
        if(root==NULL||root->left==NULL&&root->right==NULL)
        {
            return true;
        }
        mirror(root->right);
        return isSame(root->left,root->right);
    }
};
