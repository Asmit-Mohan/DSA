class Solution
{
    public:
    int findPlatform(int arr[], int dept[], int n)
    {
        vector<pair<int,int>>v;
        int ans=1;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i],dept[i]});
        }
        sort(v.begin(),v.end());
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({v[0].second,1});
        
        for(int i=1;i<n;i++)
        {
            if(v[i].first>pq.top().first)
            {
                int platform=pq.top().second;
                pq.pop();
                pq.push({v[i].second,platform});
            }
            else
            {
                ans++;
                pq.push({v[i].second,ans});
            }
        }
        return ans;
    }
};
