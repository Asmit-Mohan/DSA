/* Approach 1 Time :- O(N) Space:- O(N) */

class Solution
{
public:
void find(Node* root,int target ,unordered_set<int> &s,bool &ans)
{
    if(root!=NULL)
    {
        find(root->left,target,s,ans);
        if(s.find(target-root->data)!=s.end())
        {
           ans=1;
           return ;
        }
        else
        {
           s.insert(root->data);
        }
        find(root->right,target, s,ans);
    }
}
    int isPairPresent(struct Node *root, int target)
    {
        unordered_set<int> s;
        bool ans=0;
        find(root,target,s,ans);
        return ans;
    }
};

/* Approach 2 Time :- O(N) Space:- O(N) */

class Solution
{
public:
    bool findTarget(TreeNode* root, int k)
    {
        
        vector<int> arr;
        inorderFill(root, arr);
        int low = 0;
        int high = arr.size()-1;
        while(low < high)
        {
            if(arr[low] + arr[high] == k)
            {
              return true;
            }
            else if(arr[low]+arr[high] < k)
            {
              low++;
            }
            else
            {
              high--;
            }
        }
        return false;
    }
    
    void inorderFill(TreeNode* root, vector<int>& arr)
    {
        if(root!=NULL)
        {
           inorderFill(root->left, arr);
           arr.push_back(root->val);
           inorderFill(root->right, arr); 
        }
    }
};

/* Approach 3 Time :- O(Nlogn) Space :- O(1) */

class Solution
{
    
public:
bool search( TreeNode *root ,int k , int x )
{
    while (root != NULL)
    { 
        if (k > root->val)
        {
            root = root->right; 
        }
        else if(k < root->val)
        {
            root = root->left; 
        }
        else if( root->val == x )
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return false; 
}
    
bool inOrder( TreeNode *a ,int k , TreeNode *root)
{
    return a && (inOrder(a->left,k,root) || search(root,k-a->val,a->val) || inOrder(a->right,k,root));
}

bool findTarget(TreeNode* root, int k)
{
    if(!root || (!root->left && !root->right) )
    {
        return false;
    }
    return inOrder(root , k , root);
}
};
