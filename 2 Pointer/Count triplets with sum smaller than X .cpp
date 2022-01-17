class Solution
{
	public:
	long long countTriplets(long long arr[], int n, long long x)
	{
	     sort(arr,arr+n);
	     long long count=0;
	     for(long i=0;i<n-2;i++)
	     {
    	         long long l=i+1;
    	         long long r=n-1;
    	         while(l<r)
    	         {
        	         if(arr[i]+arr[l]+arr[r]<x)
        	         {
        	             count=count+(r-l);
        	             l++;
        	         }
        	         else
        	         {
        	             r--;
        	         }
    	         }
	     }
	     return count;
	}
};
