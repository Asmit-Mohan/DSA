/* Time :- O(N) Space :- O(N) , Since solve function time and space is O(1) and it is called O(N) times */

class Solution 
{
public:
    void solve(TreeNode* root,int target,vector<int>temp,vector<vector<int>>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        temp.push_back(root->val);
        if(root->val==target&&root->left==NULL&&root->right==NULL)  //leaf node
        {
            ans.push_back(temp);
            return;
        }
        solve(root->left,target-root->val,temp,ans);
        solve(root->right,target-root->val,temp,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
           vector<vector<int>>v;
           vector<int>temp;
           solve(root,sum,temp,v);
           return v;
    }
};
