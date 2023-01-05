/* Time :- O(Nlogn) Space :- O(N) */

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& arr)
    {
        vector<pair<int,int>>v;
        for(auto it : arr)
        {
            v.push_back({it[0],it[1]});
        }
        sort(v.begin(),v.end());
        int maxi=v[0].second;
        int count=1;
        
        for(int i=1;i<v.size();i++)
        {
            if(v[i].first>maxi)
            {
                count++;
                maxi=v[i].second;
            }
            maxi=min(maxi,v[i].second);
        }
        return count;
    }
};
