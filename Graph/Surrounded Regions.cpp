class Solution
{
public:
    
void dfs(vector<vector<char>>& grid, int x, int y)
{
    
  if(x < 0 || y < 0 || x >= grid.size() || y >=grid[0].size() || grid[x][y]!='O')
  { 
       return;
  }
    
    grid[x][y]='#';
    
    dfs(grid,x-1,y);  
    dfs(grid,x,y+1);  
    dfs(grid,x,y-1); 
    dfs(grid,x+1,y);
}
    
    void solve(vector<vector<char>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i=0;i<row;i++)
        {
            if(grid[i][0]=='O')
            {
                dfs(grid,i,0);
            }
            if(grid[i][col-1]=='O')
            {
                dfs(grid,i,col-1);
            }
        }

        for(int i=0;i<col;i++)
        {
            if(grid[0][i]=='O')
            {
                dfs(grid,0,i);
            }
            if(grid[row-1][i]=='O')
            {
                dfs(grid,row-1,i);
            }
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='O')
                {
                    grid[i][j]='X';
                }
                if(grid[i][j]=='#')
                {
                    grid[i][j]='O';
                }
            }
        }
    }
};
