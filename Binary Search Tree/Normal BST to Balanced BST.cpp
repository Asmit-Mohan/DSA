/* Time :- O(N) Space :- O(N) */

class Solution
{
public:
    void inorder(TreeNode* root,vector<int>&v)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    TreeNode* solve(int low,int high,vector<int>&arr)
    {
        if(low>high)
        {
            return NULL;
        }
        
        int mid = low+(high-low)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left =  solve(low,mid-1,arr);
        root->right = solve(mid+1,high,arr);   
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root)
    {
        vector<int>v;
        inorder(root,v);
        return solve(0,v.size()-1,v);
    }
};
