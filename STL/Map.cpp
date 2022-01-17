map<int,int> mapInsert(int arr[],int n)
{
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]=i;
    }
    return mp;
}
void mapDisplay(map<int,int>mp)
{
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        cout << itr->first<<" "<< itr->second << '\n';
    }
}
void mapErase(map<int,int>&mp,int x)
{
    if(mp.erase(x))
    {
       cout<<"erased "<<x;
    }
    else
    {
       cout<<"not found";
    }
    cout<<endl;
}
