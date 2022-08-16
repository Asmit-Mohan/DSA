/* Time :- O(nlogn) Space :- O(1) */

map<int,int> mapInsert(int arr[],int n)
{
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]=i;
    }
    return mp;
}

/* Time :- O(n) Space :- O(1) */

void mapDisplay(map<int,int>mp)
{
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        cout << itr->first<<" "<< itr->second << '\n';
    }
}

/* Time :- O(logn) Space :- O(1) */

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
