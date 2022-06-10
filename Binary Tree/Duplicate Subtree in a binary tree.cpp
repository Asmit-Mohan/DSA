class Solution
{
    public:
    string solve(Node* root,unordered_map<string,int>&mp)
    {
        if(root==NULL)
        {
            return "#";
        }
        
        string ans="";
        
        if(root->left==NULL&&root->right==NULL)
        {
            ans = to_string(root->data);
            return ans;
        }
        
        ans+=to_string(root->data);
        ans+=solve(root->left,mp);
        ans+=solve(root->right,mp);
        
        mp[ans]++;
        return ans;
    }
    
    int dupSub(Node *root)
    {
       unordered_map<string,int>mp;
       solve(root,mp);
       for(auto x : mp)
       {
           if(x.second>1)
           {
               return 1;
           }
       }
       return 0;
    }
};
