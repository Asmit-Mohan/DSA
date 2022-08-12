/* Time :- O(Nlogn) Space :- O(N) */

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) 
    {
        vector<pair<int,int>> v;
        vector<vector<int>>ans;
        
        for(int i=0;i<arr.size();i++)
        {
            v.push_back({arr[i][0],arr[i][1]});
        }
        sort(v.begin(),v.end());
        auto temp = v[0];
        
        for(int i=1;i<v.size();i++)
        {
            if(temp.second>=v[i].first)
            {
                temp.second=max(v[i].second,temp.second);
            }
            else
            {
                ans.push_back({temp.first, temp.second});
                temp=v[i];
            }
        }
        ans.push_back({temp.first, temp.second});
        return ans;
    }
};
