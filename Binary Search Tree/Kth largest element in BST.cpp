/* Naive Approach Time :- O(N) Space :- O(N) + O(N) */

class Solution
{
    public:
    void solve(Node* root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            solve(root->right,ans);
            ans.push_back(root->data);
            solve(root->left,ans);
        }
    }
    int kthLargest(Node *root, int k)
    {
        vector<int>ans;
        solve(root,ans);
        return ans[k-1];
    }
};

/* Eficient Approach Time :- O(N) Space :- O(N) */

class Solution
{
    public:
    void solve(Node* root,int &ans,int &k)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            solve(root->right,ans,k);
            if(--k==0)
            {
                ans=root->data;
            }
            solve(root->left,ans,k);
        }
    }
    int kthLargest(Node *root, int k)
    {
        int ans=0;
        solve(root,ans,k);
        return ans;
    }
};
