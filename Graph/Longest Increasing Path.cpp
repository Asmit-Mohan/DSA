class Solution
{
public:        
int dfs(vector<vector<int>>& mat,vector<vector<int>>&dp,int i,int j,int row,int col,int preVal)
{         
         if(i>=row || j>=col || i<0 || j<0 || mat[i][j]<=preVal)
         {
             return -1;
         }
     
         if(dp[i][j]!=-1)
         {
             return dp[i][j];
         }
     
         int a = 1+dfs(mat,dp,i-1,j,row,col,mat[i][j]);
         int b = 1+dfs(mat,dp,i+1,j,row,col,mat[i][j]);   
         int c = 1+dfs(mat,dp,i,j-1,row,col,mat[i][j]);   
         int d = 1+dfs(mat,dp,i,j+1,row,col,mat[i][j]);  
          
         dp[i][j]=max({a,b,c,d});
         
         if(dp[i][j]==0)
         {
             dp[i][j]=1;
         }
         return dp[i][j];  
}    

    int longestIncreasingPath(vector<vector<int>>& mat)
    {    
         int m=mat.size();
         int n=mat[0].size();   
         
         vector<vector<int>>dp(m,vector<int>(n,-1));   
         int ans=1;
        
         for(int i=0;i<m;i++)
         {
             for(int j=0;j<n;j++)
             {
                 if(dp[i][j]==-1)
                 {
                    dp[i][j]=dfs(mat,dp,i,j,m,n,-1);
                 }
                 ans=max(ans,dp[i][j]);    
             }
         }

      return ans;           
    }
};
