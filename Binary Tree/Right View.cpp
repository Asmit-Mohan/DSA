/* Time :- O(N) Space :- O(H) */

/* Approach 1 */

class Solution
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int>vec;
        if (root==NULL)
        {
            return vec;
        }
        else
        {
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty())
            {
                int n=q.size();
                while(n--)
                {
                    TreeNode *temp=q.front();
                    q.pop();
                    if(n==0)
                    {
                        vec.push_back(temp->val);
                    }
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
            return vec;
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
