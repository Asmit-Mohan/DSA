class Solution
{
public:
  bool dfs(vector<vector<char>>& board, int i, int j, int count, string word)
  {
  if (count == word.length())
  {
      return true;
  }
  if (i <0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[count])
  {
      return false;
  }

  char temp = board[i][j];
  board[i][j] = '-1';      /* Visited Cell Cannot Be Visited Again */

  int down  =  dfs(board, i + 1, j, count + 1, word);
  int up    =  dfs(board, i - 1, j, count + 1, word);
  int right =  dfs(board, i, j + 1, count + 1, word);
  int left  =  dfs(board, i, j - 1, count + 1, word);   
  bool found =  down || up || right || left;  

  board[i][j] = temp;
  return found;
  }

  bool exist(vector<vector<char>>& board, string word)
  {
     for (int i = 0; i < board.size(); i++)
     {
        for (int j = 0; j < board[0].size(); j++)
          {
             if(board[i][j] == word[0]) /* We are starting dfs, where word first char is found*/
              {
                  if(dfs(board, i, j, 0, word))
                  {
                     return true;
                  }
              }
          }
      }
     return false;
  }
};
