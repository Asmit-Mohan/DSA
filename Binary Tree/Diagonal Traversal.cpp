vector<int> diagonal(Node *root)
{
   vector<int> vec;
   if(root==NULL)
   {
      return vec; 
   }
   
   queue<Node *> q;
   q.push(root);
   
   while(!q.empty())
   {
       Node *temp = q.front();
       q.pop();
       
       while(temp)
       {
           if(temp->left)
           {
               q.push(temp->left);
           }
           vec.push_back(temp->data);
           temp = temp->right;
       }
   }
   return vec;
}
