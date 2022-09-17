/* Approach 1 :- N*(LOGN) Space :- O(1) */

class Solution
{
public:	

 int solve(int arr[], int n, int x)
 {
	    int low=0;
	    int high=n-1;
	    int mid=0;
	    
	    while(low<=high)
	    {
	        mid=low+(high-low)/2;
	        if(arr[mid]==x)
	        {
	            break;
	        }
	        else if(arr[mid]>x)
	        {
	            high=mid-1;
	        }
	        else 
	        {
	            low=mid+1;
	        }
	    }
	        low=mid;
	        high=mid;
	        while(arr[low]==x)
	        {
	            low--;
	        }
	        while(arr[high]==x)
	        {
	            high++;
	        }
	        return high-low-1;
   }
	
   int search(int A[], int N)
   {
	int res=-1;    
	if(N==1)
	{
	    return A[0];
	}
        else if(A[0]!=A[1])
        {
            return A[0];
        }
        else if(A[N-1]!=A[N-2])
        {
            return A[N-1];
        }
        else
        {
            for(int i=0;i<N;i++)
            {
                int ans=solve(A,N,A[i]);
                if(ans==1)
                {
                    res=A[i];
                    break;
                }
            }
        }
        return res;
   }
};

/* Efficient Approach :- Log(N) Space :- O(1) */

class Solution
{
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n = nums.size() ;
        int l = 0;
        int r = n-1 ;
        int ans;
        
        while(l<=r)
        {
            int mid = (l + r)/2 ;
            if(mid%2) 
            {
                mid--;                             
            }
            if(mid+1 < n && nums[mid] == nums[mid+1])       
            {
                l = mid+2;                                  
            }
            else                                            
            {
               r = mid-1;
               ans = nums[mid];
            }
        }
        return ans;
    }
};
