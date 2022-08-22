/*     
       Time  Complexity :- O(min(M, N)) where M and N are the sizes of the two trees.
       Space Complexity :- O(min(H1, H2)) where H1 and H2 are the heights of the two trees.
*/

class Solution
{
  public:
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if(root1==NULL&&root2==NULL)
        {
            return true;
        }
        if(root1==NULL||root2==NULL)
        {
            return false;
        }
        if(root1->data!=root2->data)
        {
            return false;
        }
        return isIsomorphic(root1->left,root2->left)&&isIsomorphic(root1->right,root2->right)||
        isIsomorphic(root1->left,root2->right)&&isIsomorphic(root1->right,root2->left);
    }
};
