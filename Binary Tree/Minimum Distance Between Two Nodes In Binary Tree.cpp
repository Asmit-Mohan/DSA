class Solution
{
    public:
    int distance(Node* root,int node)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->data==node)
        {
            return 1;
        }
        
        int ans1 = distance(root->left,node);
        if(ans1)
        {
            return 1 + ans1;
        }
        
        int ans2 = distance(root->right,node);
        if(ans2)
        {
            return 1 + ans2;
        }
    }
    
    Node* LCA(Node* root,int a,int b)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->data == a || root->data == b)
        {
            return root;
        }
        Node* l =  LCA(root->left,a,b);     //inorder
        Node* r =  LCA(root->right,a,b);   // inorder
    
        if(l==NULL && r!=NULL )
        {
            return r;
        }
        else if(r==NULL && l!=NULL)
        {
            return l;
        }
        else if(l==NULL && r==NULL )
        {
            return NULL;
        }
        else
        {
            return root;
        }
    }
    
    int findDist(Node* root, int a, int b)
    {
        Node* lca = LCA(root,a,b);
        
        int dis1 = distance(lca,a); 
        int dis2 = distance(lca,b);
        
        return  dis1 + dis2 - 2;
    }
};
