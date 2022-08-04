/* Approach 1 Time :- O(M*N) Space :- O(M*N) */ 

class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        int dp[201][201]={0};
        dp[0][0]=grid[0][0];
        
        for(int i=1;i<n;i++)
        {
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
        for(int i=1;i<m;i++)
        {
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};

/* Approach 2 Time :- O(M*N) Space :- O(M*N) + O(N) */

class Solution 
{
public:
	int solve(vector<vector<int>>&grid, int i, int j, vector<vector<int>>&dp)
    {
		if(i<0 || j<0)
        {
            return INT_MAX;    /* For Comparision Purpose */
        }
		if(i==0 && j==0)
        {
            return grid[i][j];
        }
		if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
		return dp[i][j] = grid[i][j] + min(solve(grid, i-1, j, dp), solve(grid, i, j-1, dp));   
	}

	int minPathSum(vector<vector<int>>& grid)
    {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>>dp(n, vector<int>(m, -1));
		return solve(grid, n-1, m-1, dp);
	}
};
