/* Time :- O(Row*Col) Space :- O(Row*Col) */

class Solution
{
public:
    int maxGold(int row, int col, vector<vector<int>>matrix)
    {
        if(row == 1)
        {
            int sum = 0;
            for(int j = 0; j < col; j++)
            {
                sum = sum + matrix[0][j];
            }
            return sum;
        }
        
        for(int j = 1; j < col; j++)
        {
            for(int i = 0; i < row; i++)
            {
                if(i == 0)
                {
                    matrix[i][j] += max(matrix[i][j - 1], matrix[i + 1][j - 1]);
                }
                else if(i == row - 1)
                {
                    matrix[i][j] += max(matrix[i][j - 1], matrix[i - 1][j - 1]);
                }
                else
                {
                    matrix[i][j] += max(matrix[i][j - 1], max(matrix[i - 1][j - 1], matrix[i + 1][j - 1]));
                }
            }
        }
        
        int mx = 0;
        for(int i = 0; i < row; i++)
        {
             mx = max(mx, matrix[i][col - 1]);
        }
        return mx;
    }
};
