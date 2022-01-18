int comp(pair<int,int>a, pair<int,int>b)
{
    return a.second<b.second;
}

int maxChainLen(struct val p[],int n)
{
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        v.push_back({p[i].first,p[i].second});
    }
    sort(v.begin(),v.end(),comp);
    int i=0;
    int l=1;
    int ans=1;
    int r=v.size()-1;
    while(l<=r)
    {
        if(v[l].first>v[i].second)
        {
            ans++;
            i=l;
            l++;
        }
        else
        {
            l++;
        }
    }
    return ans;
}
