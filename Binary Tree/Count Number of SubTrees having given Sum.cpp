/* Question 1 In case only count Time :- O(N) Space :- O(H) */

int solve(Node* root, int X, int &ans)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int lSum=solve(root->left,X,ans);
    int rSum=solve(root->right,X,ans);
	
    if(lSum+rSum+root->data==X)
    {
        ans++;
    }
    return lSum+rSum+root->data;
}

int countSubtreesWithSumX(Node* root, int X)
{
    int ans=0;
    solve(root,X,ans);
    return ans;
}

/* Question 2 Incase Return subtree also having sum x --> InterviewBit */

bool solve(TreeNode* root, int currsum, int sum, vector<vector<int>> &ans, vector<int> &temp)
{
    if(root->left == NULL and root->right == NULL)
    {
        currsum += root->val;
        temp.push_back(root->val);

        if(currsum == sum)
        {
            ans.push_back(temp);
            temp.pop_back();
            return true;
        }
        temp.pop_back();
        return false;
    }

    temp.push_back(root->val);
    bool left = 0;
    bool right = 0;

    if(root->left != NULL)
    {
        left = solve(root->left, currsum + root->val, sum, ans, temp);
    }
    if(root->right != NULL)
    {
        right = solve(root->right, currsum + root->val, sum, ans, temp);
    }   
    temp.pop_back();
    return left or right;
}

vector<vector<int> > Solution::pathSum(TreeNode* root, int sum)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(root, 0, sum, ans, temp);
    return ans;
}
