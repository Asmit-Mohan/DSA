class Solution
{
public:
    int ans=0;
    int cam=1;
    int nocam=2;
    int noneed=0;
    
    int solve(TreeNode* root)
    {
        if(root == NULL)
        {
            return noneed;    
        }
        
        int left =  solve(root->left);
        int right = solve(root->right);
        
        if(left==nocam || right==nocam)
        {
            ans++ ;
            return cam;
        }
        
        if(left==cam || right==cam)
        {
            return noneed;
        }
        
        return nocam;
    }
    
    int minCameraCover(TreeNode* root)
    {    
        if(solve(root)==nocam)
        {
            ans++;
        }
        return ans;
    }
};
