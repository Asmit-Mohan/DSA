class Solution
{
public:
	bool hasArrayTwoCandidates(int arr[], int n, int x)
	{
	    set<int>s;
	    for(int i=0;i<n;i++)
	    {
	        if(s.find(x-arr[i])==s.end())
	        {
	            s.insert(arr[i]);
	        }
	        else
	        {
	            return true;
	        }
	    }
	    return false;
	}
};
