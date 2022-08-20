class Solution
{
public:
    bool solve(vector<vector<char>>& board, string &word,int count,int i,int j)
    {
        if(count==word.size())
        {
            return true;
        }
        
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[count])
        {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j]='-1';
        
        bool left = solve(board,word,count+1,i,j-1);
        bool right = solve(board,word,count+1,i,j+1);
        bool up = solve(board,word,count+1,i-1,j);
        bool down = solve(board,word,count+1,i+1,j);
        
        board[i][j]=temp;
        return left || right || up || down; 
    }
    
    bool exist(vector<vector<char>>& board, string word)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(solve(board,word,0,i,j))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
