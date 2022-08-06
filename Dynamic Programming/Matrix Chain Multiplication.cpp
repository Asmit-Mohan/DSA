/* Time Complexity :- O(N*N*N) Space :- (N*N) + O(N) Recursive Stack */

class Solution
{
public:
    int dp[100][100];
    int solve(int arr[],int i,int j)
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(int n, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(arr,1,n-1);
    }
};

/* Time Complexity :- O(N*N*N) Space :- (N*N) */

class Solution
{
public:
    int dp[101][101];
    int matrixMultiplication(int N, int arr[])
    {
       memset(dp,0,sizeof(dp));
       for(int i=N-1;i>=1;i--)
       {
         for(int j=i+1;j<=N-1;j++)
           {
               int ans=INT_MAX; 
               for(int k=i;k<j;k++)
               {
                   dp[i][j]=dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]; 
                   ans=min(ans,dp[i][j]); 
               }
               dp[i][j]=ans; 
           }
       }
       return dp[1][N-1];
    }
};
