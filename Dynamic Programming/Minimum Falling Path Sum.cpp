class Solution
{
public:
    long long  solve(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        if(i<0||i>=matrix.size()||j<0||j>=matrix[0].size())
        {
            return INT_MAX;
        }
        if(i==0)
        {
            return matrix[i][j];
        }
        if(dp[i][j]!=INT_MAX)
        {
            return dp[i][j];
        }

        int a=solve(i-1, j+1, matrix,dp);
        int b=solve(i-1, j,   matrix,dp);
        int c=solve(i-1, j-1, matrix,dp);
        return dp[i][j] = matrix[i][j] + min(min(a,b),c);
    }

    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int r=matrix.size();
        int c=matrix[0].size();
        long long  ans=INT_MAX;
        vector<vector<int>>dp(r, vector<int>(c, INT_MAX));

        for(int i=0;i<c;i++)
        {
            ans=min(ans,solve(r-1,i,matrix,dp));
        }
        return ans;
    }
};
