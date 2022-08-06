/* Memorization Approach Time Complexity is :- O(N*N*N) Space :- O(N*N) */

class Solution
{
public:
 
int dp[2001][2001];
bool palin(int i,int j,string &str)
{
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
    
    int solve(int i,int j,string &str)
    {
        if(i>=j)
        {
            return 0;
        }
        
        if(palin(i,j,str))
        {
          return 0;  
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int ans=INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            int right;
            if(palin(i,k,str)) /* Left Part Solved Here To Optimize */
            {
                if(dp[k+1][j]!=-1)
                {
                    right=dp[k+1][j];
                }
                else
                {
                    right=solve(k+1,j,str);
                }
            }
            int temp=1+right;
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    
    int minCut(string s)
    {
        if(s.length()==1)
        {
            return 0;
        }
        if(palin(0,s.length()-1,s))
        {
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,s.length()-1,s);
    }
};

/* Tabulation Approach Time Complexity is :- O(N*N*N) Space :- O(N) */

class Solution
{
public:
bool isPalin(int l,int r,string &str)
{
    while(l<r)
    {
        if(str[l]!=str[r])
        {
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}
    
    int minCut(string s)
    {
        int n=s.size();
        vector<int> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--)
        {
            int ans=INT_MAX;
            for(int j=i;j<n;j++)
            {
                if(isPalin(i,j,s))
                {
                    ans=min(ans,1+dp[j+1]);
                }
            }
            dp[i]=ans;
        }
        return dp[0]-1;
    }
};
