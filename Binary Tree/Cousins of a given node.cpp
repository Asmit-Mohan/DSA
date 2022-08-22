/* Time :- O(N) Space :- O(N) */

class Solution
{
public:
vector<int> printCousins(Node* root, Node* find)
{
    queue<Node*>q;
    int flag=0;
    q.push(root);
    
    while(q.size())
    {
        int width=q.size();
        vector<int>res;
        while(width--)
        {
            Node *temp=q.front();
            q.pop();
            if(temp->left==find or temp->right==find)
            {
                flag=1;
            }
            else
            {
                if(temp->left)
                {
                    res.push_back(temp->left->data);
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    res.push_back(temp->right->data);
                    q.push(temp->right);
                }
            }
        }
        if(flag==1)
        {
            if(res.size()==0)
            {
                return {-1};
            }
            return res;
        }
     } 
    return {-1};
  }
};
