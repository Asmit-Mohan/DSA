class Solution
{
public:

int ans = 0;
bool isSafe(int row, int col, int n, vector<string>&board)
{
      int i = row;
      int j = col;
        
      while (i >= 0 && j >= 0)  /*Diagonal UP Leftwards*/
      {
         if (board[i][j] == 'Q')
         {
            return false;
         }
         i--;
         j--;
      }

      i = row;
      j = col;
      while (j >= 0)    /* Leftwards */
      {
         if (board[i][j] == 'Q')
         {
            return false;
         }
         j--;
      }
        
      i = row;
      j = col;
      while (i < n && j >= 0)  /*Diagonal Down Leftwards*/
      {
         if (board[i][j] == 'Q')
         {
            return false;
         }
         i++;
         j--;
      }
      return true;
}
void solve(int col,int n,vector<string>&temp)
{
     if(col==n)
     {
        ans++;
        return;
     }
        
     for(int row=0;row<n;row++)
     {
        if(isSafe(row,col,n,temp))
        {
            temp[row][col]='Q';
            solve(col+1,n,temp);
            temp[row][col]='.';
        }
    }
}
    
int totalNQueens(int n)
{
    vector<string>temp(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
    {
       temp[i]=s;
    }
    solve(0,n,temp);    
    return ans;
}
};
