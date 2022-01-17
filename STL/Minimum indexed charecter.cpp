class Solution
{
  public:
    int minIndexChar(string str, string patt)
    {
        map<char,int>mp;
        map<char, int>::iterator it ;
        for(int i=0;i<str.length();i++)
        {
            it = mp.find(str[i]);
            if(it == mp.end())
            {
                 mp[str[i]]=i;    
            }
        }
        int idx=INT_MAX;
        for(int i=0;i<patt.size();i++)
        {
            it = mp.find(patt[i]);
            if(it != mp.end())
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
}
