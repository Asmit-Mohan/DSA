void solve(Node* root,vector<int>&v)
{
     if(root==NULL)
     {
         return;
     }
     else
     {
         v.push_back(root->data);
         solve(root->left,v);
         solve(root->right,v);
     }
}

vector <int> preorder(Node* root)
{
    vector<int>v;
    solve(root,v);
    return v;
}
