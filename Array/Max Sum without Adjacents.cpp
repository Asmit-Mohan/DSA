class Solution
{
public:	
	int findMaxSum(int *arr, int n)
	{
	    arr[1]=max(arr[0],arr[1]);
	    for(int i=2;i<n;i++)
	    {
	        arr[i]=max(arr[i-1],arr[i-2]+arr[i]);
	    }
	    return arr[n-1];
	}
};