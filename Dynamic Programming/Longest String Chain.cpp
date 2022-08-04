/* Time :- O(N) Space :- O(N) */

bool comp(string &s1,string &s2)
{
    return s1.size()<s2.size();
}

class Solution
{
public:
   
    bool solve(string &s1,string &s2)
    {
        if(s1.size()!=s2.size()+1)
        {
            return false;
        }
        
        int i=0;
        int j=0;
        
        while(i<s1.size())
        {
            if(s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        
        if(i==s1.size()&&j==s2.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int longestStrChain(vector<string>& str)
    {
        int n=str.size();
        sort(str.begin(),str.end(),comp);
        vector<int>dp(n,1);
        int ans=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(solve(str[i],str[j]) && dp[i]<1+dp[j])
                {
                    dp[i]=1+dp[j];
                }
            }
            if(dp[i]>ans)
            {
                ans=dp[i];
            }
        }
        return ans;
    }
};
