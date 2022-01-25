#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll solve(ll h,ll arr[],ll n)
{
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		if(arr[i]>=h)
		{
			sum=sum+(arr[i]-h);
		}
	}
	return sum;
}
int main()
{
	ll n,m;
	cin>>n>>m;
	ll arr[n];
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	ll low=0;
	ll high=*max_element(arr,arr+n);
	ll ans=INT_MIN;
	
	while(low<=high)
	{
		ll mid=low+(high-low)/2;
		ll temp=solve(mid,arr,n);
		if(temp==m)
		{
			ans=mid;
			break;
		}
		else if(temp>m)
		{
			ans=max(ans,mid);
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
