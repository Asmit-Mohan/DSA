/* Two Pointer Approach  */

Approach :- Total Number of selection of three lines out of given n lines - Total number of valid triangles 

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int total(int n,int r)
{
       long long int up=1;
       long long int down=1;
        
       if(r==0||r==n)
       {
           return 1;
       }
       if(r==1||r==n-1)
       {
           return n;
       }
       r=min(r,n-r);
       
       for(int i=1;i<=r;i++)
       {
           up=up*(n-r+i);
           down=down*i;
       }
       return up/down;
}

int solve(ll nums[],int n)
{
	int ans=0;
        sort(nums,nums+n);
 
        if(n==3)
        {
            if(nums[0]+nums[1]>=nums[2])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        for(int i=2;i<n;i++)
        {
            int l=0;
            int r=i-1;
            while(l<r)
            {
                if(nums[l]+nums[r]>=nums[i])
                {
                    ans=ans+(r-l);
                    r--;
                }
                else
                {
                    l++;   
                }
            }
        }
        return ans;
}

int main()
{
	while(1)
	{
		int n;
		cin>>n;
		if(n==0)
		{
			break;
		}
		else
		{
			ll arr[n];
			for(int i=0;i<n;i++)
			{
				cin>>arr[i];
			}
			cout<<total(n,3)-solve(arr,n)<<endl;
		}
	}
	return 0;
}

/* Approach Binary Search */

#include<bits/stdc++.h>
using namespace std;
#define MAX 2001
int low;
int high;
int n;

int solve(int num,int arr[],int size)
{
	if(low==high && arr[low]<=num)
	{
		return 0;
	}
	while(low<high)
	{
		int mid=low+(high-low)/2;
		
		if(arr[mid]>num)
		{
			high=mid;
		}
		if(arr[mid]<=num)
		{
			low=mid+1;
		}
		if(low==size-1 && arr[low]<= num)
		{
			return 0;
		}
	}
   	return size-low;	
}

int main()
{
	while(cin>>n && n!=0)
	{
	int count=0;
	int arr[MAX];
	
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		
		for(int i=0;i<=n-3;i++)
		{
			for(int j=i+1;j<=n-2;j++)
			{
				low=j+1;
				high=n-1;
				int temp=solve(arr[i]+arr[j],arr,n);
				count=count+temp;
			}
		}
		cout<<count<<endl;
        }
   return 0;
}
