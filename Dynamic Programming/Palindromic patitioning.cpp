/* GFG Accepted Approach Leetcode TLE */

class Solution
{
public:
int solve(string str,int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(ispalin(str,i,j))
    {
        return 0;
    }
    if(str.size()==0||str.size()==1)
    {
        return 1;
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int left;
        int right;
        if(dp[i][k]!=-1)
        {
            left=dp[i][k];
        }
        else
        {
            left=solve(str,i,k);
        }
        
        if(dp[k+1][j]!=-1)
        {
            right=dp[k+1][j];
        }
        else
        {
            right=solve(str,k+1,j);
        }
        
        int temp=1+left+right;
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;
}
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return  solve(str,0,str.length()-1);
    }
};

/* Leetcode and GFG Accepted Approach */

class Solution
{
public:
int dp[2001][2001];
bool isPal(string &str, int i, int j)
{
    while(i < j)
    {
        if(str[i] != str[j])
        {
            return 0;
        }
        i++;
        j--;
    }    
    return 1;
}
    
    int solve(string &str, int i, int j)
    {
        int ans = INT_MAX;
        int right;
        
        if(i >= j)
        {
            return dp[i][j]=0;
        }
        
        if(isPal(str, i, j))
        {
            return dp[i][j]=0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        for(int k = i; k < j; k++)
        {  
            if(isPal(str,i,k))  /* Left part will be calculated here */
            {
                if(dp[k+1][j] != -1)
                {
                     right = dp[k+1][j];
                }
                else
                {
                    right = solve(str,k+1,j);
                }
                
                dp[k + 1][j] = right;
                int temp =  right + 1;
                ans = min(ans,temp);   
            }
        }
        return dp[i][j] = ans;
    }
    
    int minCut(string s) 
    {
        if(s.length()==1)
        {
            return 0;
        }
        
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.size()-1);
    }
};
