/* Approach 1 */
class Solution
{
    public:
    vector<int> rightView(Node *root)
    {
        vector<int> v;
        if(root==NULL) 
        {
           return v;
        }
        else
        {
         queue<Node*>q;
         q.push(root);
         while(q.size())
         {
             int size=q.size();
             int res;
             while(size--)
             {
                 Node* temp=q.front();
                 res=temp->data;
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
             v.push_back(res);
         }
         return v;
        }
    }
};

/* Approach 2 */

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
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};
