/* Time :- O(N) Space :- O(N) */

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val == p->val || root->val == q->val)
        {
            return root;
        }
        TreeNode* l =  lowestCommonAncestor(root->left,p,q);     //inorder
        TreeNode* r =  lowestCommonAncestor(root->right,p,q);   // inorder

        if(l==NULL && r!=NULL )
        {
            return r;
        }
        else if(r==NULL && l!=NULL)
        {
            return l;
        }
        else if(l==NULL && r==NULL )
        {
            return NULL;
        }
        else
        {
            return root;
        }
    }
};
