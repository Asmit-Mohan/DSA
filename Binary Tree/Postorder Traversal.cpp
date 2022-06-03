/* Approach 1 Recursion */
void post(Node* root,vector<int>&v)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        post(root->left,v);
        post(root->right,v);
        v.push_back(root->data);
    }
}

vector <int> postOrder(Node* root)
{
    vector<int>v;
    post(root,v);
    return v;
}

/* Approach 2 Iterative Using 2 Stack*/
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int>v;
        if(root==NULL)
        {
            return v;
        }
        else
        {
            stack<TreeNode*>s1,s2;
            s1.push(root);
            while(!s1.empty())
            {
                TreeNode* temp=s1.top();
                s1.pop();
                s2.push(temp);
                if(temp->left)
                {
                    s1.push(temp->left);
                }
                if(temp->right)
                {
                    s1.push(temp->right);
                }
            }
            while(!s2.empty())
            {
                v.push_back(s2.top()->val);
                s2.pop();
            }
        }
        return v;      
    }
};

/* Approach 3 Using 1 Stack */ 

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ans;
	if(root==NULL)
        {
            return ans;
        }
		TreeNode* curr;
		stack<TreeNode*>s;
		s.push(root);
		while(!s.empty())
                {
			curr = s.top();
			s.pop();
			ans.push_back(curr->val);
			if(curr->left)
			{
			   s.push(curr->left);
			}
		        if(curr->right)
		        {
			   s.push(curr->right);
		        }
	        }
		reverse(ans.begin(),ans.end());
		return ans;
     }
};
