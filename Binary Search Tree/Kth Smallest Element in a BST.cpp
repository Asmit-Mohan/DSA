class Solution
{
public:
    int count=0;
    void triverse(TreeNode *root,int k,int &res)
    {
          if(root!=NULL)
          {
                triverse(root->left,k,res);
                count++;
                if(k==count)
                {
                    res=root->val;
                }
                triverse(root->right,k,res);   
          }   
    }
    int kthSmallest(TreeNode* root, int k)
    {
          int res=INT_MAX;
          triverse(root,k,res);
          if(res==INT_MAX)
          {
              return -1;
          }
          else
          {
              return res;
          }
    }
};
