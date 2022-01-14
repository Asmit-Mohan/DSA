#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t; cin>>t;
   while(t--)
   {
       int n,k;
       cin>>n>>k;
       int arr[n];
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
       }
       priority_queue<int, vector<int>, greater<int> > pq;
       vector<int>v;
       vector<int>::iterator it;
       for(int i=0 ;i<n; i++)
       {
           pq.push(arr[i]);
           if(pq.size() > k)
           {
               v.push_back(pq.top());
               pq.pop();
           }
       }
       while(pq.size() > 0)
       {
       v.push_back(pq.top());
       pq.pop();
       }
       for(int i=0;i<v.size();i++)
       {
           cout<<v[i]<<" ";
       }
       cout<<"\n";
   }
   return 0;
}
