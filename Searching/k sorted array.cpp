class Solution
{
  public:
    string isKSortedArray(int temp[], int n, int k)
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({temp[i],i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            if(abs(v[i].second-i)>k)
            {
                return "No";
            }
        }
        return "Yes";
    }
};
