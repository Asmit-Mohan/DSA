class Solution
{
  public:
    int height(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=height(root->left);
        int r=height(root->right);
        return 1+max(l,r);
    }
    int diameter(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        int ans1=1+lh+rh;
        
        int ld=diameter(root->left);
        int rd=diameter(root->right);
        int ans2=max(ld,rd);
        
        int ans=max(ans1,ans2);
        
        return ans;
    }
};
