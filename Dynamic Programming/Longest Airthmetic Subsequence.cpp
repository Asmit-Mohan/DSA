/* Time :- O(M*N) Space :- O(M*N) */

class Solution
{
public:
    int longestArithSeqLength(vector<int>& nums)
    {
        int n=nums.size();
        if(n<3)
        {
            return 0;
        }
        
        int ans=INT_MIN;
        int dp[1001][1001]={0};
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int diff=nums[j]-nums[i]+500;   /* To make negative common difference postive as negative index in dp array was not possible*/
                if(dp[i][diff]!=0)
                {
                   dp[j][diff]=1+dp[i][diff]; 
                }
                else
                {
                    dp[j][diff]=2;
                }
                ans=max(ans,dp[j][diff]);
            }
        }
        return ans;
    }
};
