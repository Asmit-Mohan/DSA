/*Approach 1 (Recursion) (TLE) */

class Solution
{
  public:
    bool go(string A,string B,string C) 
    {
    	if(A.empty() and B.empty() and C.empty())
    	{
    		return true;
    	}
    	if(C.empty())
    	{
    		return false;
    	}
    	bool first=(!A.empty() and A[0]==C[0])  && go(A.substr(1),B,C.substr(1));
    	bool second=(!B.empty() and B[0]==C[0]) && go(A,B.substr(1),C.substr(1));
    	return first or second;
    }
    
    bool isInterleave(string A, string B, string C) 
    {
	   return go(A,B,C);
    }
};

/*Approach 2 (Memorisation) */

class Solution
{
public:
     bool solve(string a, string b, string c, int dp[500][500])
     {
        if(dp[a.length()][b.length()]!=-1)
        {
            return dp[a.length()][b.length()];
        }
        
        if(a.length()==0 and b.length()==0 and c.length()==0)
        {
            return true;
        }
        
        if(c.length()==0)
        {
            return false;
        }
        
        bool ans1 = a.length() and a[0]==c[0] and solve(a.substr(1),b,c.substr(1),dp);
        bool ans2 = b.length() and b[0]==c[0] and solve(a,b.substr(1),c.substr(1),dp);
        
        return dp[a.length()][b.length()] = ans1 or ans2; 
        
    }
    
    bool isInterleave(string A, string B, string C)
    {
        int dp[500][500];   
        memset(dp,-1,sizeof(dp));
        return solve(A,B,C,dp);
    }
};

/*Approach 3 (DP) */

class Solution
{
public:
       bool isInterleave(string s1, string s2, string s3)
       {
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
           
        if (len1 == 0)
        {
            return s2 == s3;
        }
        if (len2 == 0)
        {
            return s1 == s3;
        }
        
        int dp[101][101]={0};
           
        dp[len1][len2] = 1;
        
        for (int i = len1; i >= 0; --i)
        {
            for (int j = len2; j >= 0; --j)
            {
                if ((i < len1 && s1[i] == s3[i+j] && dp[i+1][j]) ||
                    (j < len2 && s2[j] == s3[i+j] && dp[i][j+1]))
                {
                    dp[i][j] = 1;
                }
            }
        }
        return dp[0][0];
    }
};
