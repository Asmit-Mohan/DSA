class Solution
{
    public:
    
    void dfs(Node* root,Node* ans, vector<Node*>&vis)
    {
        vis[ans->val] = ans;
        for(auto it : root->neighbors)
        {
            if(vis[it->val]==NULL)
            {
                Node* newNode = new Node(it->val);
                (ans->neighbors).push_back(newNode);
                dfs(it,newNode,vis);
            }
            else
            {
                (ans->neighbors).push_back(vis[it->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node)
    {
        if(node==NULL)
        {
           return NULL;
        }
        vector<Node*>vis(1000,NULL);
        Node* ans=new Node(node->val);
        dfs(node,ans,vis);
        return ans;
    }
};
