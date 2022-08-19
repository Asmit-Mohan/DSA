/* Time :- O[n*(2^n)] Space :- O[n*(2^n)] */

class Solution
{
public:
    void solve(string in,string op,vector<string>&ans)
    {
        if(in.length()==0)
        {
            ans.push_back(op);
            return;
        }
        if(isdigit(in[0]))
        {
            string op1=op;
            op1.push_back(in[0]);
            in.erase(in.begin()+0);
            solve(in,op1,ans);
        }
        else
        {
             string op1=op;
             string op2=op;
             op1.push_back(tolower(in[0]));
             op2.push_back(toupper(in[0]));
             in.erase(in.begin()+0);
             solve(in,op1,ans);
             solve(in,op2,ans);
        }
        return;
    }
    vector<string> letterCasePermutation(string s)
    {
        string op;
        vector<string>ans;
        solve(s,op,ans);
        return ans;
    }
};
