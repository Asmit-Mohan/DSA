#include <stack>

bool findRedundantBrackets(string &s)
{
    stack<char>st;
    int n = s.length();
    
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            bool ans = true;
            while (!st.empty()&&st.top() != '(')
            {
                if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                {
                    ans = false;
                }
                st.pop();
            }
            st.pop();
            if (ans == true)
            {
                return true;
            }
        }
    }
    return false;
}
