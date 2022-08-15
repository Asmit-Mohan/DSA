/* Time :- O(|str1|) Space :- O(26) */

class Solution
{
  public:
    bool areKAnagrams(string str1, string str2, int k)
    {
        int n1 = str1.length();
        int n2 = str2.length();
        
        if(n1 != n2)
        {
            return false;
        }
        
        unordered_map<char, int>mp;
        int count = 0;
        
        for(int i = 0; i < n1; i++)
        {
            mp[str1[i]]++;
        }
        
        for(int i = 0; i < n1; i++)
        {
            if(mp.find(str2[i]) == mp.end())
            {
                count++;
            }
            else
            {
                if(--mp[str2[i]] == 0)
                {
                    mp.erase(str2[i]);
                }
            }
        }
        if(count <= k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
