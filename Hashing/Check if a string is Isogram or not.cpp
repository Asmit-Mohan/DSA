/* Time :- O(N) Space :- O(26) */

class Solution
{
    public:
    bool isIsogram(string s)
    {
        int hash[26]={0};
        for(int i=0;i<s.length();i++)
        {
            hash[s[i]-'a']++;
            if(hash[s[i]-'a']>1)
            {
                return 0;
            }
        }
        return 1;
    }
};
