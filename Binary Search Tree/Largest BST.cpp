class Solution
{
    public:
    
    bool isLarge(Node* root,int val)
    {
        if(root==NULL)
        {
            return 1;
        }
        if(root->data>val&&isLarge(root->left,val)&&isLarge(root->right,val))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
 
    bool isSmall(Node* root,int val)
    {
        if(root==NULL)
        {
            return 1;
        }
        if(root->data<val&&isSmall(root->left,val)&&isSmall(root->right,val))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
 
    bool isBST(Node* root) 
    {
         if(root==NULL)
         {
             return 1;
         }
 
         int temp1=isSmall(root->left,root->data);
         int temp2=isLarge(root->right,root->data);
         int temp3=isBST(root->left);
         int temp4=isBST(root->right);
 
         if(temp1&&temp2&&temp3&&temp4)
         {
             return 1;
         }
         else
         {
             return 0;
         }
    }
    
    void countNode(Node* root,int &count)
    {
        if(root!=NULL)
        {
            countNode(root->left,count);
            count++;
            countNode(root->right,count);
        }
    }
    
    int largestBst(Node *root)
    {
        int ans=INT_MIN;
        int count=0;
        
    	if(root==NULL)
    	{
    	    return ans;
    	}
    	if(isBST(root))
    	{
    	    countNode(root,count);
    	    ans=max(ans,count);
    	    return ans;
    	}
    	int temp1=largestBst(root->left);
    	int temp2=largestBst(root->right);
    	return max(temp1,temp2);
    }
};
