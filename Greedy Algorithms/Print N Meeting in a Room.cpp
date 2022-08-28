/* Time :- O(Nlogn) Space :- O(N) */

class Solution
{
public:
    vector<int> maxMeetings(int N,vector<int> &start,vector<int> &end)
    {
        int i;
        vector<pair<int,int>>v;
        
        for (i = 0; i < N; i++)
        {
            v.push_back({end[i],i});
        }
       
        sort(v.begin(),v.end());
     
        int temp = v[0].first;
     
        vector<int> ans;
     
        ans.push_back(v[0].second + 1);
     
        for (i = 1; i < N; i++)
        {
            if (start[v[i].second] > temp)
            {
                ans.push_back(v[i].second + 1);
                temp = v[i].first;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
