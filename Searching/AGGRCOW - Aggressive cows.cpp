class Solution
{
public:
    bool solve(int dist,vector<int>arr,int n,int cow)
    {
        int count=1;
        int lastPlaced=arr[0];
        for(int i=1;i<n;i++)
        {
            if(abs(arr[i]-lastPlaced)>=dist)
            {
                count++;
                lastPlaced=arr[i];
            }
        }
        return count>=cow?1:0;
    }
    
    int maxDistance(vector<int>& arr, int cow)
    {
        int n=arr.size();
        int ans=INT_MIN;
        sort(arr.begin(),arr.end());
        
	int low=1;
	int high=arr[n-1]-arr[0];
	while(low<=high)
	{
	   int mid=low+(high-low)/2;
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
       return ans;
    }
};
