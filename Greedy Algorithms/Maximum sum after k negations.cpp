class Solution
{
    public:
    long long int maximizeSum(long long int arr[], int n, int k)
    {
    sort(arr,arr+n);
    long long  sum=0;
    long long count=0;
    
    for(int i=0;i<n;i++)
    {
       if(arr[i]<0&&k>0)
       {
           arr[i]=-arr[i];
           k--;
       }
       
    }
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    
    long long mn=*min_element(arr,arr+n);
   
       if(k%2==1)
       {
           sum-=2*mn;
       }
       return sum;
    }
};
