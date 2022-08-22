/* Time :- O(N) Space :- O(N) */

vector<vector<int>> levelOrder(Node* root)
{
       vector<vector<int>>ans;
       if(root==NULL)
       {
          return ans; 
       }
       
       queue<Node*>q;
       q.push(root);
       
       while(!q.empty())
       {
           int n=q.size();
           vector<int>v;
           while(n--)
           {
               Node* temp=q.front();
               q.pop();
               v.push_back(temp->data);
               if(temp->left)
               {
                   q.push(temp->left);
               }
               if(temp->right)
               {
                   q.push(temp->right);
               }
           }
           ans.push_back(v);
       }
       return ans;
}
