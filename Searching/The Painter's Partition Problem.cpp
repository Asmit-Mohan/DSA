/* Time :- O(Nlogm) Space :- O(1) */

class Solution
{
   public:
   int isvalid(int arr[],int n,int painterAvailable,int maximumArea)
    {
        int reqPainter=1;
        long long currArea=0;
        
        for(int i=0;i<n;i++)
        {
            currArea=currArea+arr[i];
            if(currArea>maximumArea)
            {
                reqPainter++;
                currArea=arr[i];
            }
            if(reqPainter>painterAvailable)
            {
               return 0;
            }
        }
        return 1;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        if(k>n)
        {
           return *max_element(arr,arr+n);
        }
        
        long long r=0;
        for(int i=0;i<n;i++)
        {
            r=r+arr[i];
        }
        
        long long res=-1;
        long long l=*max_element(arr,arr+n);
        
        while(l<=r)
        {
            int mid=l+((r-l)/2);
            if(isvalid(arr,n,k,mid))
            {
                res=mid;
                r=mid-1; 
            }
            else
            {
                l=mid+1;
            }
        }
        return res;
    }
};
