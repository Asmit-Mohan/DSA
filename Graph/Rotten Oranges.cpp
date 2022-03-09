class Solution
{
public:
    
    void dfs(vector<vector<int>>& grid,int i,int j,int time)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        if(i<0||i>=n||j<0||j>=m||grid[i][j]==0|| (1 < grid[i][j] && grid[i][j]<time))
        {
            return;
        }
        
        grid[i][j]=time;
        
        dfs(grid,i+1,j,grid[i][j]+1);
        dfs(grid,i-1,j,grid[i][j]+1);
        dfs(grid,i,j+1,grid[i][j]+1);
        dfs(grid,i,j-1,grid[i][j]+1);
    }
    
    int orangesRotting(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    dfs(grid,i,j,grid[i][j]);
                }
            }
        }
        int count=2;
         for(int i=0;i<n;i++)
         {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
                count=max(grid[i][j],count);
            }
        }
        return count-2;
    }
};
