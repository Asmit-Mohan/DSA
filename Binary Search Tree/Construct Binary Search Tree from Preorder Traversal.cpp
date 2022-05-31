class Solution
{
public:
TreeNode* solve(vector<int>in,int inStart,int inEnd,vector<int> pre,int preStart,int preEnd,map<int,int> &mp)
    {
        if(inStart>inEnd || preStart>preEnd)
        {
            return NULL;
        }
        
        TreeNode* temp = new TreeNode(pre[preStart]);
        
        int inRootIdx = mp[temp->val];
        int numsLeftSide = inRootIdx - inStart;
        
        temp->left=solve(in, inStart, inRootIdx-1, pre, preStart+1, preStart+numsLeftSide, mp);
        temp->right=solve(in, inRootIdx+1, inEnd, pre, preStart+numsLeftSide+1, preEnd, mp);
        
        return temp;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        vector<int>inorder;
        inorder=preorder;
        sort(inorder.begin(),inorder.end());
        map<int,int>mp;
        int n=preorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        return solve(inorder, 0, n-1, preorder, 0, n-1, mp);
    }
};
