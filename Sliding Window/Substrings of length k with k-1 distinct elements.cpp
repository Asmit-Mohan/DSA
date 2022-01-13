class Solution
{
  public:
    int countOfSubstrings(string s, int k)
    {
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int ans=0;
        
        while(j<s.length())
        {
            mp[s[j]]++;
            if(j-i+1==k)
            {
                if(mp.size()==k-1)
                {
                    ans++;                    
                }
                if(mp[s[i]]==1)
                {
                    mp.erase(s[i]);
                }
                else
                {
                    mp[s[i]]--;
                }
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};