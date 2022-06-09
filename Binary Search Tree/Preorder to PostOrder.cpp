Node* createBST(int arr[], int &i, int n, int maxRange)
{
        if(i==n||arr[i]>maxRange)
        {
            return NULL;
        }
        Node* root = newNode(arr[i++]);
        root->left  = createBST(arr,i,n,root->data);
        root->right = createBST(arr,i,n,maxRange);
        return root;
}

Node* post_order(int pre[], int n)
{
     int i=0;
     return createBST(pre,i,n,INT_MAX);   
}
