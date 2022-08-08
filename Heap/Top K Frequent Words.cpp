/* Time :- O(Nlogk) Space :- O(N) */

class comp
{
public:
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
        if (b.second < a.second)
        {
            return true;
        }
        if (b.second == a.second && b.first > a.first)
        {
            return true;
        }
        return false;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        priority_queue<pair<string, int>, vector<pair<string, int>>,comp>pq;
        unordered_map<string,int> mp;
        for (auto x : words)
        {
            mp[x]++;
        }
        
        for (auto x : mp)
        {
            pq.push(x);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        
        vector<string> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
