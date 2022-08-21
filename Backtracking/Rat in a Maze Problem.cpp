/* Time :- O[4^(m+n)] Space :- O(m*n) Because Solve function time is O(1) and it at each step it has 4 choices and overall it have m*n step then 4^(m+n) */

class Solution
{
    public:
    void solve(vector<vector<int>>&arr,int i,int j,string op,vector<string> &ans,int n)
    {
        if(i<0||j<0||i>=n||j>=n||arr[i][j]==0)
        {
            return;
        }
        if(i==n-1&&j==n-1)
        {
            ans.push_back(op);
            return;
        }
        arr[i][j]=0;
        
        solve(arr,i,j+1,op+'R',ans,n);
        solve(arr,i-1,j,op+'U',ans,n);
        solve(arr,i+1,j,op+'D',ans,n);
        solve(arr,i,j-1,op+'L',ans,n);
        
        arr[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &arr, int n)
    {
        string op="";
        vector<string>ans;
        if(arr[0][0]==0||arr[n-1][n-1]==0)
        {
            return ans;
        }
        solve(arr,0,0,op,ans,n);
        return ans;
    }
};
