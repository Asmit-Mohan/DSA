/* Time :- O(Row*Col) Space :- O(Row*Col) */

class Solution
{
public:
    void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>&vis)
    {
        if(x < 0 || y < 0 || x >= grid.size() || y >=grid[0].size()  || grid[x][y] == '0' || vis[x][y]==1)
        {
            return;
        }
        vis[x][y]=1;

        /*For north west east south*/

        dfs(grid,x-1,y,vis);
        dfs(grid,x,y+1,vis);
        dfs(grid,x,y-1,vis);
        dfs(grid,x+1,y,vis);

        /*For all 4 diagonals*/

        dfs(grid,x+1,y-1,vis);
        dfs(grid,x-1,y-1,vis);
        dfs(grid,x+1,y+1,vis);
        dfs(grid,x-1,y+1,vis);
   }

   int numIslands(vector<vector<char>>& grid)
   {
        int row=grid.size();
        int col=grid[0].size();
        int count=0;
        
        vector<vector<bool>>vis(row,vector<bool>(col, 0));
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1'&&vis[i][j]==0)
                {
                    solve(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
