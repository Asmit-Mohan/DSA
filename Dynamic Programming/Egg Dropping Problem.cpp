/* Approach 1 Recursive + Memorisation TLE */

class Solution /* Time: O(n^2*k), Space: O(n*k)*/
{
public:
    int solve(int e, int f, vector<vector<int>>& dp)
	  {
        if(f == 0 || f == 1)
        {
          return f;
        }
        if(e == 1)
		    {
			    return f;
        }
        if(dp[e][f] != -1)
		    {
			    return dp[e][f];
        }
        int mn = INT_MAX;
        
        for(int i=1; i<=f; i++)
		    {
            int left = 0;
            if(dp[e-1][i-1] != -1)
            {
				        left = dp[e-1][i-1];
            }
			      else
			      {
                left = solve(e-1, i-1, dp);
                dp[e-1][i-1] = left;
            }
            
			      int right=0;
            if(dp[e][f-i] != -1)
            {
				      right = dp[e][f-i];
            }
			      else
			      {
                right = solve(e, f-i, dp);
                dp[e][f-i] = right;
            }
            
            int temp = 1 + max(left, right);
            mn = min(mn, temp); 
        }
        return dp[e][f] = mn;
    }
    
    int superEggDrop(int e, int f)
	  {
        vector<vector<int>> dp(f+1, vector<int>(e+1, -1));
        return solve(e, f, dp);
    }
};

/* Approach 2 Optimised Approach BS + DP */

class Solution
{
public:
    int solve(int e,int f,vector<vector<int>>& dp)
      {
        int ans = INT_MAX;
        if(f==0 || f==1)
        {
            return f;
        }
        if(e==1)
        {
            return f;
        }
        if(dp[e][f] != -1)
        {
            return dp[e][f];
        }
                int low = 1;
                int high = f;
                int temp = 0;
                while(low<=high)
                {
                        int mid = low + (high-low)/2;
                        int left =  solve(e-1,mid-1,dp);
                        int right = solve(e,f-mid,dp);
                        temp = 1 + max(left,right);
                        if(left<right)
                        {
                                low = mid +1;
                        }
                        else
                        {
                                high = mid - 1;
                        }
                        ans = min(ans,temp);
                }
        return dp[e][f] = ans;
      }
      int superEggDrop(int e, int f) 
      {
        vector<vector<int>>dp(e+1,vector<int>(f+1,-1));
        return solve(e,f,dp);
      }
};
