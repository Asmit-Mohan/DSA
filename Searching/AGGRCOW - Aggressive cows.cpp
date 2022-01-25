#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool solve(ll dist,ll arr[],ll n,ll cow)
{
	ll count=1;
	ll lastPlaced=arr[0];
	for(ll i=1;i<n;i++)
	{
		if(arr[i]-lastPlaced>=dist)
		{
			count++;
			lastPlaced=arr[i];
		}
	}
	return count>=cow?1:0;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,c;
	    ll ans=INT_MIN;
	    cin>>n>>c;
	    ll arr[n];
	    for(ll i=0;i<n;i++)
	    {
	    	cin>>arr[i];
	    }
	    sort(arr,arr+n);
	    ll low=arr[0];
	    ll high=arr[n-1]-arr[0];
	    while(low<=high)
	    {
	    	ll mid=low+(high-low)/2;
	    	if(solve(mid,arr,n,c))
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
	}
	return 0;
}
