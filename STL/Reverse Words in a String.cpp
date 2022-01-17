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
