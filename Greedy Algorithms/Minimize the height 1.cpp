class Solution
{   
public:
    int getMinDiff(int arr[], int n, int k)
    {
        if(n==1)
        {
           return 0;
        } 
        sort(arr,arr+n);
        int diff = arr[n-1] - arr[0];
        int minimum;
        int maximum;
        for(int i=1;i<n;i++)
        {
           maximum = max(arr[i-1]+k, arr[n-1]-k);
           minimum = min(arr[0]+k, arr[i]-k);
           diff = min(diff,maximum-minimum);
        }
        return diff;
    }
};
