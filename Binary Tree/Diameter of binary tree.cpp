/* Approach 1 [Brute Force] Time :- O(N*N) Space :- O(N*H) */

class Solution
{
  public:
    int height(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=height(root->left);
        int r=height(root->right);
        return 1+max(l,r);
    }
    int diameter(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        int ans1=1+lh+rh;
        
        int ld=diameter(root->left);
        int rd=diameter(root->right);
        int ans2=max(ld,rd);
        
        int ans=max(ans1,ans2);
        
        return ans;
    }
};

/* Optimal Approach Time :- O(N) Space :- O(H) */

class Solution
{
  public:
    int height(Node* root,int &ans)
    {
        if(root==NULL)
        {
            return NULL;
        }
        int l=height(root->left,ans);
        int r=height(root->right,ans);
        
        ans=max(ans,1+l+r);
   
        return 1+max(l,r);
    }
    int diameter(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int ans=INT_MIN;
        height(root,ans);
        return ans;
    }
};
