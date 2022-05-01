class Solution
{
    vector<string>ph{"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    public:
    void solve(string digits, int i, string &op, vector<string>& ans)
    {
        if (op.size() == digits.size())
        {
            ans.push_back(op);
            return;
        }
        string word = ph[digits[i]-'0'];
        for (int j = 0; j < word.size(); j++)
        {
            op = op+word[j];
            solve(digits, i+1, op, ans);
            op.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string>ans;
        if (digits.length() == 0)
        {
            return ans;    
        }
        string op="";
        solve(digits, 0, op, ans);
        return ans;
    }
};
