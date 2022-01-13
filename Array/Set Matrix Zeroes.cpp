/*Approach :- 1*/

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        queue<pair<int,int>> q;
        int row = matrix.size();
        int col = matrix[0].size();  
        
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                if(matrix[i][j]==0)
                {
                    q.push(make_pair(i,j));
                }
            }
        }
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int r=0; r<row; r++)
            {
                matrix[r][y]=0;
            }
            for(int c=0; c<col; c++)
            {
                matrix[x][c]=0;
            }
        }
    }
};

/*Approach :- 2 --> in constant approach (but takes time alot --> Not TLE*/

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int MODIFIED = -2150000000;  /*Take any number less than (-2^31)*/
        int R = matrix.size();
        int C = matrix[0].size();

        for (int r = 0; r < R; r++)
        {
          for (int c = 0; c < C; c++)
          {
            if (matrix[r][c] == 0)
            {
              for (int k = 0; k < C; k++)
              {
                    if (matrix[r][k] != 0) 
                    {
                        matrix[r][k] = MODIFIED;
                    }
              }
              for (int k = 0; k < R; k++)
              {
                    if (matrix[k][c] != 0)
                    {
                        matrix[k][c] = MODIFIED;
                    }
              }
            }
          }
        }

        for (int r = 0; r < R; r++)
        {
          for (int c = 0; c < C; c++)
          {
            if (matrix[r][c] == MODIFIED)
            {
               matrix[r][c] = 0;
            }
          }
        }
    }
};

/*Approach :-3 Most Efficient*/

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        
        int m = matrix.size();
        int n = matrix[0].size();    
        bool rowflag = false;
        bool colflag = false;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                    {
                        rowflag = true;
                    }
                    if (j == 0)
                    {
                        colflag = true;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    
                }
            }
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        if (colflag)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
        
        if (rowflag)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }
};