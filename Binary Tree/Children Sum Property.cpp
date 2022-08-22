/* Time :- O(N) Space :- O(H) */

/* Convert To Follow Children Sum Property (CSP)  --> Striver */

void changeTree(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    int child=0;
    if(root->left)
    {
        child+=root->left->data;
    }
    if(root->right)
    {
        child+=root->right->data;
    }
    if(child>=root->data)
    {
        root->data=child;
    }
    else
    {
        if(root->left)
        {
            root->left->data=root->data;
        }
        if(root->right)
        {
            root->right->data=root->data;
        }
    }
    int total=0;
    
    changeTree(root->left);
    changeTree(root->right);
    
    if(root->left)
    {
        total+=root->left->data;
    }
    if(root->right)
    {
        total+=root->right->data;
    }
    if(root->left||root->right)
    {
        root->data=total;
    }
}  

/* Check Whether Tree Follows CSP or NOT */

class Solution
{
    public:
    int solve(Node* root,int &flag)
    {
        if(root==NULL)
        {
            return 0;        
        }
        int lSum=solve(root->left,flag);
        int rSum=solve(root->right,flag);
        
        if((lSum+rSum)!=root->data&&(root->left!=NULL||root->right!=NULL))
        {
            flag=false;
        }
        return root->data;
    }
    
    int isSumProperty(Node *root)
    {
        if(root==NULL)
        {
            return 1;
        }
        int flag=true;
        solve(root,flag);
        return flag;
    }
};
