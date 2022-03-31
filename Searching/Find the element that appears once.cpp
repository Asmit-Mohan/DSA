/* Approach 1 N*(LOGN) */

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

/* Efficient Approach :- Log(N) */

class Solution
{
public:	
	int search(int A[], int N)
	{
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
              int l=0;
              int r=N-1;
              while(l<=r)
              {
                  int mid=l+(r-l)/2;
                  if(A[mid]!=A[mid+1]&&A[mid]!=A[mid-1])    /*if not equal to its neighbour then it is answer*/
                  {
                      return A[mid];
                  }
                  else if(A[mid]==A[mid-1]) 
                  {
                      int lcount=mid-l+1;
                      if(lcount%2==0)
                      {
                          l=mid+1;
                      }
                      else
                      {
                          r=mid-2;      /*because mid and mid-1 are same*/
                      }
                  }
                  else if(A[mid]==A[mid+1])
                  {
                      int rcount=r-mid+1;
                      if(rcount%2==0)
                      {
                          r=mid-1;
                      }
                      else
                      {
                          l=mid+2;      /*because mid and mid+1 are same*/
                      }
                  }
              }
          }
     }
};
