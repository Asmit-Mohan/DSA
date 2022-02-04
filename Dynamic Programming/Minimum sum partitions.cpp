class Solution
{
  public:
	int minDifference(int arr[], int n) 
	{ 
	    int sum=0;
	    for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
        }
        int t[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j==0)
                {
                    t[i][j]=1;
                }
                else if(i==0)
                {
                    t[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1]<=j)
                {
                    t[i][j]=t[i - 1][j - arr[i-1]]||t[i-1][j];
                }
                else
                {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<=sum/2;i++)
        {
            int s1=i;
            int s2=sum-i;
            if(t[n][i]==1&&ans>abs(s1-s2))
            {
                ans=abs(s1-s2);
            }
        }
        return ans;
	  }
};
