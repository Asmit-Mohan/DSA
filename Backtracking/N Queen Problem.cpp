/* 
 
Time Complexity :-  Exponential in nature, since we are trying out all ways.To be precise it goes as O(N! * N) nearly.

Space Complexity: O(N^2)

*/

class Solution
{
public:
    bool isSafe(int row,int col,int n,vector<string>&board)
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
    
    void solve(int col,int n,vector<string>&temp,vector<vector<string>>&ans)
    {
        if(col==n)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,n,temp))
            {
                temp[row][col]='Q';
                solve(col+1,n,temp,ans);
                temp[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n)
    {
       vector<vector<string>>ans;
       vector<string>temp(n);
       string s(n,'.');
       for(int i=0;i<n;i++)
       {
           temp[i]=s;
       }
       solve(0,n,temp,ans);
       return ans; 
    }
};
