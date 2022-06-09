/* Approach 1 Time :- O(N) Space :- O(N) */

class Solution
{
public:
    TreeNode* prev=NULL;
    void flatten(TreeNode* root)
    {
       if(root==NULL)
       {
           return;
       }
       flatten(root->right);
       flatten(root->left); 
       root->right = prev;
       root->left = NULL; 
       prev = root; 
    }
};

/* Approach 2 Time :- O(N) Space :- O(N) */

class Solution
{
public:
    void flatten(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        
        stack<TreeNode*> stack;
        stack.push(root);
        TreeNode* currentNode;
        
        while(!stack.empty())
        {
            currentNode=stack.top();
            stack.pop();
            
            if(currentNode->right!=NULL)
            {
                stack.push(currentNode->right);
            }
            if(currentNode->left!=NULL)
            {
                stack.push(currentNode->left);
            }
            if(!stack.empty())
            {
                currentNode->right=stack.top();
            }
            currentNode->left=NULL;
        }
    }
};

/* Approach 3 Most Efficient Approach O(N) Space O(1) --> Morris Travarsal */

class Solution 
{
public:
    void flatten(TreeNode *root)
    {
		  TreeNode* curr = root;
      while(curr)
      {
          if(curr->left)
          {
            TreeNode* prev = curr->left;
            while(prev->right)
            {
              prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
          }
          curr = curr->right;
       }
    }
};
