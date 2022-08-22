/* Time :- O(N) Space :- O(N) */

class Solution
{
public:
    int widthOfBinaryTree(TreeNode* root)
    {
       queue<pair<TreeNode*,long long>>q;
       q.push({root,0});
       unsigned int ans=0;
        
       while(!q.empty())
       {
           int n=q.size();
           unsigned int l=q.front().second;
           unsigned int r;
           
           while(n--)
           {
               TreeNode* temp=q.front().first;
               r=q.front().second;
               q.pop();
               
               if(temp->left)
               {
                   q.push({temp->left,(2*r)+1});
               }
               if(temp->right)
               {
                   q.push({temp->right,(2*r)+2});
               }
           }
           ans=max(ans,r-l+1);
       }
       return ans;
    }
};
