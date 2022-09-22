/* Noted here Time Complexity is discussed only of next() and hasNext() as per question requirement */

/* Approach 1 Brute Force Time :- O(1) Space :- O(N) */

class BSTIterator
{
    vector<int>arr;
    int i=0;
    public:
    
    void inorder(TreeNode*&root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    
    BSTIterator(TreeNode* root)
    {
        inorder(root);
    }
    
    int next()
    {
        int ans=arr[i];
        i++;
        return ans;    
    }
    
    bool hasNext()
    {     
        if(i<arr.size())
        {
            return true;
        }
        return false;
    }
};

/* Approach 2 Time :- O(1) [Average case] O(H) [Worst Case] Space :- O(H) */

class BSTIterator
{
stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root)
    {
        TreeNode* temp = root;
        while (temp!=NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
    }
    
    int next()
    {
        int val = s.top()->val;
        TreeNode* temp = s.top()->right;
        s.pop();
        
        while (temp)
        {
            s.push(temp);
            temp = temp->left;
        }
        return val;
    }
    
    bool hasNext()
    {
        return s.size()==0?false:true;
    }
};
