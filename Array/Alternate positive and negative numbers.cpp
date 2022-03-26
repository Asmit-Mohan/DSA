class Solution
{
public:
	void rearrange(int arr[], int n)
	{
	    queue<int> negetive;
	    queue<int> positive;
	    for(int i=0;i<n;i++)
	    {
	       if(arr[i]<0)
	       {
	            negetive.push(arr[i]);
	       }
	       else
	       {
	           positive.push(arr[i]);
	       }
	    }
	    int i=0;
	    while(!negetive.empty() || !positive.empty() && i<n)
            {
		    if(!positive.empty())
		    {
			arr[i++]=positive.front();
			positive.pop();
		    }

		    if(!negetive.empty())
		    {
			arr[i++]=negetive.front();
			negetive.pop();
		    }
            }
	}
};

/* When Order Does Not Matter Time :- O(N) Space :- O(1) */

class Solution
{
public:
	void rearrange(int arr[], int n)
	{
		int i = -1;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] < 0)
			{
				i++;
				swap(arr[i], arr[j]);
			}
		}

		int posIdx = i + 1;
		int negIdx = 0;

		while (posIdx < n && negIdx < pos && arr[negIdx] < 0)
		{
			swap(arr[neg], arr[pos]);
			pos++;
			neg = neg + 2;
		}
	}
};
