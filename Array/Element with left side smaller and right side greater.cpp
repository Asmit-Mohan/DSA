int findElement(int arr[], int n)
{
    int big=INT_MIN;
    int small=INT_MAX;
    int maxi[n];
    int mini[n];
    int ans=-1;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=big)
        {
            big=arr[i];
        }
        maxi[i]=big;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(small>=arr[i])
        {
            small=arr[i];
        }
        mini[i]=small;
    }
    for(int i=1;i<n-1;i++)
    {
            if(maxi[i]==mini[i])
            {
                ans=maxi[i];
                break;
            }
    }
    return ans;
}
