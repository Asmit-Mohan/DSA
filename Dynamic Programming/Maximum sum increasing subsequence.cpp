class Solution
{
	public:
	int maxSumIS(int arr[], int n)  
	{  
        int dp[10001]={0};
        int res=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int ans=0;
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j])
                {
                    if(dp[j]>ans)
                    {
                        ans=dp[j];
                    }
                }
            }
              if(ans==0)
              {
                 dp[i]=arr[i];
              }
              else
              {
                  dp[i]=ans+arr[i];;
              }
             
              res=max(res,dp[i]);
        }
        return res;
	}  
};
