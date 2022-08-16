/* Approach 1 Time :- O(N) Space :- O(N) */

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;     
        for(int i = 0 ; i < s.length() ; i++)
        {
            string temp;
            if(s[i] == ' ')
            {
                continue;
            }
            while(i < s.length() && s[i] != ' ')
            {
                temp += s[i];
                i++;
            }
            st.push(temp);
        }
        
        string res;
        while(!st.empty())
        {
            res += st.top() + " ";
            st.pop();
        }
        res.pop_back();
        return res;
    }
};

/* Approach 2 Time :- More than O(N) Space :- O(N) */

class Solution
{
public:
    string reverseWords(string str)
    {
        reverse(str.begin(),str.end());
        string res;
        stringstream ss(str);
        string word;
        while(ss>>word)
        {
            reverse(word.begin(),word.end());
            res=res+word+" ";
        }
        res.pop_back();
        return res;
    }
};
