/* Approach 1 (Brute Force) Time :- O(n*m) Space :- O(1) */

class Solution
{
    public:
    int solve(vector<int>v,int m)
    {
        int count=0;
        for(int i=0;i<m;i++)
        {
            if(v[i]==1)
            {
                count++;
            }
        }
        return count;
    }
    int maxOnes (vector<vector<int>> &arr, int N, int M)
    {
        int ans=-1;
        int res=-1;
        for(int i=0;i<N;i++)
        {
            int temp=solve(arr[i],M);
            if(temp>ans)
            {
                ans=temp;
                res=i;
            }
        }
        return res;
    }
};

/* Approach 2 (Binary Search) Time :- O(N*Logm) Space :- O(1) */

class Solution
{
    public:
    int solve(vector<int>arr,int m) /*Number of occurrence Approach*/
    {
        int low=0;
	    int high=m-1;
	    int flag=0;
	    int mid=0;
	    
	    while(low<=high)
	    {
	        mid=low+(high-low)/2;
	        if(arr[mid]==1)
	        {
	            flag=1;
	            break;
	        }
	        else if(arr[mid]>1)
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
	        while(arr[low]==1)
	        {
	            low--;
	        }
	        while(arr[high]==1)
	        {
	            high++;
	        }
	        return high-low-1;
	    }
    }
    
    int maxOnes (vector<vector<int>> &arr, int N, int M)
    {
        int ans=-1;
        int res=-1;
        for(int i=0;i<N;i++)
        {
            int temp=solve(arr[i],M);
            if(temp>ans)
            {
                ans=temp;
                res=i;
            }
        }
        return res;
    }
};
