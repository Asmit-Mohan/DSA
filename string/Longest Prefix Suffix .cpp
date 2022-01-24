/*Using KMP LPS Table (also called Pi Table) */

class Solution
{
    public:		
	int lps(string s)
	{
	    int M=s.length();
	    int LPS[n]={0};
	    int i=1;
	    int len=0;
	    
	    while(i<M)
	    {
	        if(s[len] == s[i])
	        {
	            len++;
	            LPS[i] = len;
	            i++;
	        }
	        else
	        {
	            if(len==0)
	            {
	                LPS[i]=0;
	                i++;
	            }
	            else
	            {
	                len = LPS[len-1];
	            }
	        }
	    }
	    return LPS[M-1];
    }
};
