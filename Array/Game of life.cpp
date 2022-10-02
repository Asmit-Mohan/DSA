class Solution
{
public:
    bool valid(int i,int j,int row,int col)
    {
        if(i<0 || j<0 || i>=row || j>=col)
        {
            return false;
        }
        return true;
    }
    
    void gameOfLife(vector<vector<int>>& board)
    {
        int row=board.size();
        int column=board[0].size();
        vector<pair<int,int>>arr={{1,0},{-1,0},{0,1},{0,-1},{-1,1}, {-1,-1},{1,-1},{1,1}};
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                int count=0;
                for(int k=0;k<8;k++)
                {
                    int p = i + arr[k].first;
                    int q = j + arr[k].second;
                    
                    if(valid(p,q,row,column))
                    {
                        if(board[p][q]==1 || board[p][q]==2)
                        {
                            count++;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                
                if(board[i][j]==1 && (count<2 || count>3))
                {
                   board[i][j]=2;
                }
                
                if(board[i][j]==0 && count==3)
                {
                    board[i][j]=3;
                }
            }
        }
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                board[i][j]=board[i][j]%2;
            }
        }
    }
};
