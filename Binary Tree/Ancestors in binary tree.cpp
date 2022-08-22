/* Time :- O(N) Space :- O(H) */

class Solution
{
  public:
    int solve(struct Node *root,int target,vector<int>&v)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->data==target)
        {
            return 1;
        }
        if(solve(root->left,target,v)||solve(root->right,target,v))
        {
            v.push_back(root->data);
        }
    }
    vector<int> Ancestors(struct Node *root, int target)
    {
        vector<int>v;
        solve(root,target,v);
        return v;
    }
};
