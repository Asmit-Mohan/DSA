/* Approach 1 (Recursion) (TLE) Time :- O(2^(m+n)) Space :- O(m+n) */

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

/*Approach 2 (Memorisation) Time :- O(m*n) Space :- O(m*n) */

class Solution
{
public:
    
    int dp[250][250];
    bool solve(string s1,string s2,string s3)
    {
        if(s1.length()==0&&s2.length()==0&&s3.length()==0) 
        {
            return 1;
        }
        if(s3.length()==0)
        {
            return 0;
        }
        if(dp[s1.length()][s2.length()]!=-1)
        {
            return dp[s1.length()][s2.length()];
        }
        
        bool can1 = !s1.empty()&&s1[0]==s3[0]&&solve(s1.substr(1),s2,s3.substr(1));
        bool can2 = !s2.empty()&&s2[0]==s3[0]&&solve(s1,s2.substr(1),s3.substr(1));
        
        return dp[s1.length()][s2.length()] = can1 or can2;
    }
    
    bool isInterleave(string s1, string s2, string s3)
    {
         int a=s1.length();
         int b=s2.length();
         int c=s3.length();
        
         if(a==0&&b==0&&c==0)
         {
             return 1;
         }
         if((a+b)!=c)
         {
             return 0;
         }
        
         memset(dp,-1,sizeof(dp));
         return solve(s1,s2,s3);
    }
};

/* Approach 3 (DP) Time :- O(M*N) Space :- O(M*N) */

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
