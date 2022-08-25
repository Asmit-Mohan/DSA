/* Approach 1 Time :- O(H) Space :- O(1) */

class Solution
{
public:
Node * inOrderSuccessor(Node *root, Node *x)
{
Node *prev = NULL;
Node *cur = root;
while(cur!=NULL)
{
     if(cur->data > x->data)
     {
	  prev = cur;
          cur = cur->left;
     }
     else
     {
	  cur = cur->right;
     }
}
return prev;
}
};

/* Approach 2 Time :- O(H) Space :- O(1) */

class Solution
{
  public:
    
    void solve(Node* root,Node* &ans,int target)
    {
       if(root==NULL)
       {
           return;
       }
       
       if(root->data>target)
       {
           ans=root;
           solve(root->left,ans,target);
       }
       
       if(root->data<=target)
       {
           solve(root->right,ans,target);
       }
    }
    
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* ans=NULL;
        solve(root,ans,x->data);
        return ans;
    }
};
