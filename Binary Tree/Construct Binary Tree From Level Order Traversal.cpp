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

Node* solve(int arr[],int n)
{
	Node* root = new Node(arr[0]);
	queue<pair<Node*,int>>q;
	q.push({root,0});
	
	while(!q.empty())
	{
		Node* front = q.front().first;
		int i = q.front().second;
		q.pop();
		
		int leftIdx = (2*i)+1;
		int rightIdx = (2*i)+2;
		
		if(leftIdx<n&&arr[leftIdx]!=-1)
		{
			Node* temp = new Node(arr[leftIdx]);
			front->left=temp;
			q.push({front->left,leftIdx});
		}
		if(rightIdx<n&&arr[rightIdx]!=-1)
		{
			Node* temp = new Node(arr[rightIdx]);
			front->right=temp;
			q.push({front->right,rightIdx});
		}
	}
	return root;
}

int main()
{
    int arr[7] = {1,2,3,4,-1,6,7}; /* Level order traversal*/
    Node* root = solve(arr,7);
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
