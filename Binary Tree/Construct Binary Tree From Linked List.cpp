TreeNode *create(TreeNode *root,vector<int> &v,int i)
{
   if(i>=v.size())
   {
       return NULL;
   }
   root = new TreeNode(v[i]);
   root->left =  create(root,v,2*i+1);
   root->right = create(root,v,2*i+2);
   return root;
}

void convert(Node *head, TreeNode *&root)
{
   if(head==NULL)
   {
       return;
   }
   vector<int> v;
   Node* curr = head;
   while(curr != NULL)
   {
      v.push_back(curr->data);
      curr=curr->next;    
   }
   root=create(root,v,0);
   return;
}
