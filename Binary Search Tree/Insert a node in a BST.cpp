Node* insert(Node* root, int key)
{
    if(root==NULL)
    {
        return root;
    }
    
    Node* prev=NULL;
    Node* curr=root;
    Node *temp= new Node(key);
    
    while(curr!=NULL)
    {
        prev=curr; 
        if(curr->data>key)
        {
            curr=curr->left;
        }
        else if(curr->data<key)
        {
            curr=curr->right;
        }
        else
        {
            return root;    /*If K is already present in the BST, don't modify the BST*/
        }   
    }
    if(prev->data>key)  
    {
        prev->left=temp;
    }
    else
    {
        prev->right=temp;
    }
    return root;
}
