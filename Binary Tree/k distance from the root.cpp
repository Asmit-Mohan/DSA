/* Leetcode Question Iterative --> Striver || Time :- O(N) Space :- O(N) */

class Solution
{
public:
    void solve(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&mp)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left)
            {
                mp[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                mp[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
       vector<int>ans;
       unordered_map<TreeNode*,TreeNode*>parent;
       solve(root,parent);                               
        
       unordered_map<TreeNode*,bool>visited;
       queue<TreeNode*>q;
       int curr_level=0;
        
       q.push(target);
       visited[target]=true;
        
       while(!q.empty())
       {
           int size=q.size();
           if(curr_level==k)
           {
               break;
           }
           else
           {
               curr_level++;
           }
           while(size--)
           {
               TreeNode* front=q.front();
               q.pop();
               if(front->left&&!visited[front->left])
               {
                   q.push(front->left);
                   visited[front->left]=true;
               }
               if(front->right&&!visited[front->right])
               {
                   q.push(front->right);
                   visited[front->right]=true;
               }
               if(parent[front]&&!visited[parent[front]])
               {
                   q.push(parent[front]);
                   visited[parent[front]]=true;
               }
           }
       }
       while(!q.empty())
       {
           ans.push_back(q.front()->val);
           q.pop();
       }
       return ans; 
    }
};

/* GFG Question Recursive */

void kdistance(struct Node *root, int k,vector<int>& v)
{
    if(k==0)
    {
        v.push_back(root->data);
        return;
    }
    if(root->left)
    {
        kdistance(root->left,k-1,v);
    }
    if(root->right)
    {
        kdistance(root->right,k-1,v);
    }
}
vector<int> Kdistance(struct Node *root, int k)
{
   vector<int> vec;
   kdistance(root,k,vec);
   return vec;
}

/* GFG Question Iterative */

vector<int> Kdistance(struct Node *root, int k)
{
       vector<int>ans;
       if(root==NULL)
       {
          return ans; 
       }
       if(k==0)
       {
           ans.push_back(root->data);
           return ans;
       }
       queue<Node*>q;
       q.push(root);

       while(!q.empty())
       {
           int n=q.size();
           while(n--)
           {
               Node* temp=q.front();
               q.pop();
               if(k==0)
               {
                    ans.push_back(temp->data);
               }
               if(temp->left)
               {
                   q.push(temp->left);
               }
               if(temp->right)
               {
                   q.push(temp->right);
               }
           }
           k--;
           if(k==-1)
           {
               break;
           }
       }
       return ans;
}
