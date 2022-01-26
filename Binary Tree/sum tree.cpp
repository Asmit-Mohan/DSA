class Solution
{
    public:
    int solve(Node* root,int &flag)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            return root->data;
        }
        
        int lsum=solve(root->left,flag);
        int rsum=solve(root->right,flag);
        
        if((lsum+rsum)!=root->data)
        {
            flag=0;
        }
        
        return root->data+lsum+rsum;
    }
    bool isSumTree(Node* root)
    {
       int flag=1;
       int temp=solve(root,flag);
       return flag;
    }
};
