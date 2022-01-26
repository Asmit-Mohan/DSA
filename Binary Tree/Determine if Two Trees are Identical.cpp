class Solution
{
    public:
    bool isIdentical(Node *root1, Node *root2)
    {
        if(root1==NULL&&root2==NULL)
        {
            return true;
        }
        if(root1==NULL||root2==NULL)
        {
            return false;
        }
        if(root1->data!=root2->data)
        {
            return false;
        }
        return isIdentical(root1->left,root2->left)&&isIdentical(root1->right,root2->right);
    }
};
