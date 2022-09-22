class Solution
{
    public:
    Node* prev=NULL;
    Node* head=NULL;
    
    Node * bToDLL(Node *root)
    {
        if(root==NULL)
        {
            return NULL;
        }
        
        /* Inorder Technique */
        
        bToDLL(root->left);
        
        if(prev==NULL)
        {
            head=root;
            head->left=NULL;
        }
        else
        {
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        
        bToDLL(root->right);
        return head;
    }
};
