/* Time :- O(N) Space :- O(N) */

class Solution
{
    public:
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int>mp;
        vector<string>res;
        string ans;
        int fre=-1;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        for(auto x : mp)
        {
            if(x.second>fre)
            {
                fre=x.second;
                ans=x.first;
            }
            else if(x.second==fre)
            {
                int comp = ans.compare(x.first);   /* Time Complexity :- O(min(n,m)) where n and m are sizes of ans and x.first respectively */
                if(comp>0)
                {
                    ans=x.first;
                }
            }
        }
        res.push_back(ans);
        res.push_back(to_string(fre));
        return res;
    }
};
