/* Naive Approach */

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

/* Approach 2 */

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
            k--;
            if(k==0)
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

/* Approach 3 */

class Solution
{
public:
int total=0;

void count(Node* root)
{
    if(root!=NULL)
    {
        count(root->left);
        total++;
        count(root->right);
    }
}

int temp=0;

void solve(Node* root,int &ans,int k)
{
    if(root!=NULL)
    {
        solve(root->left,ans,k);
        temp++;
        if(temp==k)
        {
            ans=root->data;
        }
        solve(root->right,ans,k);
    }
}

    int kthLargest(Node *root, int k)
    {
        int ans=INT_MIN;
        count(root);
        k=total-k+1;
        solve(root,ans,k);
        return ans;
    }
};
