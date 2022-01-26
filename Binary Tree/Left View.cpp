vector<int> leftView(Node *root)
{
        vector<int> v;
        if (root==NULL) 
        {
           return v;
        }
        else
        {
         queue<Node*>q;
         q.push(root);
         while(q.size())
         {
             vector<int>res;
             int size=q.size();
             while(size--)
             {
                 Node* temp=q.front();
                 res.push_back(temp->data);
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
             v.push_back(res[0]);
         }
         return v;
        }
}
