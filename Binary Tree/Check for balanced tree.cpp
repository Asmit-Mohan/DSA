/* Time :- O(N) Space :- O(N) */

class Solution
{
    public:
    int height(Node* root,int &flag)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=height(root->left,flag);
        int rh=height(root->right,flag);
        if(abs(lh-rh)>1)
        {
            flag=0;
        }
        else
        {
            return 1+max(lh,rh);
        }
    }
    bool isBalanced(Node *root)
    {
       int flag=1;
       height(root,flag);
       return flag;
    }
};
