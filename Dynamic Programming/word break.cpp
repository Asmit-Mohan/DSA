class Solution
{
public:
    int wordBreak(string A, vector<string> &B)
    {
        int n=A.length();
        int dp[n+1]={0};
        set<string>s(B.begin(),B.end());
        
        dp[0]=1;  /*Empty charecter case, will always present in dictionary B*/
        
        for(int i=1;i<=A.length();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]==1&&s.find(A.substr(j,i-j))!=s.end())
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
