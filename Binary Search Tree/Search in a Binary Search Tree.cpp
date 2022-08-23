/* Time :- O(logn) [Average Case]  O(N) [Worst Case] Space :- O(1) */

class Solution
{
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
          while(root!=NULL)
          {
              if(root->val==val)
              {
                  return root;
              }
              else if(root->val>val)
              {
                  root=root->left;
              }
              else
              {
                  root=root->right;
              }
          }
        return NULL;
    }
};

/* Time :- O(logn) [Average Case]  O(N) [Worst Case] Space :- O(N) */

class Solution
{
public:
    TreeNode* searchBST(TreeNode* root, int x)
    {
      TreeNode * current;
      if (root == NULL || root -> val == x)
      {
          current = root;
      }
      else if (root -> val < x)
      {
          current = searchBST(root -> right, x);
      }
      else if (root -> val > x)
      {
        current = searchBST(root -> left, x);
      }
      return current; 
    }
};
