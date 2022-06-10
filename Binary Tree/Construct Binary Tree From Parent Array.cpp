class Solution
{
public:
    Node *createTree(int parent[], int n)
    {
        unordered_map<int,Node*>mp;
        for(int i=0;i<n;i++)
        {
            Node* temp = new Node(i);
            mp[i]=temp;
        }
        
        Node* root = NULL;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
            {
                root = mp[i];   
            }
            else
            {
                if(mp[parent[i]]->left==NULL)
                {
                    mp[parent[i]]->left=mp[i];
                }
                else
                {
                    mp[parent[i]]->right=mp[i];
                }
            }
        }
        return root;
    }
};
