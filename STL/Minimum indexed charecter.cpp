/* Time :- O(n) Space :- O(n) */

class Solution
{
  public:
    int minIndexChar(string str, string patt)
    {
        unordered_map<char,int>mp;  
        for(int i=0;i<str.length();i++)
        {
            if(mp.find(str[i]) == mp.end())
            {
                 mp[str[i]]=i;    
            }
        }
        
        int idx=INT_MAX;
        for(int i=0;i<patt.size();i++)
        {
            if(mp.find(patt[i]) != mp.end())
            {
                idx=min(idx,it->second);  
            }
        }
        
        if(idx==INT_MAX)
        {
            return -1;
        }
        else
        {
            return idx;
        }
    }
};
