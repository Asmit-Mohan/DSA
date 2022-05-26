/* Approach 1 :- Recursion */

class Solution
{
public:
       int longestSubstring(string s, int k)
       {
        if(s.size() == 0 || k > s.size())
        {
            return 0;
        }
        if(k == 0)
        {
            return s.size();
        }
        unordered_map<char,int>mp;
        
        for(auto x : s)
        {
            mp[x]++;
        }
        
        int idx =0;
        while(idx <s.size() && mp[s[idx]] >= k)
        {
            idx++;
        }
           
        if(idx == s.size())
        {
            return s.size();
        }
           
        int left  =  longestSubstring(s.substr(0,idx),k);
        int right =  longestSubstring(s.substr(idx+1),k);    
        return max(left, right);
    }
};

/* Approach 2 :- Sliding Window */

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
        int count = mp.size();  
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
