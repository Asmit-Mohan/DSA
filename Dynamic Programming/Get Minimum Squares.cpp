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
