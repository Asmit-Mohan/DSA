class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int>ans;
        unordered_map<char,int>mp;
        
        int prev=-1;
        int max=0;
            
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]=i;
        }
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]]>max)
            {
                max=mp[s[i]];
            }
            if(max==i)
            {
                ans.push_back(max-prev);
                prev=max;
            }
        }
        return ans;
    }
};
