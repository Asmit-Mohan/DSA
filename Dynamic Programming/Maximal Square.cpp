/* Approach 1 Tabulation Method */

class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int row=matrix.size();
        int col=matrix[0].size();
        
        if(row==0)
        {
            return 0;
        }
        
        vector<vector<int>>dp(row, vector<int>(col, 0));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                dp[i][j]=matrix[i][j]-'0';
            }
        }
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(dp[i][j]==1)
                {
                    dp[i][j]+=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]); 
                }
            }
        }
        int maxOne=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                maxOne=max(maxOne,dp[i][j]);
            }
        }
        return maxOne*maxOne;
    }
};

/* Because if dp[i][j]==0 then it will not form a square of all one --> Codebix video */

/* Approach 2 Memorisation */

class Solution
{

    int res=0;
    public:    
    int solve(vector<vector<char>>& matrix, int i , int j, int row, int col , vector<vector<int>>&dp)
    {
        if(i<0 || j<0 || i>=row || j>=col || matrix[i][j]=='0')
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];  
        }
        
        int right  = solve(matrix,i,j+1,row,col,dp);   
        int diagonal = solve(matrix,i+1,j+1,row,col,dp);   
        int down = solve(matrix,i+1,j,row,col,dp);   
        
        return dp[i][j] =1 + min(min(right,down),diagonal);    
    }
    
    
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp( row, vector<int>(col,-1));    
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]=='1')
                {
                     res = max(solve(matrix,i,j,row,col,dp),res);
                }
            }
        }
        return res*res;
    }
};
