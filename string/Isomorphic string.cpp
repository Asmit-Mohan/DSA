/* Time :- O(N) Space :- O(26) ie. Constant */

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
       if(s.length()!=t.length())
       {
           return 0;
       }
       unordered_map<char,char>mp1,mp2;
       for(int i=0;i<s.length();i++)
       {
           if(mp1.find(s[i])!=mp1.end())
           {
               if(mp1[s[i]]!=t[i])
               {
                   return 0;
               }
           }
           else if(mp2.find(t[i])!=mp2.end())
           {
               if(mp2[t[i]]!=s[i])
               {
                   return 0;
               }
           }
           else
           {
               mp1[s[i]]=t[i];
               mp2[t[i]]=s[i];
           }
       }
       return 1;
    }
};
