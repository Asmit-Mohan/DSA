int maxSubarraySum(int arr[], int n)
    {
        int pre=INT_MIN;
        int post=0;
        for(int i=0;i<n;i++)
        {
            post=post+arr[i];
            if(post<arr[i])
            {
                post=arr[i];
            }
            if(pre<post)
            {
                pre=post;
            }
        }
        return pre; 
    }