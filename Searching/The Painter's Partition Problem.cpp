class Solution
{
   public:
   int isvalid(int arr[],int n,int k,int mid)
    {
        int curr=1;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
            if(sum>mid)
            {
                curr++;
                sum=arr[i];
            }
            if(curr>k)
            {
               return 0;
            }
        }
        return 1;
    }
    long long minTime(int arr[], int n, int k)
    {
         if(n>=k)
         {
             long long l=*max_element(arr,arr+n);
             long long r=0;
             for(int i=0;i<n;i++)
             {
                 r=r+arr[i];
             }
             long long res=-1;
             while(l<=r)
             {
                 int mid=l+((r-l)/2);
                 if(isvalid(arr,n,k,mid))
                 {
                     res=mid;
                     r=mid-1; // To find more optimised solution
                 }
                 else
                 {
                     l=mid+1;
                 }
             }
             return res;
         }
         else
         {
            return *max_element(arr,arr+n);
         }
    }
};
