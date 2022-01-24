/*Approach 1 (Naive) Time :- O(|text|*|pat|) */

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
    
        vector <int> search(string pat, string txt)
        {
            vector<int>v;
            int n=pat.size();
            
            for(int i=0;i<=txt.size()-n;i++)
            {
                if(solve(i,i+n,txt,pat))
                {
                    v.push_back(i+1);
                }
            }
            if(v.size()==0)
            {
                v.push_back(-1);
            }
            return v;
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

    vector <int> search(string pat, string txt)
    {
        int m = pat.length();
        int n = txt.length();
        int lps[m];
        vector<int>ans;
        
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
                ans.push_back(i-j+1);
                j=lps[j-1];
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
        if(ans.size()==0)
        {
            ans.push_back(-1);
        }
        return ans;  
    }
};
