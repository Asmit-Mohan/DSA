/* Time :- O(Nlogk) Space :- O(K) */

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        priority_queue<pair<int,vector<int>>>pq;
        vector<vector<int>>ans;
        
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            int distance=((x*x)+(y*y));
            pq.push({distance,points[i]});
            while(pq.size()>k)
            {
                pq.pop();
            }
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
