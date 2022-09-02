/* Approach 1 (DFS) Time :- O(N*M) Space :- O(1) */

class Solution
{
public:
void dfs(vector<vector<char>>& grid, int x, int y)
{
    if(x < 0 || y < 0 || x >= grid.size() || y >=grid[0].size()  || grid[x][y] == '0')
    {
        return;
    }
    
    grid[x][y]='0';
    
    dfs(grid,x-1,y);
    dfs(grid,x,y+1);
    dfs(grid,x,y-1);
    dfs(grid,x+1,y);
    
    dfs(grid,x+1,y-1);
    dfs(grid,x-1,y-1);
    dfs(grid,x+1,y+1);
    dfs(grid,x-1,y+1);
}

int numIslands(vector<vector<char>>& grid)
{
    int row = grid.size();
    int col = grid[0].size();
    int isLands = 0;
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(grid[i][j] == '1')
            {
                grid[i][j]='0';
                isLands++;
                
                dfs(grid,i-1,j);
                dfs(grid,i,j+1);
                dfs(grid,i,j-1);
                dfs(grid,i+1,j);
            
                dfs(grid,i+1,j-1);
                dfs(grid,i-1,j-1);
                dfs(grid,i+1,j+1);
                dfs(grid,i-1,j+1);
            }
        }
    }
    return isLands;     
}
};

/* Approach 2 (BFS) Time :- O(N*M) */

class Solution
{
   public:
   bool isSafe(int r,int c,int n,int m,vector<vector<char>>& grid)
   {
       if(r>=0 && c>=0 && r<n && c<m && grid[r][c]=='1')
       {
           return 1;
       }
       else
       {
           return 0;
       }
   }
   
   int numIslands(vector<vector<char>>& grid)
   {
       queue<pair<int,int>> q;
       int n=grid.size();
       int m=grid[0].size();
       int island=0;
       
       int dx[9]={-1,-1,1,1,-1,0,1,0,-1};
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]=='1')
               {
                  grid[i][j]='0';
                  q.push({i,j});
                  island++;
                  
                  while(!q.empty())
                  {
                      int x=q.front().first;
                      int y=q.front().second;
                      q.pop();
                      
                      for(int k=0;k<8;k++)
                      {
                          int r=x+dx[k];
                          int c=y+dx[k+1];
                          if(isSafe(r,c,n,m,grid))
                          {
                              grid[r][c]='0';
                              q.push({r,c});
                          }
                      }
                  }
               }
           }
       }
       return island;
   }
};
