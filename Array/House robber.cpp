/* Time :- O(N) and Space :- O(N) + Recursive Stack */

/*Approach 1*/

class Solution
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

/* Time :- O(N) and Space :- O(N)  */
 
/*Approach 2*/

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return nums[0];
        }
        int dp[100]={0};
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++)
        {
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];    
    }
};
