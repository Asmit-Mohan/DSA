/* Time :- O(nlogn) Space :- O(1) */

set<int> setInsert(int arr[],int n)
{
    set<int>s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    return s;
}

/* Time :- O(n) Space :- O(1) */

void setDisplay(set<int>s)
{
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";   
    }
    cout<<endl;
}

/* Time :- O(n) Space :- O(1) */

void setErase(set<int>&s,int x)
{
    if(s.erase(x))
    {
      cout<<"erased "<<x;
    }
    else
    {
      cout<<"not found";
    }
    cout<<endl;
}
