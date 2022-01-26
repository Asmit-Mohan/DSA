/*Recursive*/

void kdistance(struct Node *root, int k,vector<int>& v)
{
    if(k==0)
    {
        v.push_back(root->data);
        return;
    }
    if(root->left)
    {
        kdistance(root->left,k-1,v);
    }
    if(root->right)
    {
        kdistance(root->right,k-1,v);
    }
}
vector<int> Kdistance(struct Node *root, int k)
{
   vector<int> vec;
   kdistance(root,k,vec);
   return vec;
}

/*Iterative*/

vector<int> Kdistance(struct Node *root, int k)
{
       vector<int>ans;
       if(root==NULL)
       {
          return ans; 
       }
       if(k==0)
       {
           ans.push_back(root->data);
           return ans;
       }
       queue<Node*>q;
       q.push(root);

       while(!q.empty())
       {
           int n=q.size();
           while(n--)
           {
               Node* temp=q.front();
               q.pop();
               if(k==0)
               {
                    ans.push_back(temp->data);
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
           k--;
           if(k==-1)
           {
               break;
           }
       }
       return ans;
}
