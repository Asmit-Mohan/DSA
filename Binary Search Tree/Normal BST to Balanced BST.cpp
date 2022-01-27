void inorder(Node *root, vector<int> &arr)
{
    if(root != NULL)
    {
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
}

Node *createBST(vector<int> arr, int l, int r) //It means if we make bst from sorted array it will be balanced. 
{
    if(l > r)
    {
        return NULL;
    }
    int mid = l + (r - l)/2;
    Node *root = new Node(arr[mid]);
    root->left = createBST(arr, l, mid-1);
    root->right = createBST(arr, mid+1, r); 
    return root;
}

Node* buildBalancedTree(Node* root)
{
	vector<int> arr;
	inorder(root, arr);
	return createBST(arr, 0, arr.size()-1);
}
