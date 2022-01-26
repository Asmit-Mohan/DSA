vector<int> reverseLevelOrder(Node *root)
{
        queue<Node*>q;
        vector<int>v;
        q.push(root);
        while(q.size())
        {
            Node* temp=q.front();
            v.push_back(temp->data);
            q.pop();
            if(temp->right)
            {
                q.push(temp->right);
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
        }
        reverse(v.begin(),v.end());
        return v;
}
