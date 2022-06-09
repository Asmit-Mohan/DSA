class Solution
{
public:
   int ans=INT_MIN;
   
   int solve(Node* root)
   {
       if(root->left==NULL&&root->right==NULL)
       {
           return root->data;
       }
       if(root->right==NULL)
       {
           return root->data + solve(root->left);
       }
       if(root->left==NULL)
       {
           return root->data + solve(root->right);
       }
       
       int lSum = solve(root->left);
       int rSum = solve(root->right);
       int temp = lSum + rSum + root->data;
       ans=max(ans,temp);
       
       return root->data+max(lSum,rSum);
   }
   
   int maxPathSum(Node* root)
   {      
        int res=solve(root);
        if(root->left&&root->right)
        {
           return ans;
        }
        return max(res,ans);
   }
};
