/* Time :- O(M*N) Space :- O(1) + Auxiliary Stack Space */

class Solution
{
public:
    void dfs(int i,int j,int row,int col,vector<vector<char>>& board)
    {
        if(i<0||j<0||i>=row||j>=col||board[i][j]!='O')
        {
            return;
        }
        
        board[i][j]='#';
        
        dfs(i+1,j,row,col,board);
        dfs(i,j+1,row,col,board);
        dfs(i,j-1,row,col,board);
        dfs(i-1,j,row,col,board);
    }
    
    void solve(vector<vector<char>>& board)
    {
        int row=board.size();
        int col=board[0].size();
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0||j==0||i==row-1||j==col-1)
                {
                    dfs(i,j,row,col,board);
                }
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }
            }
        }
    }
};
