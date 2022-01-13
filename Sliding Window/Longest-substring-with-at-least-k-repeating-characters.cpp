class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int ans = INT_MIN;
        unordered_map<char ,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        int count = mp.size();   /*count of unique charecters*/
        for(int itr = 1; itr <= count ; itr++)
        {
            int i = 0;
            int j = 0;
            unordered_map<char , int> window;
            int match = 0;
            
                while(j < s.size())
                {
                    window[s[j]]++;
                    if(window[s[j]] == k)
                    {
                        match++;
                    }
                    j++;
                    while(window.size() > itr)
                    {
                        if(window[s[i]] == k)
                        {
                            match--;
                        }
                        window[s[i]]--;
                        if(window[s[i]] == 0)
                        {
                            window.erase(s[i]);
                        }
                        i++;
                    }
                    
                    if(match == window.size())
                    {
                        ans = max(ans , j - i);
                    }
                } 
        }
        return (ans == INT_MIN) ? 0 : ans;
    }
};