/* Time :- O(N) Space :- O(N) */

class Solution
{
    public:
    vector <int> bottomView(Node *root)  
    {
        map<int,int>mp;
        vector<int>ans;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty())
        {
            Node* temp=q.front().first;
            int placeValue=q.front().second;
            q.pop();
            mp[placeValue]=temp->data;
            if(temp->left)
            {
                q.push({temp->left,placeValue-1});
            }
            if(temp->right)
            {
                q.push({temp->right,placeValue+1});
            }
        }
        for(auto x : mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
