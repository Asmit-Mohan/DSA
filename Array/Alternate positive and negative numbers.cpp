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
}