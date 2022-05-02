class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        string str=s+s;
        str=str.substr(1,str.length()-2);
        return str.find(s)==-1?0:1;
    }
};
