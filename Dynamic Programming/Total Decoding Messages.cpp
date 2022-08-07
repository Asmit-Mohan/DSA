/* Time :- O(N) Space :- O(N) + O(N) */

class Solution
{
	public:
	int dp[10001];
	long long mod=pow(10,9)+7;
	int solve(string &op,int pos)
	{
	    if(dp[pos]!=-1)
	    {
	        return dp[pos];
	    }
	    if(op.length()==pos)
	    {
		return 1;     
            }
	    if(op[pos]=='0')
	    {
	        return 0;
            }
		
	    int res=solve(op,pos+1);   /*For 1 charecter at a time*/
	    if((pos+1)<op.length())   /*For 2 charecter at a time*/
	    {
		 if(op[pos]=='1'||(op[pos]=='2'&&op[pos+1]<='6'))  /*starting from 1 or 2 then <=6 because total 26 alphabets are there*/
		 {
	            res=res+(solve(op,pos+2)%mod);
		 }
	    }
	    return dp[pos]=res%mod;
	}
	int CountWays(string str)
	{
	    int pos=0;
	    memset(dp,-1,sizeof(dp));
	    return solve(str,pos);
    	}
};

/* Time :- O(N) Space :- O(N) --> LC Accepted GFG Wrong Answer */

class Solution
{
public:
    int numDecodings(string s)
    {
        int n=s.length();
        if(s[0]=='0')
        {
            return 0;
        }
        
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(s[i-1]-'0'>0)
            {
                dp[i]=dp[i-1];
            }
            if(s[i-2]=='1' || (s[i-2]-'0'==2 && s[i-1]-'0'<=6))
            {
                dp[i]+=dp[i-2];
            }   
        }
        return dp[n];
    }
};
