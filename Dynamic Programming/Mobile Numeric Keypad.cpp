class Solution
{
	public:
	int phone[4][3]={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
	long long int dp[10][30];
	
	long long solve(int i,int j,int n)
	{
	    if(n==1)
	    {
	        return 1;
	    }
	    if(dp[phone[i][j]][n]!=-1)
	    {
	        return dp[phone[i][j]][n];
	    }
	    long long self=solve(i,j,n-1);
	    long long left,right,up,down;
	    left=right=up=down=0;
	    
	    if(j>0&&phone[i][j-1]!=-1)
	    {
	        left=solve(i,j-1,n-1);
	    }
	    
	    if(j<2&&phone[i][j+1]!=-1)
	    {
	        right=solve(i,j+1,n-1);
	    }
	    
	    if(i>0&&phone[i-1][j]!=-1)
	    {
	        up=solve(i-1,j,n-1);
	    }
	    
	    if(i<3&&phone[i+1][j]!=-1)
	    {
	        down=solve(i+1,j,n-1);
	    }
	    
	    return dp[phone[i][j]][n] = left+right+up+down+self;
	}
	
	long long getCount(int N)
	{
	    memset(dp,-1,sizeof(dp));
	    long long int ans=0;
	    for(int i=0;i<4;i++)
	    {
	        for(int j=0;j<3;j++)
	        {
	            if(phone[i][j]!=-1)
	            {
	                ans+=solve(i,j,N);
	            }
	        }
	    }
	    return ans;
	}
};
