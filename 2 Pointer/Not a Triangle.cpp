/* Good Approach because SPOJ accepted and simple as well as small */

/* Approach :- Total Number of selection of three lines out of given n lines - Total number of valid triangles */

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
