/* Approach 1 Time :- O(N*N) Space :- O(N*N) + O(N) */

class Solution
{
public: 
    int dp[102][102];
    int solve(vector<vector<int>>& grid,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        if(i>=m || j>=n )
        {
            return 0;
        }
        if(grid[i][j]==1 )
        {
            return 0;
        }
        if(i==m-1 && j==n-1 )
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int temp = solve(grid,i+1,j) + solve(grid,i,j+1);
        return dp[i][j]=temp;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid)
    {
        memset(dp,-1,sizeof dp);
        return solve(grid,0,0);    
    }
};

/* Approach 2 Time :- O(N*N) Space :- O(N*N) */

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat)
    {
         int m=mat.size();
         int n=mat[0].size();
         int dp[101][101]={0};
         if(mat[0][0]==1||mat[m-1][n-1]==1)
         {
             return 0;
         }
         for(int i=0;i<m;i++)
         {
             for(int j=0;j<n;j++)
             {
                 if(mat[i][j]==1)
                 {
                     dp[i][j]=0;
                 }
                 else if(i==0&&j==0)
                 {
                     dp[i][j]=1;
                 }
                 else if(i==0)
                 {
                     dp[i][j]=dp[i][j-1];
                 }
                 else if(j==0)  
                 {
                      dp[i][j]=dp[i-1][j];
                 }
                 else
                 {
                     dp[i][j]=dp[i-1][j]+dp[i][j-1];
                 }
             }
         }
         return dp[m-1][n-1];
    }
};
