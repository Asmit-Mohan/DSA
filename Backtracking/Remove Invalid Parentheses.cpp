/* Time :- O(2^|S|) Space :- O(2^|S|) */

class Solution
{
public:
unordered_set<string>ans;
vector<string>res;
int getMinRemoval(string s)
{
    stack<char>m;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '(')
        {
            m.push(s[i]);
        }
        if(s[i] == ')')
        {
            if(m.size() == 0)
            {
                m.push(s[i]);
                continue;
            }
            if(m.top() == ')')
            {
                m.push(s[i]);
                continue;
            }
            if(m.top() == '(')
            {
                m.pop();
            }
        }
    }
    return m.size();
}
void solve (string s,int mnr)
{
    if(mnr == 0)
    {
        int mna = getMinRemoval(s);
        if(mna == 0)
        {
           res.push_back(s);
        }
        return ;
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=')' && s[i]!='(')
        {
            continue;
        }
        string left = s.substr(0,i);  
        string right = s.substr(i+1);  
        string t = left+ right ;
        if(ans.find(t)==ans.end())
        {
           ans.insert(t);
           solve(t,mnr-1);
        }
    }
}
    
vector<string> removeInvalidParentheses(string s)
{
    int mnr=getMinRemoval(s);
    solve(s,mnr);
    return res;
}
};

// mnr:- Minimum number of removal 
// mna:- min number of removal now availble when mnr becomes zero
