/* Time :- O(nlogn) Space :- O(1) */

class Solution
{
    public:
    int solve(int h,int arr[],int n)
    {
    	int sum=0;
    	for(int i=0;i<n;i++)
    	{
    	    if(arr[i]>h)
    	    {
    		   sum=sum+(arr[i]-h);
    	    }
    	}
    	return sum;
    }

    int find_height(int arr[], int n, int m)
    {
        int low=0;
    	int high=*max_element(arr,arr+n);
     
    	while(low<=high)
    	{
    	     int mid=low+(high-low)/2;
    	     int temp=solve(mid,arr,n);
    	     if(temp==m)
    	     {
    		    return mid;
    	     }
    	     else if(temp>m)
    	     {
    		    low=mid+1;
    	     }
    	     else
    	     {
    		    high=mid-1;
    	     }
    	}
        return -1;
     }
};
