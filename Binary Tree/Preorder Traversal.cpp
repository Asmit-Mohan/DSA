/* Time :- O(N) Space :- O(N) of both the approaches */

/* Approach 1 Recursion */

void solve(Node* root,vector<int>&v)
{
     if(root==NULL)
     {
         return;
     }
     else
     {
         v.push_back(root->data);
         solve(root->left,v);
         solve(root->right,v);
     }
}

vector <int> preorder(Node* root)
{
    vector<int>v;
    solve(root,v);
    return v;
}

/* Approach 2 Iterative Stack */

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int>v;
        if(root==NULL)
        {
            return v;
        }
        else
        {
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp=s.top();
            s.pop();
            v.push_back(temp->val);
            if(temp->right)
            {
                s.push(temp->right);
            }
            if(temp->left)
            {
                s.push(temp->left);
            }
        }
        }
        return v;
    }
};
