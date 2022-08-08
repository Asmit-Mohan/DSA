/* Time :- O(26*N) Space :- O(26) */


class Solution
{
public:
    int maximum(unordered_map<char,int>mp)
    {
        int ans=-1;
        for(auto it : mp)
        {
            ans=max(ans,it.second);
        }
        return ans;
    }
    
    int characterReplacement(string s, int k)
    {
        int i=0;
        int j=0;
        int ans=INT_MIN;
        unordered_map<char,int>mp;
        
        while(j<s.length())
        {
            mp[s[j]]++;
            int window=j-i+1;
            int max=maximum(mp);
            
            if((window-max)>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            else
            {
                if(ans<window)
                {
                    ans=window;
                }
            }
            j++;
        }
        return ans;
    }
};
