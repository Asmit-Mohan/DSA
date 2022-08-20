class Solution
{
    public:
    void solve(string &digits, int i, vector<string>&phone , string &op, vector<string>& ans)
    {
        if (op.size() == digits.size())
        {
            ans.push_back(op);
            return;
        }
        string word = phone[digits[i]-'0'];
        for (int j = 0; j < word.size(); j++)
        {
            op = op+word[j];
            solve(digits, i+1, phone, op, ans);
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
        vector<string>ph{"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, 0, ph, op, ans);
        return ans;
    }
};
