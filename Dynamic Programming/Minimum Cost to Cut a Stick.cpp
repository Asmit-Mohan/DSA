/* Time Complexity :- O(N*N*N) Space Complexity :- O(N*N) */

class Solution
{
public:
    int solve(int i, int j, vector<int>& cuts , vector<vector<int>>& dp)
    {
        if(i>=j)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1) 
        {
            return dp[i][j];
        }
        
        int mini =INT_MAX;
        
        for(int k=i; k<j; k++)
        {
            int cost = solve(i,k,cuts, dp) + solve(k+1,j,cuts,dp) + (cuts[j]-cuts[i-1]);
            mini = min(cost,mini);
        }
        return dp[i][j]=mini;
    }
    
    int minCost(int n, vector<int>& cuts)
    {    
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size()+1, vector<int>(cuts.size()+1, -1));
        return solve(1,cuts.size()-1, cuts, dp);
    }
};
