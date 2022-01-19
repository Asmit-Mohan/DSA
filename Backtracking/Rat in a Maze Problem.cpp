class Solution
{
    public:
    void solve(int x,int y,string op,int n,vector<vector<int>> &m,vector<string>&ans)
    {
        if(x==n-1&&y==n-1)
        {
            ans.push_back(op);
            return;
        }
        if(x>=0&&y>=0&&x<=n-1&&y<=n-1&&m[x][y]==1)
        {
            m[x][y]=0;
            solve(x,y-1,op+'L',n,m,ans);
            solve(x,y+1,op+'R',n,m,ans);
            solve(x-1,y,op+'U',n,m,ans);
            solve(x+1,y,op+'D',n,m,ans);
            m[x][y]=1;
        }
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
       vector<string>ans;
       if(m[0][0]==0||m[n-1][n-1]==0)
       {
           return ans;
       }
       string op;
       solve(0,0,op,n,m,ans);
       return ans;
    }
};
