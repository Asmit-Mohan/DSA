class Solution
{
public:
    
int ans=INT_MIN;
int temp=0;
    
void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>&vis)
{
    
    if(x < 0 || y < 0 || x >= grid.size() || y >=grid[0].size()  || grid[x][y] == 0 || vis[x][y]==1)
    {
        return;
    }

    vis[x][y]=1;
    temp++;
    
    dfs(grid,x-1,y,vis);
    dfs(grid,x,y+1,vis);
    dfs(grid,x,y-1,vis);
    dfs(grid,x+1,y,vis);
    ans=max(ans,temp);
    
}
    
int maxAreaOfIsland(vector<vector<int>>& grid)
{ 
    int row = grid.size();
    int col = grid[0].size();
    int isLands = 0;
    
    vector<vector<bool>>vis(row,vector<bool>(col, 0));

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(grid[i][j] == 1&&vis[i][j]==0)
            {
                temp=0;
                dfs(grid,i,j,vis);
            }
        }
    }
    return ans==INT_MIN?0:ans;   
}
};
