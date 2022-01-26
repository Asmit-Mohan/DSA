class Solution
{
    public:
    vector<int> rightView(Node *root)
    {
        vector<int> v;
        if(root==NULL) 
        {
           return v;
        }
        else
        {
         queue<Node*>q;
         q.push(root);
         while(q.size())
         {
             int size=q.size();
             int res;
             while(size--)
             {
                 Node* temp=q.front();
                 res=temp->data;
                 q.pop();
                 if(temp->left)
                 {
                     q.push(temp->left);
                 }
                 if(temp->right)
                 {
                     q.push(temp->right);
                 }
             }
             v.push_back(res);
         }
         return v;
        }
    }
};
