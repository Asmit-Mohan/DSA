/*Approach 1 Naive Time :- O(|text|*|pat|)*/

class Solution
{
public:	
    bool solve(int l,int r,string str,string pat)
    {
        int flag=1;
        int i=0;
        while(l<r)
        {
            if(pat[i]!=str[l])
            {
                flag=0;
                break;
            }
            l++;
            i++;
        }
        return flag;
    }
	int search(string txt, string pat)
	{
            if(pat.size()>txt.size())
            {
                return 0;
            }
            
            
            int n=pat.size();
            for(int i=0;i<=txt.size()-n;i++)
            {
                if(solve(i,i+n,txt,pat))
                {
                    return 1;
                }
            }
            return 0;
  }
};

/*Approach 2 (Rabin Karp) Time :- O(|text|-|pat|+1) --> Average case O(|text|*|pat|) --> Worst case*/

class Solution
{
public:	
int search(string txt, string pat)
{
	    int n = txt.length(); 
	    int m = pat.length();
	    int h = 1;
	    int q=13;
	    int d=256;
	    
	    for(int i = 1; i <= m - 1; i++)
	    {
	        h = (h * d)%q;
	    }
	    int t = 0, p = 0; 
    	for(int i = 0; i < m; i++)
    	{
    	    t = (t * d + txt[i])%q;
    	    p = (p * d + pat[i])%q;
    	}
    	for(int i = 0; i <= n - m; i++)
	    {
    	    if(p == t)
    	    {
    	        bool IsPattern = true;
    	        for(int j = 0; j < m; j++)
    	        {
    	            if(txt[i + j] != pat[j]) 
    	            {
    	                IsPattern = false ;
    	                break;
    	            }
    	        }
    	        if(IsPattern == true)
    	        {
    	            return true;
    	        }
    	    }
    	    if(i < n - m)
    	    {
    	        t = ( (d*( t - txt[i]*h )) + txt[ i + m])%q;
    	        if(t < 0)
    	        {
    	            t = t + q;
    	        }
    	    }
	    }
	    return false;
   }
};
