/* Approach 1 Recursion Time :- O(2^N) and Space :- O(N) */

class Solution
{
public:
    int solve(vector<int>& nums, int i, int target)
    {
        if(target == 0 && i == nums.size())
        {
            return 1;
        }
        if(i >= nums.size())
        {
            return 0;
        }
        return solve(nums, i + 1, target - nums[i]) + solve(nums, i + 1, target + nums[i]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return solve(nums, 0, target);
    } 
};

/* Approach 2 Memorisation Time O(N*N):- Space :- O(N*N) + O(N) --> Same Time and Space as that of Count of Subset Sum Problem */

class Solution
{
public:
    int solve(vector<int>&arr, int sum, int n, vector<vector<int>>&dp)
    { 
               if(sum==0)
               {
                  return 1;
               }      
               if(n==0)
               {
                  return 0;
               }
               if(dp[n][sum]!=-1)
               {
                  return dp[n][sum];
               }
               if(arr[n-1]==0)
               {
                 dp[n][sum] = solve(arr,sum,n-1,dp);  
               }
               else if(arr[n-1]<=sum)
               {  
                 dp[n][sum] = solve(arr, sum-arr[n-1],n-1,dp) + solve(arr,sum,n-1,dp);
               }
               else
               {
                 dp[n][sum] = solve(arr,sum,n-1,dp);
               }
               return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int S)
    {
        if(nums.size()==1&&nums[0]==abs(S))
        {
            return 1;
        }
        
        if(nums.size()==1&&nums[0]!=S)
        {
            return 0;
        }
        
        int count = 0;
        int sum=0;
        int n = nums.size();
        
        for (int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            if(nums[i]==0)
            {
                count++;
            }
        }
        
        if(S>sum)
        {
            return 0;
        }
        
        if((S+sum)%2!=0)
        {
            return 0;
        }
        
        S = (S+sum)/2;
        
        vector<vector<int>>dp(n+1, vector<int>(S+1,-1));
        return pow(2,count)*solve(nums,S,n,dp);   
    }
};
/* Approach 3 Tabulation Time O(N*N):- Space :- O(N*N) --> Same Time and Space as that of Count of subset problem */

class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        if(nums.size()==1&&nums[0]==abs(S))
        {
            return 1;
        }
        
        if(nums.size()==1&&nums[0]!=S)
        {
            return 0;
        }
        
        int count = 0;
        int sum=0;
        int n = nums.size();
        
        for (int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            if(nums[i]==0)
            {
                count++;
            }
        }
        
        if(S>sum)
        {
            return 0;
        }
        
        if((S+sum)%2!=0)
        {
            return 0;
        }
        
        int s= (S+sum)/2;
        int t[n+1][s+1];
        
        for(int i=0;i<n+1;i++)
        {
            t[i][0]=1;
        }
        
        for(int i=1;i<s+1;i++)
        {
            t[0][i]=0;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<s+1;j++)
            {
                 if(nums[i-1]==0)
                 {
                    t[i][j] = t[i-1][j];
                 }
                 else if(j < nums[i-1])
                 {
                    t[i][j] = t[i-1][j];
                 }
                 else
                 {
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
                 }
            }
        }
        
        return pow(2,count)*t[n][s];
     }
};
