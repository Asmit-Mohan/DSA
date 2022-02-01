class Solution
{
public:	
    int shortestDistance(vector<string> &s, string word1, string word2)
    {
        if(word1==word2)
        {
            return 0;
        }
       	int w1pos=-1;
       	int w2pos=-1;
       	int ans=INT_MAX;
       	
       	for(int i=0;i<s.size();i++)
       	{
       	    if(s[i]==word1)
       	    {
       	        if(w2pos==-1)
       	        {
       	            w1pos=i;
       	        }
       	       if(w2pos!=-1&&w1pos==-1)
       	        {
       	            w1pos=i;
       	            ans=min(ans,abs(w2pos-w1pos));
       	        }
       	        else
       	        {
       	            w1pos=i;
       	            if(ans>abs(w2pos-i))
       	            {
       	                ans=abs(w2pos-i);
       	            }
       	        }
       	    }
       	    else if(s[i]==word2)
       	    {
       	        if(w1pos==-1)
       	        {
       	            w2pos=i;
       	        }
       	        else if(w1pos!=-1&&w2pos==-1)
       	        {
       	            w2pos=i;
       	            ans=min(ans,abs(w1pos-w2pos));
       	        }
       	        else
       	        {
       	            w2pos=i;
       	            if(ans>abs(w1pos-i))
       	            {
       	                ans=abs(w1pos-i);
       	            }
       	        }
       	    }
       	}
       	return ans;
    }
};
