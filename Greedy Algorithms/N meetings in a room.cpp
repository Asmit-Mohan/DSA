class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int count=1;
        int last=v[0].first;
        for(int i=1;i<n;i++)
        {
            if(last<v[i].second)
            {
                count++;
                last=v[i].first;
            }
        }
        return count;
    }
};
