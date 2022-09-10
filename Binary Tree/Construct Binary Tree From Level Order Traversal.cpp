#include <bits/stdc++.h>
using namespace std;

class Node
{
   public:
      int data;
      Node *left, *right;
      Node(int value)
      {
         data = value;
         left = NULL;
         right = NULL;
      }
};

void preorder(Node* root,vector<int>&ans)
{
	if(root!=NULL)
	{
		ans.push_back(root->data);
		preorder(root->left,ans);
		preorder(root->right,ans);
	}
}

void inorder(Node* root,vector<int>&ans)
{
	if(root!=NULL)
	{
		inorder(root->left,ans);
		ans.push_back(root->data);
		inorder(root->right,ans);
	}
}

void postorder(Node* root,vector<int>&ans)
{
	if(root!=NULL)
	{
		postorder(root->left,ans);
		postorder(root->right,ans);
		ans.push_back(root->data);
	}
}

Node* solve(string arr[],int n)
{
	int i=0;
	Node* root = new Node(stoi(arr[i++]));
	queue<Node*>q;
	q.push(root);
 
	while(!q.empty())
	{
		Node* front = q.front();
		q.pop();
 
		if(i<n)
		{
			if(arr[i]=="#")
			{
				front->left=NULL;
			}
			else
			{
				Node* temp = new Node(stoi(arr[i]));
				front->left=temp;
				q.push(front->left);
			}
			i++;
		}
		if(i<n)
		{
			if(arr[i]=="#")
			{
				front->right=NULL;
			}
			else
			{
				Node* temp = new Node(stoi(arr[i]));
				front->right=temp;
				q.push(front->right);
			}
			i++;
		}
	}
	return root;
}
int main()
{
    string levelOrder[13] = {{"1"},{"2"},{"3"},{"4"},{"#"},{"6"},{"7"},{"#"},{"8"},{"9"},{"#"},{"#"},{"10"}};
    Node* root = solve(levelOrder,13);
    vector<int>ans;
    
    preorder(root,ans);
    cout<<"Preorder Traversal of Binary Tree :- "<<endl;
    for(int i=0;i<ans.size();i++)
    {
    	cout<<ans[i]<<" ";
    }
    ans.clear();
    cout<<endl;
    
    inorder(root,ans);
    cout<<"Inorder Traversal of Binary Tree :- "<<endl;
    for(int i=0;i<ans.size();i++)
    {
    	cout<<ans[i]<<" ";
    }
    ans.clear();
    cout<<endl;
    
    postorder(root,ans);
    cout<<"Postorder Traversal of Binary Tree :- "<<endl;
    for(int i=0;i<ans.size();i++)
    {
    	cout<<ans[i]<<" ";
    }
    return 0;
}
