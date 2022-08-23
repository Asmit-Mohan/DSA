/* Time :- O(N) Space :- O(N) */

void solve(Node *root,int &sum)
{
    if(root!=NULL)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            sum+=root->data;
        }
        solve(root->left,sum);
        solve(root->right,sum);
    }
}

int sumOfLeafNodes(Node *r )
{
     int sum=0;
     solve(r,sum);
     return sum;
}
