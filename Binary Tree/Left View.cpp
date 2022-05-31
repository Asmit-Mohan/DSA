/* Approach 1 Iterative */
vector<int> leftView(Node *root)
{
        vector<int> v;
        if (root==NULL) 
        {
           return v;
        }
        else
        {
         queue<Node*>q;
         q.push(root);
         while(q.size())
         {
             vector<int>res;
             int size=q.size();
             while(size--)
             {
                 Node* temp=q.front();
                 res.push_back(temp->data);
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
             v.push_back(res[0]);
         }
         return v;
        }
}

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
