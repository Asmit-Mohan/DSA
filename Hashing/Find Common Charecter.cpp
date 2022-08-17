class Solution
{
public:
    vector<string> commonChars(vector<string>& words)
    {
        vector<string> ans;
        vector<int> v (26,0);
        
        for(int i=0;i<words.size();i++)
        {
            vector<int> temp(26,0);
            for(auto x: words[i])
            {
                temp[x-'a']++;
            }
            if(i==0)
            {
                for(int i=0;i<26;i++)
                {
                    v[i]=temp[i];
                }
            }
            
            else
            {
                for(int i=0;i<26;i++)
                {
                    v[i]=min(v[i],temp[i]);
                }
            }
        }
        
        for(int i=0;i<26;i++)
        {
            while(v[i]--)
            {
                string s;
                char c='a'+i;
                s.push_back(c);
                ans.push_back(s);
            }
        }
        return ans;
    }
};
