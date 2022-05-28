/* Approach 1 Recursion + Memo */

#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
int dp[101][101];

int maxi(int a,int b,int c)
{
	return(a>b?(a>c?a:c):(b>c?b:c));
}

int solve(int i,int j,int n,int m)
{
	if(i<0||i>=n||j<0||j>=m)
	{
		return 0;
	}
	
	if(dp[i][j])
	{
		return dp[i][j];
	}
	
	return dp[i][j] = arr[i][j]+maxi(solve(i+1,j-1,n,m),solve(i+1,j,n,m),solve(i+1,j+1,n,m));
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int i;
		int j;
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
			    dp[i][j]=0;
			}
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>arr[i][j];
			}
		}
		
		int ans=0;
		
		for(i=0;i<m;i++)
		{
			int temp=solve(0,i,n,m);
			ans=max(ans,temp);
		}
		cout<<ans<<endl;
	}
	return 0;
}

/* Approach 2 DP */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		int dp[101][101] = {0};
		cin>>n>>m;

		for(int i=1;i<=n;i++)
		{
		    for(int j=1;j<=m;j++)
			{
			    cin>>dp[i][j];
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dp[i][j] += max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
			}
		}
		
		int ans = 0;
		for(int i=1;i<=m;i++)
		{
			ans=max(ans,dp[n][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
