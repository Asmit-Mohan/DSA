class Solution
{
  public:
  int minDepth(Node *root)  
  {
         if(root==NULL)
         {
             return 0;
         }
         int lh=minDepth(root->left);
         int rh=minDepth(root->right);
         if(lh==0)
         {
             return 1+rh;
         }
         else if(rh==0)
         {
             return 1+lh;
         }
         else
         {
            return 1+min(lh,rh);
         }
    }
};
