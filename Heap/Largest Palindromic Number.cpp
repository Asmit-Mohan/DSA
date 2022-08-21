/* Time :- O(Nlogn) Space :- O(N) */ 

class Solution
{
public:
    string largestPalindromic(string num)
    {
        unordered_map<char,int>mp;
        priority_queue<pair<char,int>>pq;
        
        char mx='#';
        for(auto it:num)
        {
            mp[it]++;
        }
        
        for(auto it:mp)
        {
            if(it.second%2)
            {
                mx=max(mx,it.first);
            }
        }
        
        for(auto it:mp)
        {
            pq.push({it.first,it.second});
        }
        
        string ans="";
        while(!pq.empty())
        {
            pair<char,int>p=pq.top();
            pq.pop();
            if(p.second>=2)
            {
                for(int i=0;i<p.second/2;i++)
                {
                    ans+=p.first;
                }
            }
        }
        
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]=='0')
            {
                ans.erase(i,1);
                i--;
            }
            else
            {
                break;
            }
        }
        
        string str=ans;
        reverse(str.begin(),str.end());
        
        if(mx!='#')
        {
            ans+=mx;
        }
        
        ans+=str;
        
        if(ans=="")
        {
            return "0";
        }
        return ans;
    }
};
