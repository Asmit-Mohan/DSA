class Solution
{
  public:
    string reverseWords (string s)
    {
        stack<char>st;
        string str="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='.')
            {
                st.push(s[i]);
            }
            else
            {
               while(!st.empty())
               {
                   str=str+st.top();
                   st.pop();
               }
               str=str+'.';
            }
        }
         while (!st.empty())
         {
           str=str+st.top();
           st.pop();
        }
        return str;
    }
};
