/* Time :- O(N) Space :- O(26) ie. Constant */

class Solution
{
    public:
    char nonrepeatingCharacter(string str)
    {
        unordered_map<char,int>mp;
        for(int i=0;i<str.length();i++)
        {
            mp[str[i]]++;
        }
        for(int i=0;i<str.length();i++)
        {
            if(mp[str[i]]==1)
            {
                return str[i];
            }
        }
        return '$';
    }
};
