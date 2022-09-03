/* Time :- O(M*N) Space :- O(1) */

class Solution
{
public:
    int temp=0;
    int ans=INT_MIN;
    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        if(x < 0 || y < 0 || x >= grid.size() || y >=grid[0].size()  || grid[x][y] == 0)
        {
            return;
        }

        grid[x][y]=0;
        temp++;

        dfs(grid,x-1,y);
        dfs(grid,x,y+1);
        dfs(grid,x,y-1);
        dfs(grid,x+1,y);    
        ans=max(ans,temp);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(grid,i,j);
                    temp=0;
                }
            }
        }
        return ans==INT_MIN?0:ans;   
    }
};
