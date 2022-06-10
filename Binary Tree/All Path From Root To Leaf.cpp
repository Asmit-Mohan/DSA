class Solution
{
public:
    void solve(TreeNode* root,vector<string>& res,string str)
    {
        if(root->left ==NULL && root->right==NULL)
        {
            res.push_back(str);
            return;
        }
        
        if(root->left)
        {
            solve(root->left,res,str + "->" + to_string(root->left->val));
        }
        if(root->right)
        {
            solve(root->right,res,str + "->" + to_string(root->right->val));
        }
    } 
        
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
        if (root==NULL)
        {
            return res;
        }
        solve(root,res,to_string(root->val));
        return res;
    }
};
