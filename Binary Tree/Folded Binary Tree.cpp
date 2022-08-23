/* Time :- O(N) Space :- O(N) */

bool solve(Node* left,Node* right)
{
   if(left==NULL && right==NULL)
   {
       return true;
   }

   if(left==NULL || right==NULL)
   {
       return false;
   }
   
   return solve(left->left,right->right) && solve(left->right,right->left);
}

bool IsFoldable(Node* root)
{
    if(root==NULL)
    {
       return true;
    }
   return solve(root->left,root->right);
}
