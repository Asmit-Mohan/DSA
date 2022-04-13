/* Approach 1 */

class Solution
{
public:
    string longestPalindrome(string s1)
    {
        string s2=s1;
        reverse(s2.begin(),s2.end());
        string ans;
        int n=s1.size();
        int res=0;
        int dp[n+1][n+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
               if(s1[i-1]==s2[j-1])
                {
                     dp[i][j]=1+dp[i-1][j-1];     
                }
                else
                {
                    dp[i][j]=0;
                }
                
                if(dp[i][j]>res)
                {
                    string temp=s1.substr(i-dp[i][j],dp[i][j]);
                    string rev=temp;
                    reverse(rev.begin(),rev.end());
                    if(temp==rev)
                    { 
                        ans=temp;
                        res=dp[i][j];
                    }
                }
            }
        }
        return ans;
    }
};

/* Approach 2 */

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int dp[1000][1000]={0};
        dp[0][0] = 1;
        string res = "";
        int maxL = INT_MIN;
        
        for(int i = 1; i < s.size(); i++)
        {
            dp[i][i] = 1;
            if(s[i] == s[i-1])
            {
                dp[i-1][i] = 1;
            }
        }
        
        for(int i = s.size()-1; i>=0; i--)
        {
            for(int j = i+1; j < s.size(); j++)
            {
                if(s[i] == s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = 1;
                }
            }
        }
        
        for(int i = 0; i< s.size(); i++)
        {
            for(int j = 0; j < s.size(); j++)
            {
                    if(j-i+1 > maxL && dp[i][j] )
                    {
                        maxL = j-i+1;
                        res = s.substr(i, j-i+1);
                    }
            }
        }
        return res;
    }
};
