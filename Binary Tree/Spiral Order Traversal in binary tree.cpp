vector<int> findSpiral(Node *root)
{
   vector<int>v;
   if(root==NULL)
   {
       return v;
   }
   stack<Node*>s1,s2;  //s1 for odd level and s2 for even level.
   s1.push(root);
   while(!s1.empty() || !s2.empty())
   {
       while(!s1.empty())
       {
          Node* temp=s1.top();
          v.push_back(temp->data);
          s1.pop();
          if(temp->right)
          {
              s2.push(temp->right);    
          }
          if(temp->left)
          {
              s2.push(temp->left);    
          }
       }
       while(!s2.empty())
       {
          Node* temp=s2.top();
          v.push_back(temp->data);
          s2.pop();
          if(temp->left)
          {
              s1.push(temp->left);    
          }
          if(temp->right)
          {
              s1.push(temp->right);    
          }
       }
   }
   return v;
}
