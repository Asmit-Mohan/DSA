/* Naive Approach Only Time Efficient */

class Solution
{
    public:
    void inorder(Node* root,set<int>&s)
    {
        if(root!=NULL)
        {
            inorder(root->left,s);
            s.insert(root->data);
            inorder(root->right,s);
        }
    }
    
    void solve(Node* root,set<int>&s,vector<int>&ans)
    {
        if(root!=NULL)
        {
            solve(root->left,s,ans);
            if(s.find(root->data)!=s.end())
            {
                ans.push_back(root->data);   
            }
            solve(root->right,s,ans);
        }
    }
    
    vector <int> findCommon(Node *root1, Node *root2)
    {
        set<int>s;
        vector<int>v;
        inorder(root1,s);
        solve(root2,s,v);
        sort(v.begin(),v.end());
        return v;
    }
};

/*Efficient Approach*/

class Solution
{
    public:
    vector <int> findCommon(Node *root1, Node *root2)
    {
    stack<Node*>s1, s2;
    vector<int>v;
    while (1)
    {
        if (root1)
        {
            s1.push(root1);
            root1 = root1->left;
        }
        else if (root2)
        {
            s2.push(root2);
            root2 = root2->left;
        }
        else if (!s1.empty() && !s2.empty())
        {
            root1 = s1.top();
            root2 = s2.top();
            if (root1->data == root2->data)
            {
                v.push_back(root1->data);
                s1.pop();
                s2.pop();
                root1 = root1->right;
                root2 = root2->right;
            }
  
            else if (root1->data < root2->data)
            {
                s1.pop();
                root1 = root1->right;
                root2 = NULL;
            }
            else if (root1->data > root2->data)
            {
                s2.pop();
                root2 = root2->right;
                root1 = NULL;
            }
        }
        else
        {
            break;
        }
      }
      return v;
    }
};
