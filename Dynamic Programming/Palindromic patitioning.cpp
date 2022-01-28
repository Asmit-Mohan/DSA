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
