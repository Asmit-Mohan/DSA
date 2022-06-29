/* Time O(nlogn) Space O(n) */

class Solution
{
public:
    
    int solve(int num)
    {
        int ans=0;
        while(num>0)
        {
            if(num%2==1)
            {
                ans++;
            }
            num=num/2;
        }
        return ans;
    }
    
    vector<int> countBits(int num)
    {
        vector<int>ans;
        for(int i=0;i<=num;i++)
        {
            ans.push_back(solve(i));    
        }
        return ans;
    }
};

/* Time :- O(n) Space :- O(n) */

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int>dp(num+1);
        dp[0]=0;
        
        for(int i=1;i<=num;i++)
        {
            dp[i]=dp[i/2]+i%2;    
        }
        return dp;
    }
};
