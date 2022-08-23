/* Naive Approach Time :- O(N) Space :- O(N) */

void solve(Node* root,int target,int &ans)
{
    if(root==NULL)
    {
        return;
    }
    solve(root->left,target,ans);
    if(root->key<=target)
    {
        ans=max(ans,root->key);
    }
    solve(root->right,target,ans);
}

int findMaxForN(Node* root, int N)
{
    int ans = INT_MIN;
    solve(root,N,ans);
    return ans;
}

/* Efficient Approach Time :- O(H) Space :- O(H) where H can be replaced with logn since height of BST if logn */

int findMaxForN(Node* root, int N)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->key == N)
    {
        return N;
    }
    else if (root->key<N)
    {
        int k = findMaxforN(root->right, N);
        if (k == -1)
        {
            return root->key;
        }
        else
        {
            return k;
        }
    }
    else if (root->key > N)
    {
        return findMaxforN(root->left, N);  
    }   
}
