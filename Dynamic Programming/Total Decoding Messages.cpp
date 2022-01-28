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
