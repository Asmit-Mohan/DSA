/* Backtracking Naive Approach 136/138 Passed */

class Solution
{
    public:
    void solve(string str,int k,string &ans)
    {
        if (k == 0)
        {
            return;
        }
        
        int n = str.length();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (str[i] < str[j])
                {
                    swap(str[i], str[j]);
                    if (str.compare(ans) > 0)
                    {
                        ans = str;
                    }
                    solve(str, k - 1, ans);
                    swap(str[i], str[j]);
                }
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
        string ans=str;
        solve(str,k,ans);
        return ans;
    }
};

/* Efficient Approach */
class Solution
{
    public:
    void solve(string str, string &ans, int k, int pos)
    {
        if(k == 0)
        {
            return;
        }
        char temp = str[pos];
        for(int i=pos+1;i<str.length();i++)
        {
            if(str[i]>temp)
            {
                temp= str[i];
            }
        }
        
        if(temp != str[pos]) /* it means it have greater number rightwards ko swap required*/
        {
            k--;
        }
            
        for(int i=str.length()-1; i>=pos ;i--)
        {
            if(str[i] == temp)
            {
                swap(str[i],str[pos]);
                if(str.compare(ans) > 0)
                {
                    ans = str;
                }
                
                solve(str,ans,k,pos+1);
                swap(str[i],str[pos]);
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
       string ans = str;
       solve(str,ans,k,0);
       return ans;
    }
};
