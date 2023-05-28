/* Approach :- 1 Using Queue DS */

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

/* Approach :- 2 --> Using Array */

class Solution
{
public:
    void setZeroes(vector<vector<int>>& arr)
    {
        int row[200]={0};
        int col[200]={0};

        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[0].size();j++)
            {
                if(arr[i][j]==0)
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        for(int i=0;i<200;i++)
        {
            if(row[i]==1)
            {
                for(int j=0;j<arr[0].size();j++)
                {
                    arr[i][j]=0;
                }
            }
            if(col[i]==1)
            {
                for(int j=0;j<arr.size();j++)
                {
                    arr[j][i]=0;
                }
            }
        }  
    }
};

/* Approach :-3 Most Efficient */

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    { 
        int n=matrix.size();
        int m=matrix[0].size();
        int col0 = 1;
        
        /* step 1: Traverse the matrix and mark 1st row & col accordingly */
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    /* mark i-th row */
                    matrix[i][0] = 0;
                    
                    /* mark j-th row */
                    if (j != 0)
                    {
                        matrix[0][j] = 0;
                    }
                    else
                    {
                        col0 = 0;
                    }
                }
            }
        }
        
        /* Step 2: Mark with 0 from (1,1) to (n-1, m-1) */
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        
        /* step 3: Finally mark the 1st col & then 1st row */
        
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
