void findPreSuc(Node* root, Node*& pre, Node*& suc, int target)
{
    if(root==NULL)
    {
        return;
    }
    else if(root->key>target)
    {
        suc=root;
        findPreSuc(root->left,pre,suc,target);
    }
    else if(root->key<target)
    {
        pre=root;
        findPreSuc(root->right,pre,suc,target);
    }
    else
    {
        findPreSuc(root->left,pre,suc,target);
        findPreSuc(root->right,pre,suc,target);
    }
}
