/* Time Complexity of both approaches is O(N*N*N) and Space O(N*N) [ + O(N) In case of recursion + Memorisation ] */

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
    vector<int> check(int index,string s,int flag)
    {
        int i=0;
        int j=0;
        
        if(flag%2==0&&index>0)
        { 
            i=index-1;
            j=index;
        }
        else
        {
            i=index;
            j=index;
        }
        while(i>=0&&j<s.length())
        {
            if(s[i]!=s[j])
            {
                break;
            }
            i--;
            j++;
        }
        return {i+1,j-1};
    }
    
    string longestPalindrome(string s)
    {
        int a=0;
        int b=0;
        int ans=-1;
        
        for(int i=0;i<s.length();i++)
        {
            vector<int> v1=check(i,s,1);  /* ODD */
            vector<int> v2=check(i,s,0);  /* EVEN */

            if(v1[1]-v1[0]>ans)
            {
                a=v1[0];
                b=v1[1];
                ans=v1[1]-v1[0];
            }
            if(v2[1]-v2[0]>ans)
            {
                a=v2[0];
                b=v2[1];
                ans=v2[1]-v2[0];
            }
        }
        
        string t;
        for(int i=a;i<=b;i++)
        {
            t+=s[i];
        }
        return t;
    }
};
