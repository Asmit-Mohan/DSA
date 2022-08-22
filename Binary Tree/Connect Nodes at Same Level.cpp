/* Time :- O(N) Space :- O(N) */

class Solution
{
    public:
    void connect(Node *root)
    {
       queue<Node*>q;
       q.push(root);
       
       while(!q.empty())
       {
           int n=q.size();
           while(n--)
           {
               Node* temp=q.front();
               q.pop();
               if(n==0)
               {
                   temp->nextRight=NULL;
               }
               else
               {
                   temp->nextRight=q.front();
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
     }
};
