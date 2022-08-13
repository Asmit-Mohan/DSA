/* Time :- O(Nlogn) Space :- O(1) */

#include<bits/stdc++.h>
using namespace std;
int solve(int a[],int i,int n,int temp)
{
      int l=i+1;
      int r=n-1;
      while(l<=r)
      {
            int mid=l+(r-l)/2;
            if(temp>a[mid])
            {
                l=mid+1;
            }
            else if(temp<a[mid])
            {
                r=mid-1;
            }
            else
            {
               return 1;
            }
      }
      return 0;
}
int main() 
{
      int n,k;
      int count=0;
      cin>>n>>k;

      int arr[n];

      for(int i=0;i<n;i++)
      {
        cin>>arr[i];
      }

      sort(arr,arr+n);
      for(int i=0;i<n;i++)
      {
          int res=k+arr[i];
          if(solve(arr,i,n,res))
          {
              count++;
          }
      }
      cout<<count;
      return 0;
}
