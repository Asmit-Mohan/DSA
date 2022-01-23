/* Approach 1 (Not Efficient) Time :- O(|S|*|MAX_SIZE_WORD|) Space :- O(|S|) */

class Solution
{
  public:
    string reverseWords (string s)
    {
        stack<char>st;
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='.')
            {
                st.push(s[i]);
            }
            else
            {
                while(!st.empty())
                {
                    ans+=st.top();
                    st.pop();
                }
                ans+='.';
            }
        }
                while(!st.empty())
                {
                    ans+=st.top();
                    st.pop();
                }
                return ans;
    }
};

/* Approach 2 Efficient Approach Time :- O(|S|) Space :- O(|S|) */

class Solution
{
  public:
    string reverseWords (string str)
    {
        string ans="";
        string temp="";
        for(char it : str)
        {
            if(it=='.')
            {
                ans=ans+temp+".";
                temp="";
            }
            else
            {
                temp=it+temp;
            }
        }
        ans=ans+temp;
        return ans;
    }
};

