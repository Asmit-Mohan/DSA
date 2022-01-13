class Solution
{
public:
	void pushZerosToEnd(int arr[], int n)
	{
	    int i=0;
	    int j=0;
	    while(j<n)
	    {
	        if(arr[j]!=0)
	        {
	            swap(arr[i],arr[j]);
	            i++;
	            j++;
	        }
	        else
	        {
	            j++;
	        }
	    }
	}
};