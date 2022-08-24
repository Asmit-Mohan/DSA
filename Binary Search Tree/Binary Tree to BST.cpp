/* Time :- O(Nlogn) Space :- O(N) */

class Solution
{
  public:
  Node* change(Node* &root,vector<int>&v,int &i)
  {
      if(root==NULL)
      {
          return NULL;
      }
      change(root->left,v,i);
      root->data=v[i++];
      change(root->right,v,i);
  }
  Node* inorder(Node* root,vector<int>&v)
  {
      if(root!=NULL)
      {
          inorder(root->left,v);
          v.push_back(root->data);
          inorder(root->right,v);
      }
  }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int>v;
        int i=0;
        inorder(root,v);
        sort(v.begin(),v.end());
        change(root,v,i);
        return root;
    }
};
