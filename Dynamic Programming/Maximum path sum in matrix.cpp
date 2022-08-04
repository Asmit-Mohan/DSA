/* Approach 1 Time :- O(N*N) Space :- O(N*N) */

class Solution
{
public:
    int maximumPath(int n, vector<vector<int>> a)
    {
        int dp[n+1][n+1];
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<n+1;j++)
        {
            dp[0][j]=0;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                dp[i][j]=a[i-1][j-1]+ max ({dp[i-1][j],dp[i-1][j+1],dp[i-1][j-1]});
            }
        }
        int res=INT_MIN;
        for(int i=0;i<n+1;i++)
        {
            res=max(res,dp[n][i]);
        }
        return res;
    }
};

/* Approach 2 Time :- O(N*N) Space :- O(N*N) + O(N) */

class Solution
{
public:
int dp[501][501];
int solve(vector<vector<int>>& matrix,int n,int x, int y)
{
   if(x>=n||y>=n||x<0||y<0)
   {
       return 0;
   }
   if(dp[x][y]!=-1)
   {
       return dp[x][y];
   }
   return dp[x][y]=matrix[x][y]+max({solve(matrix,n,x+1,y+1),solve(matrix,n,x+1,y-1),solve(matrix,n,x+1,y)});
}

   int maximumPath(int N, vector<vector<int>> Matrix)
   {
       memset(dp,-1,sizeof(dp));
       int ans=0;
       for(int i=0;i<Matrix[0].size();i++)
       {
           int temp=solve(Matrix,N,0,i);
           ans=max(ans,temp);
       }
       return ans;
   }
};
