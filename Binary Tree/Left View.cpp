/* Time :- O(N) Space :- O(N) for both the approaches */

/* Approach 1 Iterative */

class Solution
{
public:
vector<int> leftView(Node *root)
{
    vector<int> v;
    if (root==NULL) 
    {
        return v;
    }
    
    queue<Node*>q;
    q.push(root);
    while(q.size())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            Node* temp=q.front();
            if(i==0)
            {
               v.push_back(temp->data);
            }
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return v;
}
};

/* Approach 2 Recursive */ 

class Solution
{
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL)
        {
            return ;
        }
        if(res.size()==level)
        {
           res.push_back(root->val);
        }
        recursion(root->left,  level+1, res);
        recursion(root->right, level+1, res);
    }
    
    vector<int> leftSideView(TreeNode *root)
    {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};
