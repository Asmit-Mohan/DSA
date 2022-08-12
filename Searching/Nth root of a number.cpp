/* Time :- O(Nlogm) Space :- O(1) */

class Solution
{
	public:
	int solve(int n,int x,int target)  /* O(N) */
	{
	   unsigned long long ans=1;
	   while(n--)
	   {
	       ans=ans*x;
	       if(ans>target)
	       {
	           return -1;
	       }
	   }
	   return (int)ans;
	}
	
	int NthRoot(int n, int m)
	{
	    if(n==1)
	    {
	        return m;
	    }
	    if(m==1)
	    {
	        return 1;
	    }
	    
            int low=0;
            int high=m/2;
        
            while(low<=high)             /* O(logm) */
            {
		 int mid=low+(high-low)/2;
		 int ans=solve(n,mid,m);
		 if(ans==m)
		 {
		     return mid;
		 }
		 else if(ans==-1)
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
