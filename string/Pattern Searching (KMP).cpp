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

/*Approach 2 (KMP) Time:- O(|text|+|pat|)*/

class Solution
{
public:	
void LPSArray(string pat, int M, int *lps) 
{ 
	int len = 0;
	int i = 1;
	lps[0] = 0;
		
	while(i < M)
	{
	    if(pat[i] == pat[len])
	    {
	        len++;
	        lps[i] = len;
	        i++;
	        
	    }
	    else
	    {
	        if(len == 0)
	        {
	            lps[i] = 0;
	            i++;
	        }
	        else
	        {
	            len = lps[len - 1];
	        }
	    }
	}
} 

	int search(string txt, string pat)
	{
    	if(pat.length() == 0)
        {
            return false;
        }
        int m = pat.length();
        int n = txt.length();
        int lps[m];
        
        LPSArray(pat,m,lps);
        
        int i = 0;
        int j = 0;
        
        while(i < n)
        {
            if(txt[i] == pat[j])
            {
                i++; 
                j++;
            }
            if(j == m)
            {
                return true;
            }
            else if(i < n && txt[i] != pat[j])
            {
                if(j == 0)
                {
                    i++;
                }
                else
                {
                    j = lps[j - 1];
                }
            }
        }
        return false;
    }
};
