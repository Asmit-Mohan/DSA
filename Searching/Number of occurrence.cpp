/* Approach 1 --> Using Hashmap to count the frequency --> Time :- O(N) Space :- O(N) */

/* Approach 2 --> Using Binary Search Time :- O(logn) Space :- O(1) */

class Solution
{
public:	
	int count(int arr[], int n, int x)
	{
	    int low=0;
	    int high=n-1;
	    int flag=0;
	    int mid=0;
	    
	    while(low<=high)
	    {
	        mid=low+(high-low)/2;
	        if(arr[mid]==x)
	        {
	            flag=1;
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
	    if(flag==0)
	    {
	        return 0;
	    }
	    else
	    {
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
       }
  };
