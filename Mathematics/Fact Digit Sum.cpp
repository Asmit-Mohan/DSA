#define ll long long
ll fact[9]={1};

class Solution
{
	public:
	vector<int> FactDigit(int N)
	{
	    for(int i=1;i<10;i++)
	    {
            fact[i] = i * fact[i-1];
	    }
	   
	    vector<int>res;
	    
	    while(N>0)
	    {
	        for(int i=9;i>0;i--)
	        {
	            if(fact[i]<=N)
	            {
	                res.push_back(i);
	                N = N - fact[i];
	                break;   
	            }
	        }
	    }
	    reverse(res.begin(),res.end());
	    return res;
	}
};
