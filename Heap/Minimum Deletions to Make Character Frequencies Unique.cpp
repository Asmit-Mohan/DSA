/* Time :- O(Nlogn) Space :- O(N) */

class Solution
{
public:
    int minDeletions(string s)
    {
        unordered_map<char,int>mp;
        priority_queue<int>pq;
        int ans=0;
        
        for(auto x : s)
        {
            mp[x]++;
        }
        
        if(mp.size()==1)
        {
            return 0;
        }
        
        for(auto x : mp)
        {
            if(x.second>0)
            {
                pq.push(x.second);
            }
        }
        
        while(pq.size()>1)
        {
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            
            if(first==0&&second==0)
            {
                break;
            }
            if(first>second)
            {
                pq.push(second);
            }
            if(first==second)
            {
                ans++;
                pq.push(first);
                pq.push(second-1);
            }
        }
        return ans;
    }
};
