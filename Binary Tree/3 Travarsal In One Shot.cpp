class Solution
{
   vector<int>PreInPost(TreeNode* root)
   {
       stack<pair<TreeNode*,int>>s;
       vector<int>Inorder,PostOrder,Preorder;
       s.push({root,1});
       
       if(root==NULL)
       {
           return;
       }
       while(!s.empty())
       {
          auto it = s.top();
          s.pop();
          
          if(it.second==1)
          {
            Preorder.push_back(it.first->val);
            it.second++;
            s.push(it);
            if(it.first->left!=NULL)
            {
                s.push({it.first->left,1});
            }
          }
          else if(it.second==2)
          {
            Inorder.push_back(it.first->val);
            it.second++;
            s.push(it);
            if(it.first->right!=NULL)
            {
                s.push({it.first->right,1});
            } 
          }
          else
          {
            PostOrder.push_back(it.first->val);  
          }
       }
    }
};
