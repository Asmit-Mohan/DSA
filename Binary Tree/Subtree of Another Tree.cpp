class Solution
{
public:
    bool isIdentical(TreeNode *r1, TreeNode *r2)
    {
          if(r1==NULL&&r2==NULL)
          {
              return 1;
          }
          if(r1==NULL&&r2!=NULL)
          {
              return 0;
          }
          if(r1!=NULL&&r2==NULL)
          {
              return 0;
          }
          if(r1->val!=r2->val)
          {
              return 0;
          }
          if(isIdentical(r1->left,r2->left)&&isIdentical(r1->right,r2->right))
          {
              return 1;
          }
          return 0;
    }
    bool isSubtree(TreeNode* T, TreeNode* S)
    {
        if(S==NULL)  /*Since Null Set is subset of every set*/
        {
            return 1;
        }
        if(T==NULL) /*But parent set is null then no meaning of subset finding*/
        {
            return 0;
        }
        if(isIdentical(T,S))
        {
            return 1;
        }
        return (isSubtree(T->left,S)||isSubtree(T->right,S));
    }
};
