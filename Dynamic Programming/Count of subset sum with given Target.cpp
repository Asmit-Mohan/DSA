class Solution
{
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        int t[n+1][sum+1];
        long long int mod=pow(10,9)+7;
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(j==0)
                {
                    t[i][j]=1;
                }
                else if(i==0)
                {
                    t[i][j]=0;
                }
                else if(arr[i-1]<=j)
                {
                    t[i][j]=(t[i-1][j-arr[i-1]]%mod)+(t[i-1][j]%mod);
                }
                else
                {
                    t[i][j]=(t[i-1][j]%mod);
                }
            }
        }
        return (t[n][sum]%mod);
	  } 
};
