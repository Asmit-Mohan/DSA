class Solution
{
    public:
    bool isAnagram(string a, string b)
    {
       if(a.length()!=b.length())
       {
           return 0;
       }
       else
       {
           unordered_map<char,int>mp;
           for(int i=0;i<a.length();i++)
           {
               mp[a[i]]++;
           }
            for(int i=0;i<b.length();i++)
            {
               mp[b[i]]--;
            }
            for(int i=0;i<a.length();i++)
            {
                if(mp[a[i]]>0)
                {
                    return 0;
                }
            }
            return 1;
       }
    }
};
