/* Recursion Time :- O(N) Space :- O(N) [Worst Case when Skewed Tree] O(H) [Average Case]*/

class Solution
{
  public:
    vector<int>v;
    vector<int> inOrder(Node* root)
    {
         if(root!=NULL)
         {
             inOrder(root->left);
             v.push_back(root->data);
             inOrder(root->right);
         }
         return v;
    }
};

/* Iterative Time :- O(N) Space :- O(N) */

class Solution
{
  public:
    vector<int> inOrder(Node* root)
    {
       stack<Node*>s;
       vector<int>v;
       while(1)
       {
           while(root)
           {
               s.push(root);
               root=root->left;
           }
           if(s.empty())
           {
               break;
           }
           root=s.top();
           s.pop();
           v.push_back(root->data);
           root=root->right;
       }
         return v;
    }
};
