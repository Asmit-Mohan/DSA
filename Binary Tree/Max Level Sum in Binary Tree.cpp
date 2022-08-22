/* Time :- O(N) Space :- O(N) */

class Solution
{
  public:
    int maxLevelSum(Node* root)
    {
     int res=INT_MIN;
     queue<Node*>q;
     q.push(root);
     while(q.size())
     {
         int size=q.size();
         int ans=0;
         while(size--)
         {
             Node* temp=q.front();
             ans=ans+temp->data;
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
         res=max(res,ans);
     }
     return res;
    }
};
