class Solution
{
public:
    
    int maximum(unordered_map<int,int>mp)
    {
        int ans=-1;
        for(auto it : mp)
        {
            ans=max(ans,it.second);
        }
        return ans;
    }
    
    int longestOnes(vector<int>& s, int k)
    {
        if(s.size()==1&&s[0]==0&&k==1)
        {
            return 1;
        }
        
        int i=0;
        int j=0;
        int ans=INT_MIN;
        unordered_map<int,int>mp;
        
        while(j<s.size())
        {
            if(s[j]==1)
            {
                mp[s[j]]++;
            }
            
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
        return ans==INT_MIN?0:ans; 
    }
};
