class Solution
{
  public:
    int getMinDiff(int arr[], int n, int k)
    {
       sort(arr, arr+n);
       int ans=arr[n-1]-arr[0];
       int small=arr[0]+k;
       int large=arr[n-1]-k;
       int mn, mx;
       for(int i=0; i<n-1; i++)
       {
           mn=min(small, arr[i+1]-k);
           mx=max(large, arr[i]+k);
           if(mn<0)
           continue;
           else
           ans=min(ans, mx-mn);
       }
       return ans;
    }
};
