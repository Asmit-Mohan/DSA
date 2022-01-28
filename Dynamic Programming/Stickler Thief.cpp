/*Approach 1*/

lass Solution
{
    public:
    int dp[10001];
    long long solve(int n,int arr[])
    {
        if(n<0)
        {
            return 0;
        }
        else if(dp[n]!=-1)
        {
            return dp[n];
        }
        else
        {
            int ans1=arr[n]+solve(n-2,arr);
            int ans2=solve(n-1,arr);
            return dp[n]=max(ans1,ans2);
        }
        
    }
    int FindMaxSum(int arr[], int n)
    {
         memset(dp,-1,sizeof(dp));
         return solve(n-1,arr);
    }
};
 
/*Approach 2*/

class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
        if(n==1)
        {
            return arr[0];
        }
        if(n==2)
        {
            return max(arr[0],arr[1]);
        }
        
        int dp[n+1];
        dp[0]=arr[0];
        dp[1]=arr[1];
        dp[2]=arr[0]+arr[2];
        
        for(int i=3;i<n;i++)
        {
            dp[i] = arr[i] + max(dp[i-2],dp[i-3]);
        }
        
        return max(dp[n-1],dp[n-2]);
    }
};
