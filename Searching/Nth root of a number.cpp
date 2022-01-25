class Solution
{
	public:
	int solve(int mid, int n, int m)
	{
	    unsigned long long ans = 1;
	    while(n--)
	    {
	        ans = ans*mid;
	        if (ans > m)
	        {
	            return m+2;
	        }
	    }
	    return (int)ans;
	}
	
	int NthRoot(int n, int target)
	{
	    if(target==1||n==1)
	    {
	        return target;
	    }
	    int low=0;
	    int high=target/2;
	    
	    while(low<=high)
	    {
	        int mid=low+(high-low)/2;
	        int res=solve(mid,n,target);
	       
	        if(res==target)
	        {
	            return mid;
	        }
	        else if(res>target)
	        {
	            high=mid-1;
	        }
	        else
	        {
	            low=mid+1;
	        }
	    }
	    return -1;
	 }  
};
