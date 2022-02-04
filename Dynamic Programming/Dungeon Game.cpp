/* Recursive+Memorisation */

class Solution
{
public:    
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&arr, int n, int m,int i,int j)
	{    
            if(i>=n||j>=m)
            {
                return  1000000;
            }   
            if(i==n-1&&j==m-1)
            {
                if(arr[i][j]>0)
                {
                    return dp[i][j]= 1;
                }
                return dp[i][j]=abs(arr[i][j])+1;
            }
            
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }
            
            int a=solve(arr,n,m,i+1,j);
            int b=solve(arr,n,m,i,j+1);
            
            if(arr[i][j]>=min(a,b))
            {
                return dp[i][j]=1;
            }
            return dp[i][j]=min(a,b)-arr[i][j];
	}
    
    int calculateMinimumHP(vector<vector<int>>& points)
    {   
         int n=points.size();
         int m=points[0].size();
         dp.clear();
         dp.resize(n,vector<int>(m,-1));
         int ans=solve(points,n,m,0,0);
        
          if(ans<=0)
          {
              ans=1;
          }
	      return ans;
    }
};

/* DP Solution*/

class Solution
{
private:    
int m, n;
public:
    bool solve(vector<vector<int>> dp, int health)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int prev = -1;
                if (i == 0 && j == 0)
                {
                    dp[i][j] = dp[i][j] + health;
                    continue;
                } 
                else if (i == 0)
                {
                    prev = dp[i][j-1];
                } 
                else if (j == 0)
                {
                    prev = dp[i-1][j];
                }
                else
                {
                    prev = max(dp[i-1][j], dp[i][j-1]);
                }
                if (prev <= 0)
                {
                    dp[i][j] = -1;
                }
                else
                {
                    dp[i][j] = dp[i][j] + prev;
                }
            }
        }
        return dp[m-1][n-1] > 0;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        m = dungeon.size();
        n = dungeon[0].size();
        int low = 1;
        int high = INT_MAX;
        
        while (low < high)
        {
            int mid = low + (high-low)/2;
            if (solve(dungeon, mid))
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        return high;
    }
};
