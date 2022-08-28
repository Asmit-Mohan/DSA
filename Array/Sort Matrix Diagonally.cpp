/* Time :- O(M*N*log(max[m,n])) Space :- O(M*N) */

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& arr)
    {
        int row = arr.size();
        int col = arr[0].size();
        
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp;
        
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[0].size();j++)
            {
                int diff = i-j;
                mp[diff].push(arr[i][j]);
            }
        } 
        
        vector<vector<int>>ans(row,vector<int>(col,0));
     
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[0].size();j++)
            {
                int diff = i-j;
                ans[i][j] = mp[diff].top();
                mp[diff].pop();
            }
        }
        return ans;
    }
};
