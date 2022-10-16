#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;

void solve(vector<int> arr, int start, int end)
{
    vector<int>temp;
    if (end == arr.size())
    {
        return;
    }
    else if (start > end)
    {
        solve(arr, 0, end + 1);
    }
    else
    {
        for (int i = start; i < end; i++)
        {
            temp.push_back(arr[i]);
        }
        temp.push_back(arr[end]);
        ans.push_back(temp);
        solve(arr, start + 1, end);
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    solve(arr, 0, 0);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        if(i!=ans.size()-1)
        {
            cout<<","<<" ";
        }
    }
    return 0;
}
