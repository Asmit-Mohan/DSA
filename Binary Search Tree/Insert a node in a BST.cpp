/* Time :- O(N) [Worst Case] O(logn) [Average Case] Space :- O(1) */

class Solution
{
public:
    TreeNode* insertIntoBST(TreeNode* root, int Key)
    {
        if(root==NULL)
        {  
            TreeNode* temp =new TreeNode(Key);
            root=temp;
            return root;
        }
        
        TreeNode* prev=NULL;
        TreeNode* curr=root;
        TreeNode* temp= new  TreeNode(Key);
        
        while(curr!=NULL)
        {
            prev=curr;
            if(curr->val>Key)
            {
                curr=curr->left;
            }
            else if(curr->val<Key)
            {
                curr=curr->right;
            }
            else
            {
                return root;
            }
        }
        
        if(prev->val>Key)
        {
            prev->left=temp;
        }
        else
        {
            prev->right=temp;
        }
        return root;
    }
};
