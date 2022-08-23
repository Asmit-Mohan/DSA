/* Time :- O(N) Space :- O(N) */

Node* solve(int in[],int inStart,int inEnd,int post[],int postStart,int postEnd,map<int,int> &mp)
{
        if(inStart>inEnd || postStart>postEnd)
        {
            return NULL;
        }
 
        Node* temp = new Node(post[postEnd]);
 
        int inRootIdx = mp[temp->data];
        int numsLeft = inRootIdx-inStart;
 
        temp->left=solve(in, inStart, inRootIdx-1, post, postStart, postStart+numsLeft-1, mp);
        temp->right=solve(in, inRootIdx+1, inEnd, post, postStart+numsLeft, postEnd-1, mp);
 
        return temp;
}
    
Node *buildTree(int in[], int post[], int n)
{
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }
        return solve(in, 0, n-1, post, 0, n-1, mp);    
}
