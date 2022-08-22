/* Time :- O(N) Space :- O(H) */

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
