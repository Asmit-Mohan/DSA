class Solution
{
    public:
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1==NULL&&r2==NULL)
        {
            return 1;
        }
        else if(r1==NULL || r2==NULL)
        {
            return 0;
        }
        else if(r1->data!=r2->data)
        {
            return 0;
        }
        else
        {
            return isIdentical(r1->left,r2->left)&&isIdentical(r1->right,r2->right);
        }
    }
    void mirror(Node *root)
    {
        if(root!=NULL)
        {
            mirror(root->left);
            mirror(root->right);
            Node* temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
    }
    int areMirror(Node* a, Node* b)
    {
       mirror(a);
       return isIdentical(a,b);
    }
};
