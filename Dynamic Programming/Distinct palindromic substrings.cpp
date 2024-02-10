class Solution
{
    public:
    int solve(string s,int n)
    {
        bool dp[n][n];
        unordered_set<string> set;
        int count=0;
        for(int g=0;g<n;g++)
        {   
            for(int i=0,j=g;j<n;j++,i++)
            {   
                if(g==0)
                {
                    dp[i][j]=true;
                }
                else if(g==1)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=true;
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
                else
                {
                    if(s[i]==s[j]&&dp[i+1][j-1]==true)
                    {
                        dp[i][j]=true;
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
                if(dp[i][j])
                {
                    set.insert(s.substr(i,j-i+1));
                }
            }
        }
        return set.size();
    }
    int palindromeSubStrs(string s)
    {
        return solve(s,s.length());
    }
};
