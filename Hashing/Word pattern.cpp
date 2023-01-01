/* Time :- O(N) Space :- O(N) */

class Solution
{
public:
    unordered_map<char,string>mp1;
    unordered_map<string,char>mp2;

    bool solve(char c,string word)   /* This is taking O(1) time */
    {
        if(mp1.find(c)!=mp1.end()&&mp1[c]!=word)
        {
            return 0;
        }
        else if(mp2.find(word)!=mp2.end()&&mp2[word]!=c)
        {
            return 0;
        }
        else if(mp1.find(c)==mp1.end())
        {
            mp1[c]=word;
            mp2[word]=c;
        }
        return 1;
    }

    bool wordPattern(string pat, string s)
    {
        vector<string>dict;
        stringstream str(s);
        string word;
        while (str >> word)
        {
            dict.push_back(word);
        }

        if(pat.length()!=dict.size())
        {
            return 0;
        }
        for(int i=0;i<pat.length();i++)
        {
            if(!solve(pat[i],dict[i]))
            {
                return 0;
            }          
        }
        return 1;      
    }
};
