/* BFS Approach */

class Solution
{
public:    
    bool isValid(int i, int j, int row, int col, vector<vector<int>>& grid)
    {
        if(i>=0 && i<row && j>=0 && j<col && grid[i][j] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        
        int fresh = 0;
        int time = 0;
        queue<pair<int, int>>q;
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                
                else if(grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        
        if(fresh == 0)  /*No Fresh Oranges*/
        {
            return 0;
        }
        if(q.size()==0)  /*No Rotten Oranges*/
        {
            return -1;
        }
        
        while(!q.empty())
        {
            
            int size = q.size();
            int flag = 0;
            while(size--)
            {   
                pair<int, int>temp = q.front();
                q.pop();
                
                int first = temp.first;
                int second = temp.second;
                
                int x[4] = { 1, -1, 0, 0};
                int y[4] = { 0, 0 , 1 , -1};
                
                for(int i=0; i<4; i++)
                {
                    int xNew  = x[i] + first;
                    int yNew  = y[i] + second;
                    
                    if(isValid(xNew, yNew, row, col, grid))
                    {
                        flag=1;
                        grid[xNew][yNew] = 2;
                        q.push({xNew, yNew});
                    }
                }
            }
            
            if(flag==1)
            {
                time++;
            }
        }
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == 1)  /*At last when any fresh oranges left*/
                {
                    time = 0;
                    break;
                }
            }
        }
        return (time == 0) ? -1 : time ;
    }
};

/* DFS Approach */
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
