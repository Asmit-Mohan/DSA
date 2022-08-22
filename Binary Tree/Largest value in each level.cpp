/* Time :- O(N) Space :- O(N) */

class Solution
{
    public:
    vector<int> largestValues(Node* root)
    {
     vector<int> v;
     queue<Node*>q;
     q.push(root);
     while(q.size())
     {
         int res=INT_MIN;
         int size=q.size();
         while(size--)
         {
             Node* temp=q.front();
             res=max(res,temp->data);
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
};
