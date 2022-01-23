int longestSubstrDistinctChars (string S)
{
    unordered_map<char,int>mp;
    int i=0;
    int j=0;
    int ans=INT_MIN;
    
    while(j<S.length())
    {
        mp[S[j]]++;
        
        if(j-i+1==mp.size())
        {
            ans=max(ans,j-i+1);
        }
        
        else if(mp.size()<j-i+1)
        {
            while(mp.size()<j-i+1)
            {
                mp[S[i]]--;
                if(mp[S[i]]==0)
                {
                    mp.erase(S[i]);
                }
                i++;
            }
        }
         j++;
    }
    return ans;
}
