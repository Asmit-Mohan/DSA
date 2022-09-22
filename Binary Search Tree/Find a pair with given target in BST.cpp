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

/* Approach 2 Time :- O(2*N) Space:- O(N) */

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

/* Approach 4 [Optimal BST Iterator] Time :- O(N) Space :- O(2*H) */

class Solution
{
public:
    stack<TreeNode*>sLeft;
    stack<TreeNode*>sRight;
    
    TreeNode* front = NULL;
    TreeNode* rear = NULL;
    
    int next_left()
    {    
        while(front)
        {
            sLeft.push(front);
            front = front->left;
        }
        int ans = sLeft.top()->val;
        front =  sLeft.top()->right;
        sLeft.pop();
        return ans;
    }
    
    int next_right()
    {
        while(rear)
        {
            sRight.push(rear);
            rear = rear->right;
        }
        int ans = sRight.top()->val;
        rear = sRight.top()->left;
        sRight.pop();
        return ans;
    }
    
    bool findTarget(TreeNode* root, int k)
    {
        front = root;
        rear = root;
        int l = next_left();
        int r = next_right();
        
        while(l<r)   /* This is taking O(N) time */
        {
            if(l+r == k)
            {
                return true;
            }
            else if(l+r<k)
            {
                l = next_left();
            }
            else
            {
                r = next_right();
            }
        }
        return false;
    }
};
