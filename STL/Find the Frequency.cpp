int findFrequency(vector<int> v, int x)
{
    map<int,int>mp;
    for(int i=0;i<v.size();i++)
    {
        mp[v[i]]++;
    }
    map<int,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if(it->first==x)
        {
            return it->second;
        }
    }
    return 0;
}
