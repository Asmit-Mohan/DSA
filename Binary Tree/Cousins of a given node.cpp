class Solution
{
    public:
    vector<int> printCousins(Node* root, Node* find)
    {
       queue<pair<Node*,int>>q;
       q.push({root,-1});
       vector<int>ans;
       
       while(!q.empty())
       {
           int n=q.size();
           int flag=0;
           vector<pair<int,int>>v;
           while(n--)
           {
               Node* temp=q.front().first;
               int par=q.front().second;
               q.pop();
               
               v.push_back({temp->data,par});
               if(temp->data==find->data)
               {
                   flag=1;
               }
               if(temp->left)
               {
                   q.push({temp->left,temp->data});
               }
               if(temp->right)
               {
                   q.push({temp->right,temp->data});
               }
           }
           if(flag==1)
           {
               int par;
               for(int i=0;i<v.size();i++)
               {
                   if(v[i].first==find->data)
                   {
                       par=v[i].second;
                       break;
                   }
               }
               for(int i=0;i<v.size();i++)
               {
                   if(v[i].second!=par)
                   {
                       ans.push_back(v[i].first);
                   }
               }
           }
       }
       if(ans.size()==0)
       {
           ans.push_back(-1);
       }
       return ans;
    }
};
