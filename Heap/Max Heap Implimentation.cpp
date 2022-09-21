#include <bits/stdc++.h>
using namespace std;

class maxheap
{
	private:
		vector<int>node;
	public:
		maxheap()
		{
			node.push_back(-1);
		}
		
		void push(int data)
		{
			int n=node.size();
			node.push_back(data);
			
			int i=n;
			while(i>1)
			{
				int parent = i/2;
				if(node[parent] < node[i])
				{
					swap(node[parent],node[i]);
					i=parent;
				}
				else break;
			}
			
		}
		
		int top()
		{
			if(node.size()<2)
			return -1;
			
			return node[1];
		}
		
		void pop()
		{
			int n=node.size();
			if(n==1)
			return ;
			
			int ans= node[1];
			node[1]=node[n-1];
			node.pop_back();
			int i=1;
			
			while(i<n-1)
			{
				int left_child = 2*i;
				int right_child = 2*i + 1;
				int largest = node[left_child] > node[right_child] ? left_child : right_child;
				
				if(node[largest] > node[i])
				{
					swap(node[largest],node[i]);
					i=largest;
				}
				else 
				{
					break;
				}
			}
			
		}
	
	
};
int main()
{
	maxheap mx;
	mx.push(10);
	mx.push(20);
	mx.push(30);
	mx.push(3);
	cout<<mx.top()<<" ";
	mx.pop();
	cout<<mx.top()<<" ";
	mx.pop();
	cout<<mx.top()<<" ";
	mx.pop();
	cout<<mx.top()<<" ";
	mx.pop();
	cout<<mx.top();
	return 0;
}
