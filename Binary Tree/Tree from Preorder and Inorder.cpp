class Solution  /*Strivers Tree Series*/
{
    public:
    
    Node* solve(int in[],int inStart,int inEnd,int pre[],int preStart,int preEnd,map<int,int> &mp)
    {
        if(inStart>inEnd || preStart>preEnd)
        {
            return NULL;
        }
        
        Node* temp = new Node(pre[preStart]);
        
        int inRootIdx = mp[temp->data];
        int numsLeftSide = inRootIdx - inStart;
        
        temp->left=solve(in, inStart, inRootIdx-1, pre, preStart+1, preStart+numsLeftSide, mp);
        temp->right=solve(in, inRootIdx+1, inEnd, pre, preStart+numsLeftSide+1, preEnd, mp);
        
        return temp;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
         map<int,int>mp;
         for(int i=0;i<n;i++)
         {
             mp[in[i]]=i;
         }
         return solve(in, 0, n-1, pre, 0, n-1, mp);
    }
};
