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
