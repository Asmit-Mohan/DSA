
/* Approach 1 */

class Solution
{
public:
Node * inOrderSuccessor(Node *root, Node *x)
{
Node *prev = NULL;
Node *cur = root;
while(cur!=NULL)
{
		if(cur->data > x->data)
		{
			prev = cur;
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
}
return prev;
}
};

/* Approach 2 */

class Solution
{
public:
int flag=1;

void solve(Node* root,Node* &ans,Node* target)
{
    if(root!=NULL)
    {
        solve(root->left,ans,target);
        if(flag==0)
        {
            ans=root;
            flag=1;
            return;
        }
        if(root->data==target->data)
        {
            flag=0;
        }
        solve(root->right,ans,target);
    }
}

Node * inOrderSuccessor(Node *root, Node *x)
{
    Node* ans=NULL;
    solve(root,ans,x);
    return ans;
}
