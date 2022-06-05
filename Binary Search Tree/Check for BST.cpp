/* Brute Force Approach */
class Solution
{
    public:
    
    bool isLarge(Node* root,int val)
    {
        if(root==NULL)
        {
            return 1;
        }
        if(root->data>val&&isLarge(root->left,val)&&isLarge(root->right,val))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    bool isSmall(Node* root,int val)
    {
        if(root==NULL)
        {
            return 1;
        }
        if(root->data<val&&isSmall(root->left,val)&&isSmall(root->right,val))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    bool isBST(Node* root) 
    {
         if(root==NULL)
         {
             return 1;
         }
         
         int temp1=isSmall(root->left,root->data);
         int temp2=isLarge(root->right,root->data);
         int temp3=isBST(root->left);
         int temp4=isBST(root->right);
         
         if(temp1&&temp2&&temp3&&temp4)
         {
             return 1;
         }
         else
         {
             return 0;
         }
    }
};

/* Optimised Code --> Striver Time :- O(N) Space :- O(1) + Auxiliary Stack Space */

class Solution
{
public:
    bool solve(TreeNode* root,long minRange,long maxRange)
    {
          if(root==NULL)
          {
              return true;
          }
          if(root->val>=maxRange||root->val<=minRange)
          {
              return false;
          }
          bool temp1 = solve(root->left,minRange,root->val);
          bool temp2 = solve(root->right,root->val,maxRange);
          
          if(temp1&&temp2)
          {
              return true;
          }
          else
          {
              return false;
          }
    }
    
    bool isValidBST(TreeNode* root)
    {
        return solve(root,LONG_MIN,LONG_MAX);    
    }
};
