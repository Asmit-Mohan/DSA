class Solution
{
    public:
    int solve(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=solve(root->left);
        int rh=solve(root->right);
        if(lh>rh)
        {
            return 1+lh;   /* left height + root */
        }
        else
        {
            return 1+rh;   /* right height + root */
        } 
    }
    int height(struct Node* root)
    {
        return solve(root);       
    }
};
