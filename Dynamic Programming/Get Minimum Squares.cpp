/* Approach 1 Time Complexity is O(N*Sqrt(N)) Space Complexity :- O(N) */

class Solution
{
	public:
	int MinSquares(int n)
	{
		int iVar=n;
		int fVar=sqrt(n);
		int dp[n]={0};

		if(iVar==fVar)  /*Incase it is a perfect square*/
		{ 
		    return 1;
		}
		else
		{
		   dp[0]=0;
		   dp[1]=1;
		   for(int i=2;i<=n;i++)
		   {
		       int ans=INT_MAX;
		       for(int j=1;j<=sqrt(i);j++)
		       {
			   int remain=i-(j*j);
			   ans=min(ans,dp[remain]);
		       }
		       dp[i]=ans+1;
		   }
	        }
	        return dp[n];
	}
};

/* Approach 2 Time :- O(N*SQRT(N)) and Space :- O(N) + O(N) */

class Solution
{
	public:
	int solve(int n,vector<int>&dp)
	{
        if(n==0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        
        int ans=n;
        for(int i=1;i*i<=n;i++)
        {
           ans=min(ans,1+solve(n-i*i,dp));
        }  
        dp[n]=ans;
        return dp[n];
	}

	int MinSquares(int n)
	{
        vector<int> dp(n+1,-1);
        return solve(n,dp);
	}
};
